#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

bool	isFile(std::string& fileName)
{
	struct stat s;

	if (stat(fileName.c_str(), &s) == 0)
	{
		if (s.st_mode & S_IFREG)
			return (true);
	}
	return (false);
}

bool	openFile(std::ifstream& ifs, std::string& fileName)
{
	if (isFile(fileName) == false)
	{
		std::cout << "File does not exist" << std::endl;
		return (false);
	}
	ifs.open(fileName);
	if (!ifs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (false);
	}
	return (true);

}

std::string	readFileContent(std::ifstream& ifs)
{
	std::string	buffer;
	std::string	line;

	std::getline(ifs, line);
	buffer += line;
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		buffer += "\n" + line;
	}
	return (buffer);
}


void	replaceAndWriteToFile(std::string& fileName, std::string& toFind, std::string& toReplace, std::string& buffer)
{
	std::ofstream	ofs;

	ofs.open(fileName + ".replace", std::ios::trunc);
	if (!ofs.is_open())
	{
		std::cout << "Error opening output file" << std::endl;
		return ;
	}

	int i = 0, index;
	while (i < (int)buffer.length())
	{
		if (buffer.find(toFind, i) == std::string::npos)
			break;
		else
		{
			index = buffer.find(toFind, i);
			ofs << buffer.substr(i, index - i) << toReplace;
			i = index + toFind.length();
		}
	}
	if (i < (int)buffer.length())
		ofs << buffer.substr(i, buffer.length() - i);

	ofs.close();
}


int main(int argc, char **argv)
{
	std::ifstream	ifs;

	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string toFind = argv[2];
	std::string toReplace = argv[3];

	if (toFind.empty())
	{
		std::cout << "Error: Empty string" << std::endl;
		return (1);
	}

	if (openFile(ifs, filename) == false)
		return (2);


	std::string buffer = readFileContent(ifs);

	ifs.close();

	replaceAndWriteToFile(filename, toFind, toReplace, buffer);

	return (0);

}

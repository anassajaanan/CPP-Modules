#include <iostream>
#include <string>


int main()
{
	std::string	stringVar = "HI THIS IS BRAIN";

	std::string	*stringPTR = &stringVar;
	std::string& stringREF = stringVar;

	// Print the memory addresses
	std::cout << &stringVar << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl << std::endl;

	// Print the values
	std::cout << stringVar << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout <<  stringREF << std::endl;

	return (0);
}
#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

BitcoinExchange::BitcoinExchange() { };

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	map = other.map;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		map.clear();
		map = rhs.map;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() { }

void	BitcoinExchange::loadDataBase()
{
	std::string	filename = "data.csv";

	std::ifstream	ifs;

	ifs.open(filename);
	if (!ifs.is_open())
		throw FailedToOpenException();
	std::string line;
	while(std::getline(ifs, line))
	{
		if (line.empty() || line == "date,exchange_rate")
			continue;
		std::istringstream	iss(line);
		std::string	dateStr, valueStr;
		std::cout << std::fixed << std::setprecision(2);
		if (std::getline(iss, dateStr, ',')
			&& std::getline(iss, valueStr, ','))
		{
			try
			{
				double value = std::stod(valueStr);
				map[dateStr] = value;
				
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			ifs.close();
			throw (InvalidLineException());
		}
	}
	ifs.close();
}

void	BitcoinExchange::displayDataBase() const
{
	std::cout << "Start Displaying the DataBase" << std::endl;
	std::map<std::string, double>::const_iterator it = map.begin();
	while (it != map.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}


const char	*BitcoinExchange::InvalidLineException::what() const throw()
{
	return ("Failed to load the DataBase because of an invalid Line");
}

const char	*BitcoinExchange::FailedToOpenException::what() const throw()
{
	return ("Failed to open file: data.csv");
}
#include "BitcoinExchange.hpp"
#include <cctype>
#include <climits>
#include <cstdio>
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
		throw FailedToOpenDataException();
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

int	validateInputDate(std::string &line, std::string &date)
{
	if (date.size() != 11)
	{
		std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
		return (0);
	}
	for (int i = 0; i < 4; i++)
	{
		if (!std::isdigit(date[i]))
		{
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
			return (0);
		}
	}
	for (int i = 5; i < 7; i++)
	{
		if (!std::isdigit(date[i]))
		{
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
			return (0);
		}
	}
	for (int i = 8; i < 10; i++)
	{
		if (!std::isdigit(date[i]))
		{
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
			return (0);
		}
	}
	if (date[4] != '-' || date[7] != '-' || date[10] != ' ')
	{
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
			return (0);
	}
	return (1);
}

int	validateInputValue(std::string &line, std::string &value)
{
	if (value.empty())
		return (0);
	if (value[0] != ' ')
	{
		std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
		return (0);
	}
	if (value[1] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (0);
	}
	for (int i = 1; i < (int)value.size(); i++)
	{
		if (value[i] != '.' && !std::isdigit(value[i]))
		{
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
			return (0);
		}
	}
	return (1);
}

bool isLeapYear(int year) {
    /*
		Leap year is divisible by 4 but not divisible by 100,
		except for years divisible by 400
	*/
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	isValidDate(std::string date)
{
	std::string yearStr, monthStr, dayStr;

	std::istringstream	iss(date);
	if (std::getline(iss, yearStr, '-')
		&& std::getline(iss, monthStr, '-')
		&& std::getline(iss, dayStr, '-'))
	{
		int	year = std::stoi(yearStr);
		int	month = std::stoi(monthStr);
		int	day = std::stoi(dayStr);
		if (year < 1 || month < 1 || month > 12 || day < 1)
			return false;

		switch (month) {
			case 2:
				if (isLeapYear(year)) {
					return day <= 29;
				} else {
					return day <= 28;
				}
			case 4:
			case 6:
			case 9:
			case 11:
				// April, June, September, November
				return day <= 30;
			default:
				// All other months
				return day <= 31;
		}
	}
	return (false);
}

void	BitcoinExchange::processInput(const char *filename)
{
	std::ifstream	ifs;

	ifs.open(filename);
	if (!ifs.is_open())
	{
		throw (FailedToOpenInputException());
	}
	std::string	line;
	while (std::getline(ifs, line))
	{
		if (line.empty() || line == "date | value")
		{
			std::cout << std::endl;
			continue;
		}
		std::istringstream	iss(line);
		std::string	dateStr, valueStr;
		if (std::getline(iss, dateStr, '|') && std::getline(iss, valueStr, '|'))
		{
			if (validateInputDate(line, dateStr) && validateInputValue(line, valueStr))
			{
				std::string	date = dateStr.substr(0, 10);
				if (!isValidDate(date))
				{
					std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
					continue;
				}
				if (date > "2022-03-29" || date < "2009-01-02")
				{
					std::cout << "Error: date out of range." << std::endl;
					continue;
				}
				std::string	value = valueStr.substr(1, valueStr.size() - 1);
				try
				{
					double valueDouble = std::stod(value);
					if (valueDouble > INT_MAX)
					{
						std::cout << "Error: too large number." << std::endl;
						continue;
					}
					std::map<std::string, double>::iterator	it = map.lower_bound(date);
					if (it == map.begin())
					{
						if (it->first == date)
							// std::cout << "Lower Bound Found of " << date << " is " << it->first << std::endl;
							std::cout << date << " => " << valueDouble << " = " << it->second * valueDouble << std::endl;
						else
							std::cout << "Lower Bound Not Found " << std::endl;
					}
					else
					{
						if (it->first != date)
							it--;
						std::cout << date << " => " << valueDouble << " = " << it->second * valueDouble << std::endl;
					}
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			
		}
		else {
			std::cout << "Error: bad input" << " => {" << line << "}" << std::endl;
		}
	}
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

const char	*BitcoinExchange::FailedToOpenDataException::what() const throw()
{
	return ("Failed to open file: data.csv");
}

const char	*BitcoinExchange::FailedToOpenInputException::what() const throw()
{
	return ("Failed to open input file");
}
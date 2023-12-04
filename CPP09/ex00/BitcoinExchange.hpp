



#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <exception>


class BitcoinExchange
{
private:
	std::map<std::string, double>	map;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();


	void	loadDataBase();
	void	processInput(const char *filename);
	void	displayDataBase() const;


	class InvalidLineException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FailedToOpenDataException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FailedToOpenInputException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};





#endif /* BITCOINEXCHANGE_HPP */
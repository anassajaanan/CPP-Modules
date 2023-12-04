



#pragma once
#include <exception>
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>


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
	void	displayDataBase() const;


	class InvalidLineException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class FailedToOpenException : public std::exception
	{
		public:
			const char	*what() const throw();
	};


};





#endif /* BITCOINEXCHANGE_HPP */
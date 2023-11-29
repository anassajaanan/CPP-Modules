

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();


public:
	static void	convertToChar(int intValue);
	static void	convertToInt(std::string input);
	static void	convertToFloat(std::string input);
	static void	convertToDouble(std::string input);

	static void	convert(std::string input);
};



#endif /* SCALARCONVERTER_HPP */
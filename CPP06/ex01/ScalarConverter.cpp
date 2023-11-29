#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>
#include <iomanip>

void	ScalarConverter::convertToChar(int intValue)
{
	std::cout << "char: ";
	if (std::isprint(intValue))
		std::cout << "'" << (char)intValue << "'" << std::endl;
	else
	 	std::cout << "Non displayable" << std::endl;
}


void	ScalarConverter::convertToInt(std::string input)
{
	int	intValue = std::stoi(input);
	ScalarConverter::convertToChar(intValue);
	std::cout << "int: " << intValue << std::endl;
}

void	ScalarConverter::convertToFloat(std::string input)
{
	float	floatValue = std::stof(input);
	if (std::isinf(floatValue))
	{
		if (floatValue < 0)
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}
	else if (std::isnan(floatValue))
		std::cout << "float: nanf" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << floatValue << "f" << std::endl;

	}
}

void	ScalarConverter::convertToDouble(std::string input)
{
	double	doubleValue = std::stod(input);
	if (std::isinf(doubleValue))
	{
		if (doubleValue < 0)
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
	else if (std::isnan(doubleValue))
		std::cout << "double: nan" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << doubleValue << std::endl;
	
	}

}

void	ScalarConverter::convert(std::string input)
{
	try
	{
		ScalarConverter::convertToInt(input);
	}
	catch(std::invalid_argument)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	catch(std::out_of_range)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}

	try
	{
		ScalarConverter::convertToFloat(input);
	}
	catch(std::invalid_argument)
	{
		std::cout << "float: impossible" << std::endl;
	}
	catch(std::out_of_range)
	{
		std::cout << "float: impossible" << std::endl;
	}

	try
	{
		ScalarConverter::convertToDouble(input);
	}
	catch(std::invalid_argument)
	{
		std::cout << "double: impossible" << std::endl;
	}
	catch(std::out_of_range)
	{
		std::cout << "double: impossible" << std::endl;
	}
}
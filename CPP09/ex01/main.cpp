#include "RPN.hpp"
#include <iostream>




int main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cout << "Usage: ./RPN \"[expression]\"" << std::endl;
		return (1);
	}
	if (rpn.isValidExpression(argv[1]) == false)
	{
		std::cerr << "Error" << std::endl;
		return (2);
	}

	try
	{
		std::cout << rpn.evaluateRPNExpression(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
#include "RPN.hpp"
#include <cctype>


const char *NotValidException::what() const throw()
{
	return ("Not Valid Expression");
}

const char *DevisionByZeroException::what() const throw()
{
	return ("Devision By Zero");
}

RPN::RPN() { }

RPN::RPN(const RPN &other)
{
	deq = other.deq;
}

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		deq = rhs.deq;
	return (*this);
}

RPN::~RPN() { }

bool	RPN::isValidExpression(std::string expression)
{
	for (int i = 0; i < (int)expression.size(); i += 2)
	{
		char c = expression[i];
		if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
			return (false);
	}
	for (int i = 1; i < (int)expression.size(); i += 2)
	{
		if (expression[i] != ' ')
			return (false);
	}
	char c = expression[expression.length() - 1];
	if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
		return (false);
	return (true);
}

int	RPN::evaluateRPNExpression(std::string expression)
{
	for (int i = 0; i < (int)expression.size(); i += 2)
	{
		// std::cout << expression[i] << std::endl;
		if (std::isdigit(expression[i]))
		{
			deq.push_back(expression[i] - '0');
		}
		else
		{
			if (deq.size() < 2)
				throw (NotValidException());
			int num2 = deq.back();
			deq.pop_back();
			int num1 = deq.back();
			deq.pop_back();
			if (expression[i] == '/' && num2 == 0)
				throw (DevisionByZeroException());
			if (expression[i] == '+')
				deq.push_back(num1 + num2);
			else if (expression[i] == '-')
				deq.push_back(num1 - num2);
			else if (expression[i] == '*')
				deq.push_back(num1 * num2);
			else if (expression[i] == '/')
				deq.push_back(num1 / num2);
		}
	}
	if (deq.size() != 1)
		throw (NotValidException());
	int res = deq.back();
	deq.pop_back();
	return (res);
}


#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <deque>

class NotValidException : public std::exception
{
public:
	virtual const char *what() const throw();
};

// devision by zero exception
class DevisionByZeroException : public std::exception
{
public:
	virtual const char *what() const throw();
};

class RPN
{
private:
	std::deque<int>	deq;

public:
	RPN();
	RPN(const RPN &other);
	RPN	&operator=(const RPN &rhs);
	~RPN();

	bool	isValidExpression(std::string expression);
	int	evaluateRPNExpression(std::string expression);

};


#endif /* RPN_HPP */



#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>


class NoSpaceException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class NoSpanException : public std::exception
{
public:
	virtual const char* what() const throw();
};

class Span
{
private:
	unsigned int		size;
	std::vector<int>	vec;

public:
	Span();
	Span(unsigned int _size);
	Span(const Span &other);
	Span	&operator=(const Span &rhs);
	~Span();

	void	addNumber(int num);

	int	shortestSpan() const;
	int	longestSpan() const;

	void	fillVector(int startNum, int endNum);
	void	printVector() const;

};

#endif /* SPAN_HPP */
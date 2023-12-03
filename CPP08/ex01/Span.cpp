#include "Span.hpp"
#include <climits>

const char* NoSpaceException::what() const throw()
{
	return ("No space left in the Span");
}

const char* NoSpanException::what() const throw()
{
	return ("No span to find");
}

Span::Span() : size(0) { }

Span::Span(unsigned int size) : size(size) { }

Span::Span(const Span &other) : size(other.size)
{
	for (unsigned int i = 0; i < other.size; i++)
	{
		vec.push_back(other.vec[i]);
	}
}

Span	&Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		size = rhs.size;
		vec.clear();
		for (unsigned int i = 0; i < rhs.size; i++)
		{
			vec.push_back(rhs.vec[i]);
		}
	}
	return (*this);
}

Span::~Span()
{
	vec.clear();
}

void	Span::addNumber(int num)
{
	if (vec.size() >= size)
	{
		throw (NoSpaceException());
	}
	else {
		vec.push_back(num);
	}
}

int	Span::shortestSpan() const
{
	if (vec.size() <= 1)
		throw (NoSpanException());
	std::vector<int>	vec = this->vec;

	std::sort(vec.begin(), vec.end());
	int	minSpan = INT_MAX;
	for (int i = 1; i < (int)vec.size(); i++)
	{
		if (vec[i] - vec[i - 1] < minSpan)
			minSpan = vec[i] - vec[i - 1];
	}
	return (minSpan);
}

int	Span::longestSpan() const
{
	if (vec.size() <= 1)
		throw (NoSpanException());
	std::vector<int>	vec = this->vec;

	std::sort(vec.begin(), vec.end());
	return (vec[vec.size() - 1] - vec[0]);
}

void	Span::fillVector(int start, int end)
{
	std::srand(std::time(NULL));
	for (unsigned int i = vec.size(); i < size; i++)
	{
		vec.push_back(std::rand() % (end - start + 1) + start);
	}
}

void	Span::printVector() const
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}
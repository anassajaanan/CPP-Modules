

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP


#include <iostream>
#include <algorithm>


class NotFoundException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return ("Not Found");
	}
};

template <typename  T>
typename	T::iterator	easyfind(T &container, int val)
{
	typename	T::iterator it;

	it = std::find(container.begin(), container.end(), val);
	if (it != container.end())
		return (it);
	else
	{
		std::cout << val << " ";
		throw (NotFoundException());
	}
}



#endif /* EASYFIND_HPP */
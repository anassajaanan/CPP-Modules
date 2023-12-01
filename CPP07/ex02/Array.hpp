


#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>


template <class T>
class Array
{
private:
	unsigned int	_size;
	T				*array;


public:
	Array();
	Array(unsigned int size);
	Array(const Array &other);
	Array	&operator=(const Array &other);
	~Array();

	unsigned int	size() const;

	T	&operator[](unsigned int index);

};


#endif /* ARRAY_HPP */
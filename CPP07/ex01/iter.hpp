


#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <class T>
void	printValue(T a)
{
	std::cout << a << " ";
}


template <class T>
void	iter(T *array, int length, void (*f)(T a))
{
	for (int i = 0; i < length; i++)
	{
		f(array[i]);
	}
	std::cout << std::endl;
}


#endif /* ITER_HPP */
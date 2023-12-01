#include "Array.hpp"
#include <stdexcept>

template <class T>
Array<T>::Array() : _size(0), array(NULL) { }

template <class T>
Array<T>::Array(unsigned int size) : _size(size), array(new T[size]()) { }

template <class T>
Array<T>::Array(const Array &other) : _size(other._size), array(new T[other._size]())
{
	for (unsigned int i = 0; i < _size; i++)
		array[i] = other.array[i];
}

template <class T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		_size = other._size;
		array = new T[other._size]();
		for (unsigned int i = 0; i < _size; i++)
			array[i] = other.array[i];
	}
	return (*this);
}

template <class T>
Array<T>::~Array()
{
	delete[] array;
}

template <class T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <class T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::out_of_range("Index out of range"));
	return (array[index]);
}

int main()
{
	Array<int> a(5);
	Array<int> b(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i + 5;

	Array<int> c(b);

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
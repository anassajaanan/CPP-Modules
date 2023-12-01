

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
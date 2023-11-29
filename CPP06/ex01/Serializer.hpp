

#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Queue.hpp"

class Serializer
{

public:
	static uintptr_t	serialize(Data* ptr);
	static Data			*deserialize(uintptr_t raw);

};






#endif // SERIALIZER_HPP

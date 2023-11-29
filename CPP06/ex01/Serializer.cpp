#include "Serializer.hpp"
#include "Queue.hpp"
#include <sys/_types/_uintptr_t.h>


uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
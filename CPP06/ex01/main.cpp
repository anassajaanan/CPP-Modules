#include "Queue.hpp"
#include "Serializer.hpp"


int main(void)
{
	Data	queue;

	queue.enqueue(new std::string("anas"));
	queue.enqueue(new std::string(" is"));
	queue.enqueue(new std::string(" at"));
	queue.enqueue(new std::string(" 42\n"));

	uintptr_t	serializedPtr = Serializer::serialize(&queue);


	Data	*deserializedPtr = Serializer::deserialize(serializedPtr);

	if (deserializedPtr != &queue)
	{
		std::cout << "Serialization and deserialization failed!" << std::endl;
		return (1);
	}

	while (!deserializedPtr->isEmpty())
	{
		std::string	*word = (std::string *)deserializedPtr->dequeue();
		std::cout << *word;
		delete word;
	}

}
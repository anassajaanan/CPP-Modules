#include "Queue.hpp"
#include "Serializer.hpp"


int main(void)
{
	Data	queue;

	queue.enqueue(new std::string("anas"));
	queue.enqueue(new std::string(" is"));
	queue.enqueue(new std::string(" at"));
	queue.enqueue(new std::string(" 42."));

	uintptr_t	address = Serializer::serialize(&queue);


	Data	*queue1 = Serializer::deserialize(address);

	while (!queue1->isEmpty())
	{
		std::string	*word = (std::string *)queue1->dequeue();
		std::cout << *word;
		delete word;
	}

	std::cout << std::endl;


}
#include "Queue.hpp"


Node::Node() : val(NULL), next(NULL) { }

Node::Node(void *val) : val(val), next(NULL) { }

Node::~Node() { }

Queue::Queue() : front(NULL), rear(NULL) { }

Queue::~Queue()
{
	Node	*tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

void	Queue::enqueue(void *val)
{
	Node	*newNode = new Node(val);
	if (front == NULL)
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

void	*Queue::dequeue()
{
	if (front == NULL)
		return (NULL);
	Node	*tmp = front;
	void	*val = tmp->val;
	front = front->next;
	delete tmp;
	return (val);
}

void	*Queue::queueFront()
{
	if (front == NULL)
		return (NULL);
	return (front->val);
}

int		Queue::isEmpty()
{
	if (front == NULL)
		return (1);
	return (0);
}



#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Node
{
public:
	void	*val;
	Node	*next;
	Node();
	Node(void *val);
	~Node();
};


class Data
{
private:
	Node	*front;
	Node	*rear;
public:
	Data();
	~Data();
	void	enqueue(void *val);
	void	*dequeue(void);
	void	*queueFront();
	int		isEmpty();

};


#endif // !QUEUE_HPP
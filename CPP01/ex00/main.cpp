#include "Zombie.hpp"



int main(void)
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stack Zombie");

	return (0);
}
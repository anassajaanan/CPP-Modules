#include "Zombie.hpp"


int main(void)
{
	int	numOfZombies = 5;
	std::string	zombieName = "42 Zombie";

	Zombie	*zombies = zombieHorde(numOfZombies, zombieName);


	for (int i = 0; i < numOfZombies; i++)
		zombies[i].announce();

	delete [] zombies;

	return (0);
}
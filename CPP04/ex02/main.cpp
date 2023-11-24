#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main()
{
	int	numAnimals = 10;
	const Animal	*ptrs[numAnimals];

	for (int i = 0; i < numAnimals / 2; i++)
		ptrs[i] = new Dog();
	for (int i = numAnimals / 2; i < numAnimals; i++)
		ptrs[i] = new Cat();

	for (int i = 0; i < numAnimals; i++)
		ptrs[i]->makeSound();

	for (int i = 0; i < numAnimals; i++)
		delete ptrs[numAnimals - 1 - i];
}
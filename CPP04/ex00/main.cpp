#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	// Create instances of Animal, Dog, and Cat
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	// Print the types of j and i
    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;

	// Call makeSound() for both Dog and Cat and Animal
    i->makeSound(); // Output: Meow! 😺
    j->makeSound(); // Output: Bark! 🐶
	

	// Call makeSound() for the base class
    meta->makeSound(); // Output: Generic animal sound 🐾

	delete i;
	delete j;
	delete meta;
}
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


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

	const WrongAnimal	*meta2 = new WrongAnimal();
	const WrongAnimal	*i2 = new WrongCat();

	meta2->makeSound(); // Output: Generic WrongAnimal sound 🐾
	i2->makeSound(); // Output: Generic WrongAnimal sound 🐾

	delete i2;
	delete meta2;

	delete i;
	delete j;
	delete meta;
}
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Default constructor of Dog is called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const std::string &type) : Animal(type) 
{
	std::cout << "Dog " << type << " is created" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog " << other.type << " is created by copy constructor" << std::endl;
	brain = new Brain();
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	*brain = *other.brain;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog " << type << " is destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! 🐶" << std::endl;
}
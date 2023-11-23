#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Default constructor of Dog is called" << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type) 
{
	std::cout << "Dog " << type << " is created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog " << other.type << " is created by copy constructor" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog " << type << " is destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Bark! 🐶" << std::endl;
}
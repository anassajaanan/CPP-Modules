#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Default constructor of WrongCat is called" << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "WrongCat " << type << " is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat " << other.type << " is created by copy constructor" << std::endl;
	*this = other;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << type << " is destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat: Meow! 😺" << std::endl;
}
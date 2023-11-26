


#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP


#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const std::string &type);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	~WrongCat();

	void	makeSound() const;
};





#endif /* WRONGCAT_HPP */
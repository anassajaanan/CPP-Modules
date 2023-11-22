

#pragma once
#ifndef FRAGTARP_HPP
# define FRAGTARP_HPP

#include "ClapTrap.hpp"



class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string &name, unsigned int hitPoint = 100, unsigned int energyPoint = 100, unsigned int attackDamage = 30);
	FragTrap(const FragTrap &fragTrap);
	FragTrap &operator=(const FragTrap &fragTrap);
	~FragTrap();

	void highFivesGuys(void);
};




#endif /* FRAGTRAP_HPP */
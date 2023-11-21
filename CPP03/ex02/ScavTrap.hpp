


#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &name, unsigned int hitPoint = 100, unsigned int energyPoint = 50, unsigned int attackDamage = 20);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();
};





#endif /* SCAVTRAP_HPP */
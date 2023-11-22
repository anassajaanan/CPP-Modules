


#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


#include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &name, unsigned int hitPoint = 100, unsigned int energyPoint = 50, unsigned int attackDamage = 20);
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap	&operator=(const ScavTrap &scavTrap);
	~ScavTrap();

	void	attack(const std::string &target);
	void	guardGate();

};





#endif /* SCAVTRAP_HPP */
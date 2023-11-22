

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hitPoint;
	unsigned int	energyPoint;
	unsigned int	attackDamage;


public:
	ClapTrap();
	ClapTrap(const std::string &name, unsigned int hitPoint = 100, unsigned int energyPoint = 50, unsigned int attackDamage = 20);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap	&operator=(const ClapTrap &clapTrap);
	~ClapTrap();


	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);


	void	displayStats() const;

};



#endif /* CLAPTRAP_HPP */
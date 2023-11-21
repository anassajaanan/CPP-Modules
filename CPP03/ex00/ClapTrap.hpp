

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string		name;
	unsigned int	hitPoint;
	unsigned int	energyPoint;
	unsigned int	attackDamage;


public:
	ClapTrap();
	ClapTrap(const std::string &name, unsigned int hitPoint = 10, unsigned int energyPoint = 10, unsigned int attackDamage = 0);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();


	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amout);

	void	displayStats() const;

};



#endif /* CLAPTRAP_HPP */
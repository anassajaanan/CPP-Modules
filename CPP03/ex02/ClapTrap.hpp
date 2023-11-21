

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
	ClapTrap(const std::string &name, unsigned int hitPoint = 100, unsigned int energyPoint = 50, unsigned int attackDamage = 20);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();


	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);


	// Mutators
	void		setName(std::string _name);
	void		setHitPoint(unsigned int _hitPoint);
	void		setEnergyPoint(unsigned int _energyPoint);
	void		setAttackDamage(unsigned int _attackDamage);

	// Accessors
	std::string		getName() const;
	unsigned int	getHitPoint() const;
	unsigned int	getEnergyPoint() const;
	unsigned int	getAttackDamage() const;


	void	displayStats() const;

};



#endif /* CLAPTRAP_HPP */
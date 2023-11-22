#include "ClapTrap.hpp"




ClapTrap::ClapTrap() : name("Default"), hitPoint(100), energyPoint(50), attackDamage(20)
{
	std::cout << "Default ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage)
	: name(name), hitPoint(hitPoint), energyPoint(energyPoint), attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << name << " is created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (energyPoint > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > 0)
	{
		std::cout << "ClapTrap " << name << " is damaged " << amount << " of hit point!" << std::endl;
		this->hitPoint -= amount;
	}
	else
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0)
	{
		std::cout << "ClapTrap " << name << " is repaired " << amount << " of hit point!" << std::endl;
		this->hitPoint += amount;
		this->energyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " is out of energy!" << std::endl;
	}
}

void	ClapTrap::displayStats() const
{
	std::cout << "ClapTrap " << name << " has " << hitPoint << " hit points, " << energyPoint << " energy points and " << attackDamage << " attack damage" << std::endl;
}

void	ClapTrap::setName(std::string _name)
{
	name = _name;
}

void	ClapTrap::setHitPoint(unsigned int _hitPoint)
{
	hitPoint = _hitPoint;
}

void	ClapTrap::setEnergyPoint(unsigned int _energyPoint)
{
	energyPoint = _energyPoint;
}

void	ClapTrap::setAttackDamage(unsigned int _attackDamage)
{
	attackDamage = _attackDamage;
}

std::string	ClapTrap::getName() const
{
	return (name);
}

unsigned int	ClapTrap::getHitPoint() const
{
	return (hitPoint);
}

unsigned int	ClapTrap::getEnergyPoint() const
{
	return (energyPoint);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (attackDamage);
}
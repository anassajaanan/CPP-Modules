#include "FragTrap.hpp"
#include "ClapTrap.hpp"



FragTrap::FragTrap()
{
	std::cout << "Default FragTrap is created" << std::endl;
}

FragTrap::FragTrap(const std::string &name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage)
	: ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "FragTrap " << this->name << " is created" << std::endl;
	this->hitPoint = hitPoint;
	this->attackDamage = attackDamage;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "FragTrap " << name << " is created" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &fragTrap)
{
	this->name = fragTrap.name;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is asking for high fives" << std::endl;
}



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
	// ClapTrap::setHitPoint(hitPoint);
	// ClapTrap::setAttackDamage(attackDamage);
	this->hitPoint = hitPoint;
	this->attackDamage = attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " is destroyed" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is asking for high fives" << std::endl;
}



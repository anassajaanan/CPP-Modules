#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage)
	: ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "ScavTrap " << this->name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->name = scavTrap.name;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " is destroyed" << std::endl;
}

// Override the attack function of ClapTrap
void	ScavTrap::attack(const std::string &target)
{
	if (energyPoint > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoint--;
	}
	else
	{
		std::cout << "ScavTrap " << name << " is out of energy!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}
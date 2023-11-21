#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name, unsigned int hitPoint, unsigned int energyPoint, unsigned int attackDamage)
	: ClapTrap(name, hitPoint, energyPoint, attackDamage)
{
	std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->getName() << " is created from a copy" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << this->getName() << " is assigned from another ScavTrap" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

// Override the attack function of ClapTrap
void	ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoint() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " is out of energy!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}
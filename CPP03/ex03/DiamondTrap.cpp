#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"), FragTrap(_name) , ScavTrap(_name), name(_name)
{
	std::cout << "DiamondTrap " << _name << " is created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is destroyed" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::displayStats() const
{
	std::cout	<< "DiamondTrap name is " << name << ", hit points is " << hitPoint << ", energy points is "
				<< energyPoint << ", attack damage is " << attackDamage << std::endl;
}
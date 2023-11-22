


#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap :  public FragTrap , public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);
	~DiamondTrap();


	void whoAmI();
	void attack(std::string const & target);

	void	displayStats() const;



};


#endif /* DIAMONDTRAP_HPP */
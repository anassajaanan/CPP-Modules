#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string _name)
	:name(_name), weapon(NULL) {}


void	HumanB::setWeapon(Weapon& _weapon)
{
	weapon = &_weapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << (*weapon).getType() << std::endl;
}


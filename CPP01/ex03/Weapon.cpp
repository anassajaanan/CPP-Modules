#include "Weapon.hpp"


Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string _type) : type(_type) {}

void	Weapon::setType(std::string _type)
{
	type = _type;
}

const std::string&	Weapon::getType() const
{
	return (type);
}
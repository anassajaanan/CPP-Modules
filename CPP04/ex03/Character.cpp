#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const std::string &name) : name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	name = other.name;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
	}
}

Character	&Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete  inventory[i];
		}
	}
}

const std::string	&Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}
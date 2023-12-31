

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Queue.hpp"

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*inventory[4];
	Queue		queue;

public:
	Character();
	Character(const std::string &name);
	Character(const Character &other);
	Character	&operator=(const Character &other);
	~Character();

	const std::string	&getName() const;

	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);

};


#endif /* CHARACTER_HPP */
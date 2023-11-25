

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{

public:
	Cure();
	Cure(const std::string &type);
	Cure(const Cure &other);
	Cure	&operator=(const Cure &other);
	~Cure();

	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif /* CURE_HPP */
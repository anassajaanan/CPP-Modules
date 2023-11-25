

#pragma once
#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria
{

public:
	Ice();
	Ice(const std::string &type);
	Ice(const Ice &other);
	Ice	&operator=(const Ice &other);
	~Ice();

	AMateria	*clone() const;
	void		use(ICharacter &target);


};

#endif /* ICE_HPP */
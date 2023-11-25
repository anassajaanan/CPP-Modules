#include "AMateria.hpp"

AMateria::AMateria() { }

AMateria::AMateria(const std::string &type) : type(type) { }

AMateria::AMateria(const AMateria &other)
{
	type = other.type;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

AMateria::~AMateria() { }

const std::string	&AMateria::getType() const
{
	return (type);
}


void	AMateria::use(ICharacter &target)
{
	(void)target;
}
#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"


Ice::Ice()
{
	type = "ice";
}

Ice::Ice(const std::string &type) : AMateria(type) { }

Ice::Ice(const Ice &other) : AMateria(other) { }

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Ice::~Ice() { }

AMateria	*Ice::clone() const
{
	return (new Ice(type));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

 

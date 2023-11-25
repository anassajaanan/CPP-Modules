


#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP


#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*learnedMaterias[4];
	int			numLearnedMaterias;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);
	~MateriaSource();

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(const std::string &type);


};

#endif /* MATERIASOURCE_HPP */
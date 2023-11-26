#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Queue.hpp"


int main()
{
	// IMateriaSource* src = new MateriaSource();

	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");

	// AMateria* tmp;
	
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter* bob = new Character("bob");


	// me->use(0, *bob);
	// me->use(1, *bob);


	// delete bob;
	// delete me;
	// delete src;
	// return 0;

	Queue	queue;

	for (int i = 0; i < 10; i++)
	{
		queue.enqueue(new Ice());
	}

	for (int i = 0; i < 10; i++)
	{
		AMateria *val = (AMateria *)queue.dequeue();
		std::cout << "Type is : " << val->getType() << " " << std::endl;
		delete  val;
	}


}
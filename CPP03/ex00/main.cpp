#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clapTrap("Anas", 20, 15, 5);

    clapTrap.attack("Enemy");

    clapTrap.takeDamage(10);

    clapTrap.beRepaired(5);


	clapTrap.displayStats();

    return 0;
}
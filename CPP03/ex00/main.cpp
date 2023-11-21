#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    // Create a default ClapTrap
    ClapTrap defaultClapTrap;

    // Create a custom ClapTrap
    ClapTrap customClapTrap("Custom", 20, 15, 5);

    defaultClapTrap.attack("Target1");
    customClapTrap.attack("Target2");

    defaultClapTrap.takeDamage(3);
    customClapTrap.takeDamage(7);

    defaultClapTrap.beRepaired(2);
    customClapTrap.beRepaired(4);


	customClapTrap.displayStats();

    return 0;
}
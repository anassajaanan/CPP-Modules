#include "ScavTrap.hpp"



int main()
{
    ScavTrap scavTrap("Anas");

    scavTrap.displayStats();

    scavTrap.attack("Enemy2");

    scavTrap.takeDamage(10);

    scavTrap.beRepaired(8);

    scavTrap.displayStats();

    scavTrap.guardGate();


    return 0;
}
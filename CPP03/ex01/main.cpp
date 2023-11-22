#include "ScavTrap.hpp"



int main()
{
    ClapTrap clapTrap("Bob");
    ScavTrap scavTrap("Alice");

    clapTrap.displayStats();
    scavTrap.displayStats();


    clapTrap.attack("Enemy1");
    scavTrap.attack("Enemy2");

    clapTrap.takeDamage(15);
    scavTrap.takeDamage(10);

    clapTrap.beRepaired(5);
    scavTrap.beRepaired(8);

    clapTrap.displayStats();
    scavTrap.displayStats();

    scavTrap.guardGate();

    return 0;
}
#include "ScavTrap.hpp"



int main()
{
    // Create instances of ClapTrap and ScavTrap
    ClapTrap clapTrap("Bob");
    ScavTrap scavTrap("Alice");

    // Display initial stats
    clapTrap.displayStats();
    scavTrap.displayStats();

    // Perform some actions
    clapTrap.attack("Enemy1");
    scavTrap.attack("Enemy2");

    clapTrap.takeDamage(15);
    scavTrap.takeDamage(10);

    clapTrap.beRepaired(5);
    scavTrap.beRepaired(8);

    // Display stats after actions
    clapTrap.displayStats();
    scavTrap.displayStats();

    // Test ScavTrap's unique function
    scavTrap.guardGate();

    return 0;
}
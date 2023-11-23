#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    FragTrap fragTrap("Fraggy");

    fragTrap.attack("Enemy1");
    fragTrap.takeDamage(20);
    fragTrap.beRepaired(10);

    fragTrap.displayStats();

    fragTrap.highFivesGuys();

    return 0;
}
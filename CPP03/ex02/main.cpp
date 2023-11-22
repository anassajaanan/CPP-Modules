#include "FragTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    FragTrap fragTrap("Fraggy");

    fragTrap.attack("Enemy1");
    fragTrap.takeDamage(20);
    fragTrap.beRepaired(10);

    // Display stats after actions
    fragTrap.displayStats();

    // Test unique function for FragTrap
    fragTrap.highFivesGuys();

    return 0;
}
#include "DiamondTrap.hpp"



int main() {
    DiamondTrap diamondTrap("Anas");

    diamondTrap.whoAmI();
    diamondTrap.attack("Enemy1");
    diamondTrap.guardGate();
    diamondTrap.highFivesGuys();
    diamondTrap.displayStats();

    return 0;
}
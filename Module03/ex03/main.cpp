#include "DiamondTrap.hpp"

int main() {
    std::cout << "---- Creating DiamondTrap ----" << std::endl;
    DiamondTrap dt("Shiny");

    std::cout << "\n---- Using DiamondTrap Methods ----" << std::endl;
    dt.attack("EnemyBot");      // from ScavTrap
    dt.highFivesGuys();         // from FragTrap
    dt.guardGate();             // from ScavTrap
    dt.whoAmI();                // from DiamondTrap

    std::cout << "\n---- Copy Constructor Test ----" << std::endl;
    DiamondTrap copy(dt);

    std::cout << "\n---- Assignment Operator Test ----" << std::endl;
    DiamondTrap assigned;
    assigned = dt;

    std::cout << "\n---- Destruction ----" << std::endl;
    return 0;
}

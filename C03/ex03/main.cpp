#include "DiamandTrap.hpp"
#include <iostream>

int main( void )
{
    std::cout << "--- 1. TESTING DIAMONDTRAP CONSTRUCTION ---" << std::endl;
    {
        DiamandTrap d1("Monster");
        
        std::cout << "\n[Checking Stats]" << std::endl;
		d1.getStats();
        d1.whoAmI();
        d1.attack("dummy_target");
    }

    std::cout << "\n--- 2. TESTING SPECIAL CAPABILITIES ---" << std::endl;
    {
        DiamandTrap d2("Hybrid");
        d2.whoAmI();
        d2.guardGate();
        d2.highFiveGuys();
    }

    std::cout << "\n---TESTING COPY/ASSIGNMENT ---" << std::endl;
    {
        DiamandTrap d3("Original");
        DiamandTrap d4(d3);
        
        DiamandTrap d5;
        d5 = d3;
        
        d4.whoAmI();
        d5.whoAmI();
    }

    return 0;
}
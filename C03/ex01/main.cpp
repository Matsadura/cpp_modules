#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a;
	ClapTrap b ( "Clappy" );
	ClapTrap c( b);
	ClapTrap d;

	d = c;

	d.attack("Victim");
	d.takeDamage(3);
	d.beRepaired(2);
	d.takeDamage(10);
	d.attack("Victim");
	d.beRepaired(5);

	ScavTrap e;
	ScavTrap f ( "Scavvy" );
	ScavTrap g( f );
	ScavTrap h;

	h = g;

	h.attack("Intruder");
	h.takeDamage(20);
	h.beRepaired(10);
	h.guardGate();
	h.takeDamage(100);
	h.attack("Intruder");
	h.beRepaired(50);
	h.guardGate();

	ClapTrap* ptr = new ScavTrap("New Scav");
	delete ptr;
	
	return (0);
}
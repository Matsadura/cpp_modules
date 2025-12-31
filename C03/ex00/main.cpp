#include "ClapTrap.hpp"

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

	return (0);
}
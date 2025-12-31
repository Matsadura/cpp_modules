#include "FragTrap.hpp"

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

	FragTrap e;
	FragTrap f( "Fraggy" );
	FragTrap g( f );
	FragTrap h;

	h = g;

	h.attack("Enemy");
	h.takeDamage(20);
	h.beRepaired(10);
	h.highFiveGuys();
	h.takeDamage(100);
	h.attack("Enemy");
	h.beRepaired(50);

	return (0);
}
#include "DiamandTrap.hpp"

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

	ScavTrap s;
	ScavTrap t( "Scavvy" );
	ScavTrap u( t );
	ScavTrap v;

	v = u;
	
	v.attack("Intruder");
	v.takeDamage(15);
	v.beRepaired(10);
	v.guardGate();
	v.takeDamage(100);
	v.attack("Intruder");
	v.beRepaired(50);


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

	DiamandTrap x;
	DiamandTrap y( "Diamandy" );
	DiamandTrap z( y );
	DiamandTrap w;

	w = z;

	w.attack("Target");
	w.takeDamage(30);
	w.beRepaired(15);
	w.guardGate();
	w.highFiveGuys();
	w.takeDamage(150);
	w.attack("Target");
	w.beRepaired(75);
	w.whoAmI();

	return (0);
}
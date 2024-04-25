#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap claptrap("junsbae");
	
	claptrap.attack("seongwol");
	claptrap.beRepaired(5);
	claptrap.takeDamage(11);
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	claptrap.attack("seongwol");
}
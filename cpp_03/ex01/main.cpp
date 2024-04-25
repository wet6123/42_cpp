#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap scavtrap("junsbae");
	
	scavtrap.attack("seongwol");
	scavtrap.beRepaired(5);
	scavtrap.takeDamage(11);
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(5);
	scavtrap.attack("seongwol");
	scavtrap.guardGate();
}
#include "FragTrap.hpp"

int main( void ) {
	FragTrap fragtrap("junsbae");
	
	fragtrap.attack("seongwol");
	fragtrap.beRepaired(5);
	fragtrap.takeDamage(11);
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(5);
	fragtrap.attack("seongwol");
	fragtrap.highFivesGuys();
}
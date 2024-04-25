#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
	// init
		ScavTrap(void);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator=(const ScavTrap& obj);
	// override
		// constructor
		ScavTrap(std::string name);
		// destructor
		~ScavTrap(void);
		// attack
		void attack(const std::string& target);
	// guard gate
		void guardGate(void);
};


#endif

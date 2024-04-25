#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	// init
		FragTrap(void);
		FragTrap(const FragTrap& obj);
		FragTrap& operator=(const FragTrap& obj);
	// override
		// constructor
		FragTrap(std::string name);
		// destructor
		~FragTrap(void);
	// high fives guys
		void highFivesGuys(void);
};


#endif

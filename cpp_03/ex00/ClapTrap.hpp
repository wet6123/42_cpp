#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int	hitPoint;
		int	energyPoint;
		int attackDamage;
	public:
		// init
		ClapTrap(void);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		ClapTrap(std::string name);
		~ClapTrap(void);
		// func
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		// move check
		bool	canMove(void);
};

#endif

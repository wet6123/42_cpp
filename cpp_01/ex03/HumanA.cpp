#include "Weapon.hpp"
#include "HumanA.hpp"

	HumanA::HumanA(std::string name, Weapon& weapon)
	: name(name), weapon(weapon)
	{}

	HumanA::~HumanA(void)
	{}

	void HumanA::attack()
	{
		std::cout << this->name << " attacks with their " << this->weapon.getType() << "\n";
	}
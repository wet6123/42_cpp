#include "Weapon.hpp"
#include "HumanB.hpp"

	HumanB::HumanB(std::string name)
	: name(name)
	{}

	HumanB::~HumanB(void)
	{}

	void HumanB::setWeapon(Weapon& weapon)
	{
		this->weapon = &weapon;
	}

	void HumanB::attack()
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << "\n";
	}
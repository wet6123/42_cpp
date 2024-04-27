#include "FragTrap.hpp"

FragTrap::FragTrap(void)
: ClapTrap()
{
	this->name = "noname";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
: ClapTrap(obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (canMove() == false)
	{
		std::cout << "FragTrap " << this->name << " can not move." << std::endl;
		return;
	}
	this->energyPoint = this->energyPoint - 1;
	std::cout << "high fives guys!!!!" << std::endl;
}

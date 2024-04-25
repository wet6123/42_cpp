#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
: ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	// hit point나 energy point가 없으면 동작 못함
	if (canMove() == false)
	{
		std::cout << "ScavTrap " << this->name << " can not move." << std::endl;
		return;
	}
	// attack
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (canMove() == false)
	{
		std::cout << "ScavTrap " << this->name << " can not move." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}

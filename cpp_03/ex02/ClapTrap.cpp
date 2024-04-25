# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
: name("noname"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->name = obj.name;
	this->hitPoint = obj.hitPoint;
	this->energyPoint = obj.energyPoint;
	this->attackDamage = obj.attackDamage;
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	// hit point나 energy point가 없으면 동작 못함
	if (canMove() == false)
	{
		std::cout << "ClapTrap " << this->name << " can not move." << std::endl;
		return;
	}
	// attack
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	// hit point나 energy point가 없으면 동작 못함
	if (canMove() == false)
	{
		std::cout << "ClapTrap " << this->name << " has no hit points." << std::endl;
		return;
	}
	// hit point 감소
	this->hitPoint = this->hitPoint - amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	// hit point나 energy point가 없으면 동작 못함
	if (canMove() == false)
	{
		std::cout << "ClapTrap " << this->name << " can not move." << std::endl;
		return;
	}
	// hit point 회복, energy point 감소
	this->hitPoint = this->hitPoint + amount;
	this->energyPoint = this->energyPoint - 1;
	std::cout << "ClapTrap " << this->name << " repair " << amount << " hit points!" << std::endl;
}

bool	ClapTrap::canMove(void)
{
	if (this->hitPoint <= 0 || this->energyPoint <= 0)
		return (false);
	return (true);
}

#include "Character.hpp"

Character::Character(void)
: name("default")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}

Character::Character(std::string name)
: name(name)
{
    std::cout << "Character string constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character &obj)
{
    std::cout << "Character copy constructor called." << std::endl;
    if(this != &obj)
    {
        this->name = obj.getName();
        for (int i = 0; i < 4; i++)
        {
            this->inventory[i] = obj.inventory[i];
        }
    }
}

Character& Character::operator=(const Character& obj)
{
    std::cout << "Character copy assignment operator called." << std::endl;
    if(this != &obj)
    {
        this->name = obj.getName();
        for (int i = 0; i < 4; i++)
        {
            this->inventory[i] = obj.inventory[i];
        }
    }
    return (*this);
}

Character::~Character(void)
{
    std::cout << "Character destructor called." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete inventory[i];
    }
}

std::string const & Character::getName() const
{
    // std::cout << "Character getName called." << std::endl;
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << "Materia is NULL." << std::endl;
        return ;
    }

    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            std::cout << "Materia " << m->getType() << " equiped at " << i << "." << std::endl;
            inventory[i] = m;
            return ;
        }
    }

    std::cout << "Inventory is full." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Index out of range: 0 ~ 3" << std::endl;
        return ;
    }

    if (inventory[idx])
    {
        std::cout << "Inventory " << idx << " unequiped." << std::endl;
        inventory[idx] = NULL;
    }
    else
    {
        std::cout << "Inventory " << idx << " is empty." << std::endl;
    }
    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (inventory[idx] == NULL)
    {
        std::cout << "Inventory " << idx << " is empty." << std::endl;
    }
    else
    {
        inventory[idx]->use(target);
        delete inventory[idx];
        inventory[idx] = NULL;
    }
}
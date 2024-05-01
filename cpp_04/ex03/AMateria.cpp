#include "AMateria.hpp"

AMateria::AMateria(void)
: type("default")
{
    std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type)
: type(type)
{
    std::cout << "AMateria string constructor called." << std::endl;
}

AMateria::AMateria(const AMateria& obj)
: type(obj.type)
{
    std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& obj)
{
    std::cout << "AMateria copy assignment operator called." << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this); 
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called." << std::endl;
}

std::string const & AMateria::getType() const //Returns the materia type
{
    // std::cout << "AMateria getType called." << std::endl;
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << target.getName() << " USE" << std::endl;
}
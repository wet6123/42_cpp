#include "Cure.hpp"

Cure::Cure(void)
: AMateria()
{
    std::cout << "Cure default constructor called." << std::endl;
    this->type = "cure";
}

Cure::Cure(std::string const & type)
: AMateria(type)
{
    std::cout << "Cure string constructor called." << std::endl;
}

Cure::Cure(const Cure& obj)
: AMateria(obj)
{
    std::cout << "Cure copy constructor called." << std::endl;
    this->type = obj.type;
}

Cure& Cure::operator=(const Cure& obj)
{
    std::cout << "Cure copy assignment operator called." << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this); 
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone(void) const
{
    std::cout << "Cure clone called." << std::endl;
    Cure *result = new Cure(this->type);
    return (result);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
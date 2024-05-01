#include "Ice.hpp"

Ice::Ice(void)
: AMateria()
{
    std::cout << "Ice default constructor called." << std::endl;
    this->type = "ice";
}

Ice::Ice(std::string const & type)
: AMateria(type)
{
    std::cout << "Ice string constructor called." << std::endl;
}

Ice::Ice(const Ice& obj)
: AMateria(obj)
{
    std::cout << "Ice copy constructor called." << std::endl;
    this->type = obj.type;
}

Ice& Ice::operator=(const Ice& obj)
{
    std::cout << "Ice copy assignment operator called." << std::endl;
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this); 
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone(void) const
{
    std::cout << "Ice clone called." << std::endl;
    Ice *result = new Ice(this->type);
    return (result);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
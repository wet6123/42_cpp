#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->source[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    std::cout << "MateriaSource copy constructor called." << std::endl;
    if(this != &obj)
    {    
        for (int i = 0; i < 4; i++)
        {
            this->source[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    std::cout << "MateriaSource copy assignment operator called." << std::endl;
    if(this != &obj)
    {
        for (int i = 0; i < 4; i++)
        {
            this->source[i] = obj.source[i];
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
            delete source[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] == NULL)
        {
            std::cout << "Materia " << m->getType() << " learned." << std::endl;
            this->source[i] = m->clone();
            return ;
        }
    }
    std::cout << "MateriaSource is Full." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i]->getType() == type)
        {
            return (source[i]->clone());
        }
    }
    return (0);
}
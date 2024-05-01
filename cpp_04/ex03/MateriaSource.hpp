#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *source[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &obj);
        virtual MateriaSource& operator=(const MateriaSource& obj);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif
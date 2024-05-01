#ifndef CURE_HPP
# define CURE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
  public:
    Cure(void);
    Cure(std::string const & type);
    Cure(const Cure& obj);
    Cure& operator=(const Cure& obj);
    ~Cure(void);

    AMateria* clone(void) const;
    void use(ICharacter& target);
};

#endif
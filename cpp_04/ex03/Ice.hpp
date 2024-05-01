#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
  public:
    Ice(void);
    Ice(std::string const & type);
    Ice(const Ice& obj);
    Ice& operator=(const Ice& obj);
    ~Ice(void);

    AMateria* clone(void) const;
    void use(ICharacter& target);
};

#endif
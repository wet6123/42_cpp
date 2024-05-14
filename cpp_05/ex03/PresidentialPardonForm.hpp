#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
    std::string target;
    PresidentialPardonForm(void);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
  public:
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm(void);
    void executeChild(void) const;
    static AForm* clone(const std::string& target);
};

#endif
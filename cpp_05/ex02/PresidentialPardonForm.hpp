#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  // target 추가?
  private:
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm & operator=(PresidentialPardonForm const & src);
  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm(void);
    void execute(const Bureaucrat& executor) const;
};

#endif
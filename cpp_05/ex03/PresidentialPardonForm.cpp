#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm("presidential pardon", 25, 5)
{
  this->target = obj.target;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("presidential pardon", 25, 5)
{
  this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

void PresidentialPardonForm::executeChild(void) const
{
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::clone(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}
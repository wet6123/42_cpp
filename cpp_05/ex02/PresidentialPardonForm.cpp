#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
: AForm("presidential pardon form", 25, 5)
{
  this->target = obj.target;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("presidential pardon form", 25, 5)
{
  this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

void PresidentialPardonForm::executeChild(void) const
{
  std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
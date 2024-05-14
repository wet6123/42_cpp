#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("default_pardon", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm(target + "_pardon", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
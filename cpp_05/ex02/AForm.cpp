#include "AForm.hpp"

AForm::AForm(void)
: name("default"), sign(false), signGrade(150), execGrade(150)
{}

AForm::AForm(std::string name, int signGrade, int execGrade)
: name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
    else if (signGrade < 1)
    {
        throw AForm::GradeTooHighException();
    }

    if (execGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
    else if (execGrade < 1)
    {
        throw AForm::GradeTooHighException();
    }
}

AForm::~AForm(void)
{}

std::string AForm::getName(void) const { return (this->name); }
bool AForm::getSign(void) const { return (this->sign); }
int AForm::getSignGrade(void) const { return (this->signGrade); }
int AForm::getExecGrade(void) const { return (this->execGrade); }

void AForm::setSign(bool status) { this->sign = status; }

void AForm::beSigned(const Bureaucrat& obj)
{
    if (this->signGrade >= obj.getGrade())
    {
        // can sign
        setSign(true);
    }
    else
    {
        // can not sign
        throw AForm::GradeTooLowException();
    }
}

const char * AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade too high";
}

const char * AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, AForm& obj)
{
    out << obj.getName() << ", signed: " << (obj.getSign() ? "true" : "false") << ", sign grade: " << obj.getSignGrade() << ", execute grade: " << obj.getExecGrade();
    return out;
}

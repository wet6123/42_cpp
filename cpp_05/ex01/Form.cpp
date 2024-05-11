#include "Form.hpp"

Form::Form(void)
: name("default"), sign(false), signGrade(150), execGrade(150)
{}

Form::Form(std::string name, int signGrade, int execGrade)
: name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (signGrade < 1)
    {
        throw Form::GradeTooHighException();
    }

    if (execGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
    else if (execGrade < 1)
    {
        throw Form::GradeTooHighException();
    }
}

Form::~Form(void)
{}

std::string Form::getName(void) const { return (this->name); }
bool Form::getSign(void) const { return (this->sign); }
int Form::getSignGrade(void) const { return (this->signGrade); }
int Form::getExecGrade(void) const { return (this->execGrade); }

void Form::setSign(bool status) { this->sign = status; }

void Form::beSigned(const Bureaucrat& obj)
{
    if (this->signGrade >= obj.getGrade())
    {
        // can sign
        setSign(true);
    }
    else
    {
        // can not sign
        throw Form::GradeTooLowException();
    }
}

const char * Form::GradeTooHighException::what(void) const throw()
{
    return "Grade too high";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, Form& obj)
{
    out << obj.getName() << ", signed: " << (obj.getSign() ? "true" : "false") << ", sign grade: " << obj.getSignGrade() << ", execute grade: " << obj.getExecGrade();
    return out;
}

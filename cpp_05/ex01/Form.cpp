#include "Form.hpp"

        // const std::string name;
        // bool sign;
        // const int signGrade;
        // const int execGrade;

Form::Form(void)
: name("default"), sign(false), signGrade(150), execGrade(150)
{}

Form::Form(std::string name, bool sign, int signGrade, int execGrade)
: name(name), sign(sign), signGrade(signGrade), execGrade(execGrade)
{}

Form::~Form(void)
{}

std::string Form::getName(void) const { return (this->name); }
bool Form::getSign(void) const { return (this->sign); }
int Form::getSignGrade(void) const { return (this->signGrade); }
int Form::getExecGrade(void) const { return (this->execGrade); }

void Form::beSigned(const Bureaucrat& obj)
{
    if (this->signGrade < obj.getGrade())
    {
        // can not sign
        std::cout << obj.getName() << " couldn’t sign " << this->name << " because ";
        throw Form::GradeTooLowException();
    }
    else
    {
        // can sign
        // this->sign = true;
        std::cout << obj.getName() << " signed " << this->name << "\n";
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

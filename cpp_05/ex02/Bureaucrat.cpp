#include "Bureaucrat.hpp"
#include "AForm.hpp"

// occf
Bureaucrat::Bureaucrat(void)
: name("default"), grade(150)
{}

// Bureaucrat::Bureaucrat(const Bureaucrat& obj)
// {
//     if (this != &obj)
//         *this = obj;
// }

// Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
// {
//     if (this != &obj)
//     {
//         this->name = obj.getName();
//         this->grade = obj.getGrade();
//     }
//     return (*this);
// }

Bureaucrat::~Bureaucrat(void)
{}

// custom
Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name), grade(grade)
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

// function
std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::signForm(AForm& obj)
{
    try
    {
        // can sign
        obj.beSigned(*this);
        std::cout << this->name << " signed " << obj.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        // can not sign
        std::cout << this->name << " couldn’t sign " << obj.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(const AForm& obj)
{
    try
    {
        // execute
        obj.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

// exception
const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade too low";
}

// operator
std::ostream& operator<<(std::ostream& out, Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}
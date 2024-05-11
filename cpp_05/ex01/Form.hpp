#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;

        Form(const Form& ojb);
        Form& operator=(const Form& obj);
    public:
        Form(void);
        Form(std::string name, int signGrade, int execGrade);
        ~Form(void);

        std::string getName(void) const;
        bool getSign(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;

        void setSign(bool status);

        void beSigned(const Bureaucrat& obj);

        class GradeTooHighException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& out, Form& obj);

#endif
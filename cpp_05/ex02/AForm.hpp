#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        bool sign;
        const int signGrade;
        const int execGrade;

        AForm(const AForm& ojb);
        AForm& operator=(const AForm& obj);
    public:
        AForm(void);
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm(void);

        std::string getName(void) const;
        bool getSign(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;

        void setSign(bool status);

        void beSigned(const Bureaucrat& obj);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, AForm& obj);

#endif
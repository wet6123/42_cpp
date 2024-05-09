#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        // ranges from 1 (highest possible grade) to 150 (lowest possible grade)
        int grade;

        // occf
        Bureaucrat(const Bureaucrat& obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
    public:
        // occf
        Bureaucrat(void);
        ~Bureaucrat(void);

        // custom
        Bureaucrat(std::string name, int grade);

        // fuction
        std::string getName(void);
        int getGrade(void);
        void incrementGrade(void);
        void decrementGrade(void);

        // exception
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

std::ostream& operator<<(std::ostream& out, Bureaucrat& obj);

#endif
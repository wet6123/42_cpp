#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN
{
    private:
        double  _result;

    public:
        RPN(void);
        RPN(const RPN &obj);
        RPN &operator=(const RPN &obj);
        ~RPN(void);

        void    calculate(std::string str);
        void    printResult(void) const;
};

#endif
#include "RPN.hpp"

RPN::RPN(void)
: _result(0)
{}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN& RPN::operator=(const RPN &obj)
{
    _result = obj._result;
    return (*this);
}

RPN::~RPN(void)
{}

void RPN::calculate(std::string str)
{
    std::stack<double> stack;
    std::string::size_type i = 0;
    double a, b;

    while (i < str.size())
    {
        if (std::isdigit(str[i]))
        {
            stack.push(std::strtod(&str[i], NULL));
            i++;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (stack.size() < 2)
                throw std::invalid_argument("Error: not enough numbers");

            b = stack.top();
            stack.pop();
            a = stack.top();
            stack.pop();

            if (str[i] == '+')
                stack.push(a + b);
            else if (str[i] == '-')
                stack.push(a - b);
            else if (str[i] == '*')
                stack.push(a * b);
            else if (str[i] == '/')
                stack.push(a / b);
            i++;
        }
        else if (str[i] == ' ')
            i++;
        else
            throw std::invalid_argument("Error: invalid character");
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Error: too many numbers");
    _result = stack.top();
    stack.pop();
}

void RPN::printResult(void) const
{
    std::cout << _result << std::endl;
}
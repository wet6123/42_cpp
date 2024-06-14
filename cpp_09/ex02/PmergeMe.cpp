#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [num1 num2 ...]" << std::endl;
        exit(1);
    }

    try
    {
        std::vector<int> nums = parseNums(argc, argv);
        fillVector(nums);
        fillList(nums);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    for (std::vector< std::vector<int> >::iterator it = _v.begin(); it != _v.end(); it++)
    {
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
        {
            std::cout << *it2 << " ";
        }
        std::cout << std::endl;
    }

    for (std::list< std::list<int> >::iterator lit = _l.begin(); lit != _l.end(); lit++)
    {
        for (std::list<int>::iterator lit2 = lit->begin(); lit2 != lit->end(); lit2++)
        {
            std::cout << *lit2 << " ";
        }
        std::cout << std::endl;
    }
}

PmergeMe::~PmergeMe(void)
{}

std::vector<int> PmergeMe::parseNums(int argc, char **argv)
{
    std::vector<int> nums;

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (std::isdigit(argv[i][j]) == 0)
            {
                throw std::invalid_argument("Invalid argument");
            }
        }

        nums.push_back(std::strtod(argv[i], NULL));
    }

    return (nums);
}

void PmergeMe::fillVector(std::vector<int> nums)
{
    for (std::vector<int>::iterator it = nums.begin(); it < nums.end(); it += 2)
    {
        std::vector<int> v;

        if (it + 1 < nums.end())
        {
            if (*it > *(it + 1))
            {
                v.push_back(*(it + 1));
                v.push_back(*it);
            }
            else
            {
                v.push_back(*it);
                v.push_back(*(it + 1));
            }
        }
        else
        {
            v.push_back(*it);
        }

        _v.push_back(v);
    }
}

void PmergeMe::fillList(std::vector<int> nums)
{
    for (std::vector<int>::iterator it = nums.begin(); it < nums.end(); it += 2)
    {
        std::list<int> l;

        l.push_back(*it);
        if (it + 1 < nums.end())
        {
            if (*it > *(it + 1))
            {
                l.push_front(*(it + 1));
            }
            else
            {
                l.push_back(*(it + 1));
            }
        }

        _l.push_back(l);
    }
}
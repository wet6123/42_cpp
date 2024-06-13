#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

class PmergeMe
{
    private:
        std::vector<int> _v;
        std::list<int> _l;
        bool* _visited;
        
        struct pair
        {
            int front;
            int back;
        };

        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe(void);
    public:
        PmergeMe(int argc, char **argv);
};

#endif
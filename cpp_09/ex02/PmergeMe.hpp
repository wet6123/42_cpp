#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <cctype>
# include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<unsigned int> Jacobsthal;
        std::vector<int> nums;
        std::vector<int> _v;
        std::list<int> _l;
        double vectorTime;
        double listTime;

        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe(void);

        std::vector<int> parseNums(int argc, char **argv);

        void sort(void);
        void sortVector(std::vector< std::pair<int, int> > *v);
        int *sortList(std::list<int> l);
        void printResult(void);
};

#endif
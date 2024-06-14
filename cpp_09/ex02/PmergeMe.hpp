#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <cctype>

class PmergeMe
{
    private:
        std::vector< std::vector<int> > _v;
        std::list< std::list<int> > _l;
        std::vector<int> nums;
        double vectorTime;
        double listTime;

        PmergeMe(void);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
    public:
        PmergeMe(int argc, char **argv);
        ~PmergeMe(void);

        std::vector<int> parseNums(int argc, char **argv);
        void fillVector(std::vector<int> nums);
        void fillList(std::vector<int> nums);

        void sort(void);
        void sortVector(void);
        void sortList(void);
        void printResult(void);
};

#endif
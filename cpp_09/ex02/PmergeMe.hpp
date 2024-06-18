#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <cstdlib>
# include <cctype>
# include <sys/time.h>
# include <iterator>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<unsigned int> JacobsthalVector;
        std::list<unsigned int> JacobsthalList;
        std::vector<int> nums;
        std::vector< std::pair<int, int> > _v;
        std::list< std::pair<int, int> > _l;
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
        void sortList(std::list< std::pair<int, int> > *l);
        void printResult(void);

};

template <typename InputIterator>
InputIterator next(InputIterator it, typename std::iterator_traits<InputIterator>::difference_type n = 1)
{
    std::advance(it, n);
    return it;
};

template <typename InputIterator>
InputIterator prev(InputIterator it, typename std::iterator_traits<InputIterator>::difference_type n = 1)
{
    std::advance(it, -n);
    return it;
};

#endif
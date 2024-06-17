#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
: vectorTime(0), listTime(0)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [num1 num2 ...]" << std::endl;
        exit(1);
    }

    try
    {
        nums = parseNums(argc, argv);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    Jacobsthal.push_back(0);
    Jacobsthal.push_back(1);
    while(Jacobsthal.back() < nums.size())
    {
        Jacobsthal.push_back(Jacobsthal[Jacobsthal.size() - 1] + 2 * Jacobsthal[Jacobsthal.size() - 2]);
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
        int num = std::strtod(argv[i], NULL);
        nums.push_back(num);
    }

    return (nums);
}

void PmergeMe::sort(void)
{
    struct timeval start, end;
    std::vector< std::pair<int, int> > v;
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        v.push_back(std::make_pair(*it, it - nums.begin()));
    }
    
    gettimeofday(&start, NULL);
    // 수정
    sortVector(&v);
    for (std::vector< std::pair<int, int> >::iterator it = v.begin(); it != v.end(); it++)
    {
        _v.push_back(it->first);
    }
    // 여기까지
    gettimeofday(&end, NULL);
    vectorTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
    
    gettimeofday(&start, NULL);
    sortList(_l);
    gettimeofday(&end, NULL);
    listTime = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    printResult();
}

void PmergeMe::sortVector(std::vector< std::pair<int, int> > *v)
{
    if (v->size() == 1)
    {
        return;
    }

    std::vector< std::pair<int, int> > main;
    std::vector< std::pair<int, int> > sub;

    for (std::vector< std::pair<int, int> >::iterator it = v->begin(); it + 1 < v->end(); it += 2)
    {
        int num1 = it->first;
        int num2 = (it + 1)->first;

        if (num1 > num2)
        {
            main.push_back(std::make_pair(num1, it->second));
        }
        else
        {
            main.push_back(std::make_pair(num2, (it + 1)->second));
        }
    }

    sortVector(&main);

    for (std::vector< std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
    {
        for (std::vector< std::pair<int, int> >::iterator it2 = v->begin(); it2 != v->end(); it2++)
        {
            if (it->second == it2->second)
            {
                if ((it2 - v->begin()) % 2 == 0)
                {
                    sub.push_back(std::make_pair((it2 + 1)->first, (it2 + 1)->second));
                }
                else
                {
                    sub.push_back(std::make_pair((it2 - 1)->first, (it2 - 1)->second));
                }
            }
        }
    }

    if (v->size() % 2 == 1)
    {
        sub.push_back(std::make_pair(v->back().first, v->back().second));
    }
    
    // binary search
    std::vector< std::pair<int, int> > newV;
    newV = main;
    std::vector<int> mainIdx;

    for (std::vector< std::pair<int, int> >::iterator it = main.begin(); it != main.end(); it++)
    {
        mainIdx.push_back(it - main.begin());
    }

    for (unsigned int i = 2; i < Jacobsthal.size(); i++)
    {
    //  0 1 1 3 5 11 ...
        int start = Jacobsthal[i] - 1;
        int end = Jacobsthal[i - 1] - 1;

        if (start == end && start == 0)
            end = -1;
        if (start > static_cast<int>(sub.size() - 1))
            start = sub.size() - 1;
        if (end > static_cast<int>(sub.size() - 1))
            break;

        for (int j = start; j > end; j--)
        {
            int left = 0;
            int right = mainIdx[j];
            if (static_cast<int>(mainIdx.size()) < j + 1)
                right = newV.size() - 1;
            int mid = (left + right) / 2;

            while (left <= right)
            {
                mid = (left + right) / 2;
                if (newV[mid].first == sub[j].first)
                {
                    break ;
                }
                else if (newV[mid].first < sub[j].first)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (newV[mid].first < sub[j].first)
            {
                mid++;
            }

            newV.insert(newV.begin() + mid, sub[j]);

            for (std::vector<int>::iterator mainIdxIt = mainIdx.begin(); mainIdxIt != mainIdx.end(); mainIdxIt++)
            {
                if (*mainIdxIt >= mid)
                {
                    (*mainIdxIt)++;
                }
            }
        }
    }

    *v = newV;

    return ;
}

int *PmergeMe::sortList(std::list<int> l)
{
    (void)l;
    return (NULL);
}

void PmergeMe::printResult(void)
{
    std::cout << "Before:   ";
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After:    ";
    for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of    " << nums.size() << " elements with std::vector :   " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of    " << nums.size() << " elements with std::list   :   " << listTime << " us" << std::endl;
}
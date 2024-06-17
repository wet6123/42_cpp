#include <iostream>
#include <vector>
#include <algorithm>

int main (int argc, char **argv)
{
  std::vector<int> origin;
  std::vector<int> sorted;

  for (int i = 1; i < argc; i++)
  {
    for (int j = 0; argv[i][j]; j++)
    {
      if (std::isdigit(argv[i][j]) == 0)
      {
        std::cerr << "Invalid argument" << std::endl;
        return (1);
      }
    }
    int num = std::strtod(argv[i], NULL);
    origin.push_back(num);
  }

  sorted = origin;
  sort(sorted.begin(), sorted.end());

  for(std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); it++)
  {
    if(*it != origin[it - sorted.begin()])
    {
      std::cout << "KO" << std::endl;
      return (0);
    }
  }

  std::cout << "OK" << std::endl;

  return (0);
}
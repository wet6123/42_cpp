#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
  std::cout << "Brain copy assignment operator called." << std::endl;
  return (*this);
}

Brain::~Brain(void)
{
  std::cout << "Brain destructor called." << std::endl;
}

std::string Brain::getIdeas(int idx) const
{
  return (ideas[idx]);
}

void Brain::setIdeas(int idx, std::string idea)
{
  ideas[idx] = idea;
}
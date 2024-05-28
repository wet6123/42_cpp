#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator result;
	result = std::find(container.begin(), container.end(), n);
	if (result == container.end())
		throw std::exception();
	return (result);
}

#endif
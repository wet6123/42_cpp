#include "Span.hpp"

Span::Span(unsigned int N) : _n(N)
{}

Span::Span(const Span& obj)
{
	if (this != &obj)
		*this = obj;
}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		_n = obj._n;
		_v = obj._v;
	}
	return (*this);
}

Span::~Span(void)
{}

void Span::addNumber(int num)
{
	if (_v.size() >= _n)
		throw std::exception();
	_v.push_back(num);
}

int Span::shortestSpan(void)
{
	if (_v.size() <= 1)
		throw std::exception();

	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min;
	min = INT_MAX;
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan(void)
{
	if (_v.size() <= 1)
		throw std::exception();

	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size()-1] - tmp[0]);
}


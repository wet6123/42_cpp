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

	int min;
	min = INT_MAX;
	for (size_t i = 0; i < _v.size() - 1; i++)
	{
		if (abs(_v[i + 1] - _v[i]) < min)
			min = abs(_v[i + 1] - _v[i]);
	}
	return (min);
}

int Span::longestSpan(void)
{
	if (_v.size() <= 1)
		throw std::exception();

	int max;
	max = INT_MIN;
	for (size_t i = 0; i < _v.size() - 1; i++)
	{
		if (abs(_v[i + 1] - _v[i]) > max)
			max = abs(_v[i + 1] - _v[i]);
	}
	return (max);
}
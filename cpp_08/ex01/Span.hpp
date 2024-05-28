#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cmath>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
		Span(void);
	public:
		Span(unsigned int N);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span(void);

		void addNumber(int num);
		int longestSpan(void);
		int shortestSpan(void);
};

#endif
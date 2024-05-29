#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cmath>
# include <ctime>

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

		template <typename T>
		void insert(typename T::iterator begin, typename T::iterator end)
		{
			if (_v.size() + std::distance(begin, end) > _n)
				throw std::exception();
			_v.insert(_v.end(), begin, end);
		}
};

#endif
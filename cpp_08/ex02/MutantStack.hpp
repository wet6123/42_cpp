#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack( void )
		: std::stack<T>()
		{}
		
		MutantStack( MutantStack const &obj )
		: std::stack<T>(obj)
		{}

		MutantStack &operator=( MutantStack const &obj )
		{
			if (this != &obj)
				*this = obj;
			return ( *this );
		}

		~MutantStack( void )
		{}

		//iterator
		typedef typename MutantStack<T>::container_type::iterator iterator;
		
		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		//reverse iterator
		typedef typename MutantStack<T>::container_type::reverse_iterator reverse_iterator;
		
		reverse_iterator rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend(void)
		{
			return (this->c.rend());
		}
};

#endif
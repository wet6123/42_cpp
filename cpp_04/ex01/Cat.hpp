#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <sstream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		~Cat(void);
		virtual void makeSound(void) const;
		Brain* getBrain(void) const;
};

#endif

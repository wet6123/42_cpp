#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(const WrongDog& obj);
		WrongDog& operator=(const WrongDog& obj);
		~WrongDog(void);
		void makeSound(void) const;

};

#endif

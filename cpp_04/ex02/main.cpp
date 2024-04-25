#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// 순수 가상 함수를 가지고 있는 클래스는 객체를 생성할 수 없다.
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();
	
	delete i;
	delete j;
	// delete meta;

	return 0;
}
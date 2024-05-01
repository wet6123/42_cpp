#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// 순수 가상 함수를 가지고 있는 클래스는 객체를 생성할 수 없다.
	// const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	// animal->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	
	// delete animal;
	delete cat;
	delete dog;

	return 0;
}
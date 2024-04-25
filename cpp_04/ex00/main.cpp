#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// 일반함수는 참조형식을 따르고 가상함수는 실형식으로 따름
	// 참조형식은 Animal이지만 실형식은 Cat, Dog 임
	// Cat, Dog 소리를 내야함 -> 가상함수 사용해야함
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	// 추상 자료형으로 참조시 소멸자 가상화를 하지 않으면 파생 형식의 소멸자가 호출되지 않음.
	delete i;
	delete j;
	delete meta;

	return 0;
}
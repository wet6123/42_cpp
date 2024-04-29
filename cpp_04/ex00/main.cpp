#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong/WrongAnimal.hpp"
#include "Wrong/WrongCat.hpp"

int main()
{
	// 일반함수는 참조형식을 따르고 가상함수는 실형식으로 따름
	// 참조형식은 Animal이지만 실형식은 Cat, Dog 임
	// Cat, Dog 소리를 내야함 -> 가상함수 사용해야함
	std::cout << "\n*** Animal ***\n" << std::endl;

	const Animal* animal = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout << cat->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;

	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	animal->makeSound();
	
	// 추상 자료형으로 참조시 소멸자 가상화를 하지 않으면 파생 형식의 소멸자가 호출되지 않음.
	delete cat;
	delete dog;
	delete animal;

	// WrongAnimal
	std::cout << "\n*** Wrong Animal ***\n" << std::endl;

	const WrongAnimal* wAnimal = new WrongAnimal();
	const WrongAnimal* wCat = new WrongCat();

	std::cout << wCat->getType() << " " << std::endl;

	wCat->makeSound(); //will output the cat sound!
	wAnimal->makeSound();
	
	delete wCat;
	delete wAnimal;

	return 0;
}
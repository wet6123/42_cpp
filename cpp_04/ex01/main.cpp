#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta[10];

	std::cout << "----make & del test----" << std::endl;

	for(int i = 0; i < 10; i++)
	{
		if(i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	std::cout << "--------del test-------" << std::endl;

	for(int i = 0; i < 10; i++)
	{
		delete meta[i];
	}

	std::cout << "-------copy test-------" << std::endl;

	Cat& cat1 = new Cat();
	Cat& cat2 = new Cat();

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;

	cat1 = cat2;

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;

	std::cout << "---set cat 1 - idea 0--" << std::endl;
	cat1->getBrain()->setIdeas(0, "new idea");

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;

	std::cout << "-----copy del test-----" << std::endl;

	delete &cat1;
	delete &cat2;

	return 0;
}
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong/WrongAnimal.hpp"
#include "Wrong/WrongCat.hpp"

int main()
{
	const Animal* animal[10];

	std::cout << "----make test----" << std::endl;

	for(int i = 0; i < 10; i++)
	{
		if(i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	std::cout << "--------del test-------" << std::endl;

	for(int i = 0; i < 10; i++)
	{
		delete animal[i];
	}

	std::cout << "-------copy test-------" << std::endl;

	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	Cat* cat3 = new Cat(*cat1);

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 3 - idea 0: " << cat3->getBrain()->getIdeas(0) << std::endl;

	*cat1 = *cat2;

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 3 - idea 0: " << cat3->getBrain()->getIdeas(0) << std::endl;

	std::cout << "---set cat new idea----" << std::endl;
	cat1->getBrain()->setIdeas(0, "new idea 1");
	cat2->getBrain()->setIdeas(0, "new idea 2");
	cat3->getBrain()->setIdeas(0, "new idea 3");

	std::cout << "cat 1 - idea 0: " << cat1->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 2 - idea 0: " << cat2->getBrain()->getIdeas(0) << std::endl;
	std::cout << "cat 3 - idea 0: " << cat3->getBrain()->getIdeas(0) << std::endl;

	std::cout << "-----copy del test-----" << std::endl;

	delete cat1;
	delete cat2;
	delete cat3;

	return 0;
}
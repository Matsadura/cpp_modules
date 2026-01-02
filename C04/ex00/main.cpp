#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* animals[4];

	for (int i = 0; i < 4; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and says: ";
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
	}

	std::cout << std::endl;

	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongAnimal is a " << wrongAnimal->getType() << " and says: ";
	wrongAnimal->makeSound();

	std::cout << "WrongCat is a " << wrongCat->getType() << " and says: ";
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
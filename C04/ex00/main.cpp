#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

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

	return 0;
}
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----- Animal Array Test -----" << std::endl;
	Animal* animals[4];

	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	std::cout << std::endl;

	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();
	std::cout << std::endl;
	
	for (int i = 0; i < 4; ++i)
	{
		animals[i]->makeSound();
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----- Wrong Animal Test -----" << std::endl;
	WrongAnimal* wrongAnimal = new WrongCat();
	wrongAnimal->makeSound();
	delete wrongAnimal;

	std::cout << std::endl;
	std::cout << "----- Deep Copy Test -----" << std::endl;
	Cat originalCat;
	{
		Cat copiedCat = originalCat;
	}

	return 0;
}
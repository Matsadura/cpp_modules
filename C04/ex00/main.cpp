#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "----- Animal Test -----" << std::endl;
	const Animal* animal1 = new Dog();
	const Animal* animal2 = new Cat();


	std::cout << std::endl;

	std::cout << "----- Animal Sounds -----" << std::endl;
	std::cout << "Animal 1 is a " << animal1->getType() << " and says: ";
	animal1->makeSound();
	std::cout << "Animal 2 is a " << animal2->getType() << " and says: ";
	animal2->makeSound();

	std::cout << std::endl;

	std::cout << "----- Cleaning Up -----" << std::endl;
	delete animal1;
	delete animal2;

	std::cout << std::endl;

	std::cout << "----- Wrong Animal Test -----" << std::endl;
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
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "===== BASIC SETUP =====" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n===== UNKNOWN MATERIA =====" << std::endl;
	tmp = src->createMateria("fire");   // should return NULL
	me->equip(tmp);                     // should do nothing safely

	std::cout << "\n===== EQUIP MORE THAN 4 =====" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); // 5th materia → should be ignored

	std::cout << "\n===== USE INVALID SLOTS =====" << std::endl;
	me->use(-1, *bob);   // invalid index
	me->use(10, *bob);   // invalid index

	std::cout << "\n===== UNEQUIP TEST =====" << std::endl;
	me->unequip(1);      // remove cure
	me->use(1, *bob);    // should do nothing

	std::cout << "\n===== DEEP COPY TEST =====" << std::endl;
	ICharacter* clone = new Character(*(Character*)me);

	clone->use(0, *bob); // should work independently
	me->unequip(0);
	clone->use(0, *bob); // should STILL work (deep copy)

	std::cout << "\n===== SOURCE LIMIT TEST =====" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure()); // beyond limit → ignored

	std::cout << "\n===== CLEANUP =====" << std::endl;
	delete clone;
	delete bob;
	delete me;
	delete src;
	delete tmp;

	return 0;
}


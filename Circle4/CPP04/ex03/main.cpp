#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void leaks()
{
	system("leaks materia");
}

void	subjectTest()
{
	std::cout << "---------- Subject test ----------" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter *bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	std::cout << std::endl;
}

void	myTest()
{
	std::cout << "---------- My test ----------" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

	Character *mi = (Character *)me;
	tmp = mi->getInventorySlot(0);	
	me->unequip(0);
	me->use(0, *me);
	
	me->unequip(4);
	me->use(4, *me);
	
	// AMateria	*cure = src->createMateria("cure");
	// me->equip(cure);
	// me->use(0, *me);

	delete tmp;
	delete src;
	delete me;
	
	std::cout << std::endl;
}

void	copyTest()
{
	std::cout << "---------- Copy test ----------" << std::endl;
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria	*ice = src->createMateria("ice");
	me->equip(ice);

	Character *mi = (Character*)me;
	Character you(*mi);
	
	delete me;
	
	you.use(0, you);

	delete src;
	
	std::cout << std::endl;
}

int main()
{
	atexit(leaks);
	subjectTest();
	myTest();
	copyTest();
	return 0;
}

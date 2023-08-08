#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void leaks()
{
	system("leaks a.out");
}

void	subjectTest()
{
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
}

void	myTest()
{
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
	tmp = src->createMateria("cure");
	me->equip(tmp);

	Character *mi = (Character *)me;
	tmp = mi->getInventorySlot(0);	
	me->unequip(0);
	me->use(0, *me);
	me->equip(tmp);
	me->use(1, *me);

	// delete tmp;
	delete src;
	delete me;
}

void	copyTest()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	me->equip(new Ice());

	Character *mi = (Character*)me;
	Character you(*mi);
	
	you.use(0, you);

	// delete you;
	delete me;
	delete src;
}

int main()
{
	atexit(leaks);
	// subjectTest();
	// myTest();
	copyTest();
	return 0;
}

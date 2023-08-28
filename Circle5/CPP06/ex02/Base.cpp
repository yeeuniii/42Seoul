#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base	*generate()
{
	srand(time(NULL));
	int	randomValue = rand();

	switch (randomValue % 3)
	{
		case 0:
			return dynamic_cast<Base*>(new A());
		case 1:
			return dynamic_cast<Base*>(new B());
		case 2:
			return dynamic_cast<Base*>(new C());
	}
	return 0;
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);
	std::string	type;

	std::cout << "My actual type is ";
	if (a)
		type = a->getType();
	if (b)
		type = b->getType();
	if (c)
		type = c->getType();
	std::cout << type << "." << std::endl;
}

void	identify(Base &p)
{
	std::string	type;

	std::cout << "My actual type is ";
	try
	{
		type = dynamic_cast<A&>(p).getType();
	}
	catch(std::exception& e) {}
	try
	{
		type = dynamic_cast<B&>(p).getType();
	}
	catch(std::exception& e) {}
	try
	{
		type = dynamic_cast<C&>(p).getType();
	}
	catch(std::exception& e) {}
	std::cout << type << "." << std::endl;	
}

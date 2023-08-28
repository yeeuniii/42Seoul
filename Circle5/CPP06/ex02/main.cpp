#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void leaks()
{
	system("leaks base");
}

int main()
{
	// atexit(leaks);
	std::cout << "----------Dervied class----------" << std::endl;
	{
		Base *base = generate();
		Base &baseRef = *base;

		identify(base);
		identify(baseRef);

		delete base;
	}
	std::cout << std::endl;
	std::cout << "----------Base class----------" << std::endl;
	{
		Base *base = new Base();
		Base &baseRef = *base;

		identify(base);
		identify(baseRef);

		delete base;
	}
	std::cout << std::endl;
	std::cout << "----------NULL----------" << std::endl;
	{
		Base *base = 0;

		identify(base);
	}
	return 0;
}
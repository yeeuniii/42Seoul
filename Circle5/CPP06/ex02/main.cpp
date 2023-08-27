#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void leaks()
{
	system("leaks base");
}

int	main()
{	
	Base	*base = generate();
	Base	&baseRef = *base;
	
	// atexit(leaks);
	
	identify(base);
	identify(baseRef);

	delete base;
	return 0;
}
#include "Zombie.hpp"

// void	leaks()
// {
// 	system("leaks zombie");
// }

int	main()
{
	Zombie	*horde = zombieHorde(5, "zom");

	// atexit(leaks);
	for (int idx = 0; idx < 5; idx++)
	{
		horde[idx].announce();
	}
	delete[] horde;
	return 0;
}

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde = zombieHorde(5, "zom");

	for (int idx = 0; idx < 5; idx++)
	{
		horde[idx].announce();
	}
	delete[] horde;
	return 0;
}

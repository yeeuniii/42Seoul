#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	claptrap1("1");
	ClapTrap	claptrap2("2");

	std::cout << std::endl;
	claptrap1.displayStatus();
	claptrap2.displayStatus();

	claptrap2.attack(claptrap1.getName());
	claptrap1.takeDamage(claptrap2.getAttackDamage());
	claptrap1.takeDamage(50);
	claptrap1.beRepaired(40);
	std::cout << std::endl;

	claptrap1.displayStatus();
	claptrap2.displayStatus();
	std::cout << std::endl;

	claptrap2.setAttackDamage(5);
	for (int idx = 0; idx < 10; idx++)
	{
		claptrap2.attack(claptrap1.getName());
		claptrap1.takeDamage(claptrap2.getAttackDamage());
	}
	claptrap1.beRepaired(10);
	claptrap1.displayStatus();
	claptrap2.displayStatus();
	
	return 0;
}
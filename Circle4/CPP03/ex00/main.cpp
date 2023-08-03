#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST1----------" << std::endl;
	{
		ClapTrap claptrap1("one");
		ClapTrap claptrap2("two");

		claptrap1.displayStatus();
		claptrap2.displayStatus();

		claptrap2.attack(claptrap1.getName());
		claptrap1.takeDamage(claptrap2.getAttackDamage());
		claptrap1.beRepaired(40);

		claptrap1.displayStatus();
		claptrap2.displayStatus();
	}
	std::cout << std::endl;
	std::cout << "----------TEST2----------" << std::endl;
	{
		ClapTrap claptrap1("one");
		ClapTrap claptrap2("two");

		claptrap2.setAttackDamage(1);
		for (int idx = 0; idx < 10; idx++)
		{
			claptrap2.attack(claptrap1.getName());
			claptrap1.takeDamage(claptrap2.getAttackDamage());
		}
		claptrap1.beRepaired(10);
		claptrap2.attack(claptrap1.getName());
		claptrap1.takeDamage(claptrap2.getAttackDamage());
		claptrap1.displayStatus();
		claptrap2.displayStatus();
	}
	return 0;
}
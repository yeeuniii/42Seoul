#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST1----------" << std::endl;
	{
		ScavTrap	scavtrap1("one");
		ScavTrap	scavtrap2("two");

		scavtrap1.attack(scavtrap2.getName());

		scavtrap1.guardGate();
		scavtrap1.guardGate();
	}
	std::cout << std::endl;
	std::cout << "----------TEST2----------" << std::endl;
	// virtual 키워드 사용이유 예제
	{
		ClapTrap	*one = new ScavTrap;

		one->attack("two");
		delete one;
	}
	return 0;
}
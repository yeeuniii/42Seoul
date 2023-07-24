#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger!\n"
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!\n"
		<< "I want to speak to the manager now." << std::endl;
}

void	Harl::displayInvalid(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int		Harl::getIndex(std::string level)
{
	if (level == "DEBUG")
		return 0;
	if (level == "INFO")
		return 1;
	if (level == "WARNING")	
		return 2;
	if (level == "ERROR")
		return 3;
	return -1;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*harl_functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		index = getIndex(level);

	if (index == -1)
	{
		displayInvalid();
		return ;
	}
	(this->*harl_functions[index])();
}
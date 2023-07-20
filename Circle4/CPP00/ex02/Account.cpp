#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account()
{
	this->_accountIndex = _nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index" << this->_accountIndex
			<< ";amount:" << this->_amount 
			<< ";created" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index" << this->_accountIndex
			<< ";amount:" << this->_amount 
			<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index" << this->_accountIndex
			<< ";amount:" << this->_amount 
			<< ";closed" << std::endl;
}

void	Account::_displayTimestamp()
{
	time_t		timer = time(NULL);
	struct tm	*t = localtime(&timer);

	std::cout << "[" << t->tm_year + 1900
			<< t->tm_mon + 1
			<< t->tm_mday
			<< "_" << t->tm_hour
			<< t->tm_min
			<< t->tm_sec << "]"; 
}

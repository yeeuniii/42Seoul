#include "Account.hpp"

int	main(void)
{
	Account	account1(3);
	Account	account2(7);

	Account::displayAccountsInfos();
	account1.displayStatus();
	account1.makeDeposit(47);
	Account::displayAccountsInfos();
	account1.displayStatus();

	account1.makeWithdrawal(51);
	account1.makeWithdrawal(50);
	account2.makeWithdrawal(3);

	Account::displayAccountsInfos();
	account1.displayStatus();
	account2.displayStatus();
	return 0;
}

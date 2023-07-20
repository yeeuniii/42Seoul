#include "Account.hpp"

int	main(void)
{
	Account	account1(3);
	Account	account2(7);

	Account::displayAccountsInfos();
	account1.displayStatus();
	return 0;
}

/* Account.hpp */ 

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


	public:

// 	typedef Account		t;

	static int	getNbAccounts( void ); /* */
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); /* 총 계좌 정보 표시 함수 */

 	Account( int initial_deposit ); /* 생성자 - 초기 입금값 설정 */
	~Account( void ); /* 소멸자 */

// 	void	makeDeposit( int deposit ); /* */
// 	bool	makeWithdrawal( int withdrawal ); /* */
// 	int		checkAmount( void ) const; /* */
	void	displayStatus( void ) const; /* 한개 계좌 정보 표시 함수 */


private:

	static int	_nbAccounts; /* (nb = number) 계좌 수 */
	static int	_totalAmount; /* 총 액수 */
	static int	_totalNbDeposits; /* 총 입금횟수 */
	static int	_totalNbWithdrawals; /* 총 출금횟수 */

	static void	_displayTimestamp( void ); /* 타임스탬프 보여주는 함수 */

	int				_accountIndex; /* 계좌 인덱스 */
	int				_amount; /* 액수, 금액 */
	int				_nbDeposits; /* 입금 횟수*/
	int				_nbWithdrawals; /* 출금 횟수 */

	Account( void ); /* 생성자 */

};


#endif /* __ACCOUNT_H__ */
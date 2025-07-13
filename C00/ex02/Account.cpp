#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	_displayTimestamp(void)
{
	// TO IMPLEMENT
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "TIMESTAMP "
		<< "accounts" << ":" << getNbAccounts() << ";"
		<< "total" << ":" << getTotalAmount() << ";"
		<< "deposits" << ":" << getNbDeposits() << ";"
		<< "withdrawls" << ":" << getNbWithdrawals()
	<< std::endl;  
}

Account::Account(void)
{
	this->_accountIndex = _nbAccounts % 8;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::Account(int inital_deposit)
{
	this->_accountIndex = _nbAccounts % 8;
	this->_amount = inital_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::~Account(void)
{
	std::cout << "TIMESTAMP "
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->_amount << ";"
		<< "closed"
	<< std::endl;  
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	std::cout << "TIMESTAMP "
		<< "index" << ":" << this->_accountIndex << ";"
		<< "p_amount" << ":" << this->checkAmount() << ";"
		<< "deposits" << ":" << deposit << ";"
		<< "amount" << ":" << this->checkAmount() + deposit << ";"
		<< "nb_deposits" << ":" << this->_nbDeposits
	<< std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->checkAmount() - withdrawal <= 0)
	{
		std::cout << "TIMESTAMP "
			<< "index" << ":" << this->_accountIndex << ";"
			<< "p_amount" << ":" << this->_amount << ";"
			<< "withdrawal" << ":" << withdrawal << ";"
			<< "refused"
		<< std::endl;
		return (false);
	}
	std::cout << "TIMESTAMP "
		<< "index" << ":" << this->_accountIndex << ";"
		<< "p_amount" << ":" << this->checkAmount() << ";"
		<< "amount" << ":" << this->checkAmount() - withdrawal << ";"
		<< "nb_withdrawals" << ":" << this->_nbWithdrawals
	<< std::endl;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	return (this->_amount -= withdrawal);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	std::cout << "TIMESTAMP "
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->checkAmount() << ";"
		<< "depsits" << ":" << this->_nbDeposits << ";"
		<< "withdrawals" << ":" << this->_nbWithdrawals
	<< std::endl;
}

/**
 * Account.cpp
 * This file implements the Account class, which simulates a bank account system.
 * It includes methods for creating accounts, making deposits and withdrawals,
 */
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * getNbAccounts - Returns the number of accounts.
 */
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

/**
 * getTotalAmount - Returns the total amount of all accounts.
 */
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

/**
 * getNbDeposits - Returns the total number of deposits made.
 */
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

/**
 * getNbWithdrawals - Returns the total number of withdrawals made.
 */
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/**
 * _displayTimestamp - Displays the current timestamp.
 */
void	Account::_displayTimestamp(void)
{
	char buff[32];
	std::time_t	now = std::time(NULL);
	std::tm *local_time = std::localtime(&now);

	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", local_time);
    std::cout << buff;
}

/**
 * displayAccountsInfos - Displays the total number of accounts, total amount,
 *                        total deposits, and total withdrawals.
 */
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts" << ":" << getNbAccounts() << ";"
		<< "total" << ":" << getTotalAmount() << ";"
		<< "deposits" << ":" << getNbDeposits() << ";"
		<< "withdrawals" << ":" << getNbWithdrawals()
	<< std::endl;  
}

/**
 * Account - Default constructor.
 */
Account::Account(void)
{
	this->_accountIndex = _nbAccounts % 8;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->_amount << ";"
		<< "created"
	<< std::endl;  
}
/*
 * Account - Constructor with initial deposit.
 * @initial_deposit: The initial deposit amount.
 */
Account::Account(int inital_deposit)
{
	this->_accountIndex = _nbAccounts % 8;
	this->_amount = inital_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->_amount << ";"
		<< "created"
	<< std::endl;  
}

/**
 * Account - Destructor.
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->_amount << ";"
		<< "closed"
	<< std::endl;  
}

/**
 * makeDeposit - Adds a deposit to the account.
 * @deposit: The amount to deposit.
 */
void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "p_amount" << ":" << this->checkAmount() << ";"
		<< "deposit" << ":" << deposit << ";"
		<< "amount" << ":" << this->checkAmount() + deposit << ";"
		<< "nb_deposits" << ":" << this->_nbDeposits
	<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

/**
 * makeWithdrawal - Withdraws an amount from the account.
 * @withdrawal: The amount to withdraw.
 * Return: true if the withdrawal was successful, false otherwise.
 */
bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->checkAmount() - withdrawal <= 0)
	{
		_displayTimestamp();
		std::cout
			<< "index" << ":" << this->_accountIndex << ";"
			<< "p_amount" << ":" << this->_amount << ";"
			<< "withdrawal" << ":" << "refused"
		<< std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "p_amount" << ":" << this->checkAmount() << ";"
		<< "withdrawal" << ":" << withdrawal << ";"
		<< "amount" << ":" << this->checkAmount() - withdrawal << ";"
		<< "nb_withdrawals" << ":" << this->_nbWithdrawals
	<< std::endl;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

/**
 * checkAmount - Returns the current amount in the account.
 * Return: The current amount.
 */
int	Account::checkAmount(void) const
{
	return (this->_amount);
}

/**
 * displayStatus - Displays the account status including index, amount,
 *                 number of deposits, and number of withdrawals.
 */
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index" << ":" << this->_accountIndex << ";"
		<< "amount" << ":" << this->checkAmount() << ";"
		<< "depsits" << ":" << this->_nbDeposits << ";"
		<< "withdrawals" << ":" << this->_nbWithdrawals
	<< std::endl;
}

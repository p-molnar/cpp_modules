#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts;
	_amount = 0;
	_amount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits += deposit > 0;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += deposit > 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		_nbWithdrawals += withdrawal > 0;
		Account::_totalNbWithdrawals += withdrawal > 0;

		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << _amount << ';';
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(0);
	struct tm ltime = *localtime(&now);

	std::cout << '[';
	std::cout << 1900 + ltime.tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltime.tm_mon;
	std::cout << ltime.tm_mday;
	std::cout << '_';
	std::cout << std::setw(2) << std::setfill('0') << ltime.tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltime.tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltime.tm_sec;
	std::cout << "] ";
}

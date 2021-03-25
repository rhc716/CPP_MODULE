/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroh <hroh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:23:18 by hroh              #+#    #+#             */
/*   Updated: 2021/03/25 17:12:52 by hroh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	//[19920104_091532] index:5;amount:0;created
	this->_accountIndex = this->_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_checkAmountCount = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:0;";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};

Account::Account( int initial_deposit )
{
	//[19920104_091532] index:4;amount:1234;created
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
};

Account::~Account( void )
{
	//[19920104_091532] index:4;amount:1245;closed
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	this->_nbAccounts--;
};

int		Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
};

int		Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
};

int		Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
};

int		Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
};

void	Account::_displayTimestamp( void )
{
	//"[19920104_091532] "
	time_t temp;
    struct tm* timeinfo;

    time(&temp);
    timeinfo = localtime(&temp);
	std::cout << "[";
	std::cout << timeinfo->tm_year + 1900 << std::setfill('0');
	std::cout << std::setw(2) << timeinfo->tm_mon + 1;
	std::cout << std::setw(2) << timeinfo->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << timeinfo->tm_hour;
	std::cout << std::setw(2) << timeinfo->tm_min;
	std::cout << std::setw(2) << timeinfo->tm_sec;
	std::cout << "] ";
};

void	Account::displayAccountsInfos( void )
{
	//[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	//[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
};

bool	Account::makeWithdrawal( int withdrawal )
{
	//[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
	//[19920104_091532] index:0;p_amount:47;withdrawal:refused
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	return (true);
};

int		Account::checkAmount( void ) const
{
	this->_checkAmountCount++;
	return (0);
};

void	Account::displayStatus( void ) const
{
	//[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
	Account::checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();

    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals;
    std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;

    _amount = initial_deposit;
    _totalAmount += _amount;

    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}



void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";

    _amount += deposit;
    _totalAmount += deposit;

    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";

    _nbDeposits += 1;
    _totalNbDeposits += 1;

    std::cout << "nb_deposits:" << _nbDeposits;

    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:";

    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";";
        std::cout << "amount:" << _amount << ";";

        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << "nb_withdrawals:" << _nbWithdrawals;
        std::cout << std::endl;
        return (true);
    }
    else
    {
        std::cout << "refused";
        std::cout << std::endl;
        return (false);
    }

}

int		Account::checkAmount( void ) const
{
    std::cout << "check Amount" << std::endl;
    return 0;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals;
    std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t currentTime;
    std::tm* localTime;

    std::time(&currentTime);
    localTime = std::localtime(&currentTime);

    //UTC 시간
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    std::cout << "[" << buffer << "] ";
}



Account::Account( void )
{
    _accountIndex = 0;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

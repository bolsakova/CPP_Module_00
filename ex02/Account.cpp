#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 8;
int Account::_totalAmount = 20049;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
	std::time_t t = std::time(0);		// получить текущее время с 1 января 1970 года (Unix timestamp)
	std::tm* now = std::localtime(&t);	// преобразовать в структуру tm, котоая содержит год, месяц, день, час, минуту, секунду
	// std::setfill('0') - если число меньше заданной ширины, заполняет нулями слева
	// std::setw(2) - устанавливает ширину поля в 2 символа
	std::cout	<< "["
				<< (now->tm_year + 1900)									// год полный
				<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)	// месяц (2 цифры)
				<< std::setfill('0') << std::setw(2) << now->tm_mday		// день (2 цифры)
				<< "_"
				<< std::setfill('0') << std::setw(2) << now->tm_hour		// час (2 цифры)
				<< std::setfill('0') << std::setw(2) << now->tm_min			// минута (2 цифры)
				<< std::setfill('0') << std::setw(2) << now->tm_sec			// секунда (2 цифры)
				<< "] ";
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return _totalAmount;
}
int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// to learn
Account::Account( int initial_deposit ) {

}
Account::~Account( void ) {
	
}

void	Account::makeDeposit( int deposit ) {

}
bool	Account::makeWithdrawal( int withdrawal ) {

}
int		Account::checkAmount( void ) const {

}
void	Account::displayStatus( void ) const {
	
}

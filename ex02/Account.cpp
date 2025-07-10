#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// временная метка
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

// конструктор - функция создания объекта
//
// ЧТО ПРОИСХОДИТ?
// 1. выделяется память для всех переменных объекта
// 2. вызывается конструктор
// 3. инициализируются переменные объекта
//
// ЧТО "КОНСТРУИРУЕТСЯ"?
// 1. переменные экземпляра (для каждого объекта свои): 
// 		_accountIndex (номер аккаунта - 0,1,2,3),
//		_amount (сумма на счету этого аккаунта),
// 		_nbDeposits (кол-во пополнений этого аккаунта),
// 		_nbWithdrawals (кол-во снятий с этого аккаунта)
// 2. статистические переменные (общие для всех объектов):
//		_nbAccounts (общее кол-во аккаунтов)
//		_totalAmount (общая сумма во всех аккаунтах)
//		_totalNbDeposits (общее кол-во всех пополнений)
//		_totalNbWithdrawals (общее кол-во всех снятий)
Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	// вывод сообщения со всей информацией
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}
// Деструктор - специальная функция, к-рая автоматически вызывается при уничтожении объекта
// 
// ЧТО ПРОИСХОДИТ ПРИ УНИЧТОЖЕНИИ ОБЪЕКТА?
// 1. Автоматически вызывается деструктор
// 2. выаолняется код деструктора
// 3. освобождается память объекта
// 
// ЧТО "ДЕСТРУКТИРУЕТСЯ" (УНИЧТОЖАЕТСЯ)?
// - НЕ уничтожается: статистические переменные
// - уничтожается: переменные конкретного объекта
// 
// ПОРЯДОК УНИЧТОЖЕНИЯ
// - LIFO (Last In, First Out)
// - последний созданный, первый уничтожается!
//
// ЗАЧЕМ НУЖЕН ДЕСТРУКТОР?
// 1. Очистка ресурсов:
//		- закрытие файлов
//		- освобождение памяти
//		- закрытие сетевых соединений
// 2. Логирование:
//		- запись в лог об уничтожении объекта
//		- отладочная информация
// 3. Обновление статистики:
//		- уменьшение счётчиков
//		- обновление общих данных
Account::~Account( void ) {
	// вывод сообщения со всей информацией
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

// пополняет счёт
// 		p_amount - предыдущая сумма (previous amount)
// 		deposit - размер депозита
// 		amount - новая сумма
// 		nb_deposits - количество депозитов для этого аккаунта
void	Account::makeDeposit( int deposit ) {
	// вывести timestamp и начальную информацию
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount; // показать старую сумму
	// обновить данные
	_amount += deposit;			// увеличить сумму аккаунта
	_nbDeposits++;				// увеличить счётчик депозитов аккаунта
	_totalAmount += deposit;	// увеличить общую сумму
	_totalNbDeposits++;			// увеличить общий счётчик депозитов
	// вывести остальную информацию
	std::cout	<< ";deposit:" << deposit
				<< ";amount:" << _amount		// показать новую сумму
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ) {
	// вывести timestamp и начальну информацию
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;		// показать старую сумму
	// проверить: хватает ли денег?
	if (withdrawal > _amount) {
		// НЕ хватает денег - отказ
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	// хватает денег - снимаем
	// обновить переменные только при успешном снятии
	_amount -= withdrawal;			// уменьшаем сумму аккаунта
	_nbWithdrawals++;				// увеличиваем счетчик снятий аккаунта
	_totalAmount -= withdrawal;		// уменьшаем общую сумму
	_totalNbWithdrawals++;			// увеличиваем общий счётчик снятий
	// вывести информацию об успешном снятии
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount		// показать новую сумму
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
// возвращает текущую сумму на счету
int		Account::checkAmount( void ) const {
	return _amount;
}
// выводит информацию о состоянии аккаунта
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string>
#include "account.h"

int Account::accno_generator = 1000;

Account::Account(const std::string &name, float balance): name(name), balance(balance)
{
	accno = ++ accno_generator;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

const std::string Account::get_name() const
{
	return name;
}
float Account::get_balance() const
{
	return balance;
}
int Account::get_accno() const
{
	return accno;
}

void Account::accumulate_interest()
{
}
void Account::withdraw(float amount)
{
	if(amount < balance)
	{
		balance -= amount;
	}
	else
	{
		throw std::out_of_range("Insufficient balance.");

	}
}
void Account::deposit(float amount)
{
	balance += amount;
}

float Account::get_interest_rate() const
{
	return 0.0f;
}

Account::~Account()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

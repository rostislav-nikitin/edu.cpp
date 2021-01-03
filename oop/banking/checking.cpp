#include <iostream>
#include <string>
#include "checking.h"

//c++11:
/*Checking::Checking(const std::string &name, float balance)
	: Account(name, balance)
{
}*/

Checking::Checking(const std::string &name, float balance, float minimum_balance) : Account::Account(name, balance), minimum_balance(minimum_balance)
{
}

void Checking::withdraw(float amount)
{
	if((balance - amount) < minimum_balance)
	{
		throw std::out_of_range("Balance should not fall below 50");
	}

	Account::withdraw(amount);
}

float Checking::get_minimum_balance() const
{
	return minimum_balance;
}

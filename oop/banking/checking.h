#pragma once

#include <string>
#include "account.h"

class Checking: public Account
{
		float minimum_balance;
	public:
		//c++17 next line ask to compiler to implicitly inherit all the constructors from the base in the child class
		//using Account::Account;
		//c++11:Checking(const std::string &name, float balance);
		Checking(const std::string &name, float balance, float minimum_balance);
		void withdraw(float amount) final override;
		float get_minimum_balance() const;
};

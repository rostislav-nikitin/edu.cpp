#include "transaction.h"
#include <iostream>

void transact(Account *ptr_account)
{
	std::cout << "Transaction started" << std::endl;
	std::cout << "Initial balance: " << ptr_account->get_balance() << std::endl;
	ptr_account->deposit(100);
	ptr_account->accumulate_interest();
	/*if(typeid(*ptr_account) == typeid(Checking))
	{
		Checking *ptr_checking = static_cast<Checking*>(ptr_account);
		std::cout << "Minimum balance of Checking:" << ptr_checking->get_minimum_balance() << std::endl;
	}*/
	Checking *ptr_checking = dynamic_cast<Checking*>(ptr_account);
	if(ptr_checking != nullptr)
	{
		std::cout << "Minimum balance of Checking:" << ptr_checking->get_minimum_balance() << std::endl;
	}
	ptr_account->withdraw(170);
	std::cout << "Interest rate: " << ptr_account->get_interest_rate() << std::endl;
	std::cout << "Final balance: " << ptr_account->get_balance() << std::endl;
}


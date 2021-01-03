// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "savings.h"
#include "checking.h"
#include "transaction.h"

using namespace std;

int main()
{
	//Savings acc{"Bob", 100, 0.03f};
	Checking acc {"Bob", 100, 50};
	//Account *acc = new Savings {"Bob", 100, 0.05f};
	transact(&acc);
	/*cout << "Initial balance:" << acc.get_balance() << endl;

	acc.deposit(200);
	acc.accumulate_interest();
	acc.withdraw(380);

	cout << "Balance: " << acc.get_balance() << endl;*/
	//delete acc;
	
	Account *acc2 = &acc;
	cout << typeid(acc2).name() << endl;
	cout << typeid(*acc2).name() << endl;

	return 0;
}

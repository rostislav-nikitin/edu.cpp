// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include "account.h"

class Savings final: public Account
{
		float rate;
	public:
		Savings(const std::string &name, float balance, float rate);
		~Savings();
		float get_interest_rate() const override;
		void accumulate_interest() override;
};

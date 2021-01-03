#pragma once
#include <string>

class Account
{
		std::string name;
		int accno;
		static int accno_generator;

	protected:
		float balance;

	public:
		Account(const std::string &name, float balance);
		virtual ~Account();
		const std::string get_name() const;
		float get_balance() const;
		int get_accno() const;

		virtual void accumulate_interest();
		virtual void withdraw(float amount)=0;
		void deposit(float amount);

		virtual float get_interest_rate() const;
};

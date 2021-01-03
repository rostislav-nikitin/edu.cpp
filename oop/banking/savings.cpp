// Single-line comment
/*
 * Multiple line comment
 */

#include <iostream>
#include <string>
#include "savings.h"

Savings::Savings(const std::string &name, float balance, float rate) : Account(name, balance), rate(rate)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Savings::~Savings()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

float Savings::get_interest_rate() const
{
	return rate;
}

void Savings::accumulate_interest()
{
	balance += (balance * rate);
}

#pragma once
#include <iostream>
#include "BankAccount.hpp"
class LimitedBankAccount : public BankAccount
{
private:
	double limit;
public:
	LimitedBankAccount(double limitAmmount);
	void setLimit(double LimitAmmount);
	double getLimit();
};
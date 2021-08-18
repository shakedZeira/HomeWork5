#pragma once
#include <iostream>
using namespace std;
class BankAccount
{
protected:
	string bankName;
	double balance;

public:
	BankAccount(string name)
	{
		bankName = name;
		balance = 0;
	}
	string getName();
	double getbalance();
	double withdraw(double amount);
	void deposit(double);
};
#pragma once
#include <iostream>
#include "BankAccount.hpp"
using namespace std;

class overDraftAccount : public BankAccount
{
private:
	double maxOverDraft;
public:
	overDraftAccount(double max);
	double GetMax();
};
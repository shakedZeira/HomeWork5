#include "BankAccount.hpp"
#include "LimitedBankAccount.hpp"
#include "overDraftAccount.hpp"
#include <list>

string BankAccount::getName()
{
	return bankName;
}
double BankAccount::getbalance()
{
	return balance;
}
double BankAccount::withdraw(double amount)
{
	if (balance - amount < 0)
	{
		cout << "cant withdarw! , not enough money!" << endl;
		return balance;
	}
	else
	{
		return balance - amount;
	}
}
void BankAccount::deposit(double amount)
{
	balance = balance + amount;
}
LimitedBankAccount::LimitedBankAccount(double limitammount):BankAccount(bankName)
{
	limit = limitammount;
}
void LimitedBankAccount::setLimit(double limitammount)
{
	limit = limitammount;
}
double LimitedBankAccount::getLimit()
{
	return limit;
}

overDraftAccount::overDraftAccount(double maxLimit) :BankAccount(bankName)
{
	maxOverDraft = maxLimit;
}
double overDraftAccount::GetMax()
{
	return maxOverDraft;
}

void createBank()
{
	list<BankAccount> regularAccounts;
	list<LimitedBankAccount> limitedAccounts;
	list<overDraftAccount> overDraftAccounts;
	int initialchoice;
	int firstchioce;
	cout << "Welcome to MagshiBank" << endl;
	cout << "press 1 to add a new account" << endl;
	cout << "press 2 to make a transaction from an existing account" << endl;
	cout << "press 3 to list all of the accounts (type,balance)" << endl;
	cout << "press 4 to exit" << endl;
	cin >> initialchoice;
	while (initialchoice != 4)
	{
		if (initialchoice == 1)
		{
			cout << "what kind of account you will want to create? " << endl;
			cout << "press 1 for regular account" << endl;
			cout << "press 2 for limited bank account" << endl;
			cout << "press 3 for overDarftAccount" << endl;
			cin >> firstchioce;
			if (regularAccounts.size() + limitedAccounts.size() + overDraftAccounts.size() < 20)
			{
				cout << "please enter the name of the account owner: " << endl;
				string name;
				cin >> name;
				if (firstchioce == 1)
				{
					BankAccount account = BankAccount(name);
					regularAccounts.push_back(account);

				}
				else if (firstchioce == 2)
				{
					double limitAmmount;
					cout << "please enter the limit you want : " << endl;
					cin >> limitAmmount;
					LimitedBankAccount LimitedAccount{limitAmmount};
					limitedAccounts.push_back(LimitedAccount);
				}
				else if(firstchioce ==3)
				{
					double maxLimit;
					cout << "please enter the Max limit you want : " << endl;
					cin >> maxLimit;
					overDraftAccount overAccount{maxLimit};
					overDraftAccounts.push_back(overAccount);
				}
				else
				{
					cout << "wrong choice!! , please re enter" << endl;
				}
			}
		}
		if (initialchoice == 2)
		{
			cout << "please enter the name of the account owner: " << endl;
			string ownername;
			cin >> ownername;
			list<BankAccount>::iterator RegularIterator;
			for (RegularIterator = regularAccounts.begin(); RegularIterator != regularAccounts.end(); RegularIterator++)
			{
				string RegularNameFinder = RegularIterator->getName();
				if (ownername == RegularNameFinder)
				{
					//to check
					BankAccount* account;
					account = &*RegularIterator;
					cout << "Welcome [" <<ownername<< "] !" << endl;
					int secondchioce;
					cout << "press 1 to deposit money" << endl;
					cout << "press 2 withdraw money" << endl;
					cout<<"press 3 to show current balance"<<endl;
					cout << "press 4 to get back to the main menu" << endl;
					cin >> secondchioce;
					if (secondchioce == 1)
					{
						double depositAmount;
						cout << "please enter how much you want to deposit: " << endl;
						cin >> depositAmount;
						account->deposit(depositAmount);
					}
					else if (secondchioce == 2)
					{
						double withdrawAmount;
						cout << "please enter how much you want to withdarw: " << endl;
						cin >> withdrawAmount;
						account->withdraw(withdrawAmount);
					}
					else if(secondchioce == 3)
					{
						cout <<"Current Regular account Balance: "<< account->getbalance() << endl;
						list<LimitedBankAccount>::iterator LimitedIterator;
						string LimitedNameFinder;
						list<overDraftAccount>::iterator OverdraftIterator;
						string OverdraftNameFinder;
						for (LimitedIterator = limitedAccounts.begin(); LimitedIterator != limitedAccounts.end(); LimitedIterator++)
						{
							LimitedNameFinder = LimitedIterator->getName();
							if (ownername == LimitedNameFinder)
							{
								LimitedBankAccount* LimitedAccount;
								LimitedAccount =  &*LimitedIterator;
								cout << "Current Limited account balance:  " << LimitedAccount->getbalance() << endl;
							}
						}
						for (OverdraftIterator = overDraftAccounts.begin(); OverdraftIterator != overDraftAccounts.end(); OverdraftIterator++)
						{
							OverdraftNameFinder = OverdraftIterator->getName();
							if (ownername == OverdraftNameFinder)
							{
								overDraftAccount* OverdraftAccount;
								OverdraftAccount = &*OverdraftIterator;
								cout << "Current Overdraft account balance:  " << OverdraftAccount->getbalance() << endl;
							}
						}
					}
					else if(secondchioce == 4)
					{
						cout << "Returning to the main menu..." << endl;
					}
					else
					{
						cout << "wrong choice, please re enter" << endl;
					}
				}
			}
		}
		else if(initialchoice ==3)
		{
			list<BankAccount>::iterator RegularIterator2;
			for (RegularIterator2 = regularAccounts.begin(); RegularIterator2 != regularAccounts.end(); RegularIterator2++)
			{
				cout <<"Account owner: " << RegularIterator2->getName();
				cout << " Account Type: Regular ";
				cout << " Account Balance: " << RegularIterator2->getbalance();
			}
			list<LimitedBankAccount>::iterator LimitedIterator2;
			for (LimitedIterator2 = limitedAccounts.begin(); LimitedIterator2 != limitedAccounts.end(); LimitedIterator2++)
			{
				cout << "Account owner: " << LimitedIterator2->getName();
				cout << " Account Type: Limited ";
				cout << " Account Balance: " << LimitedIterator2->getbalance();
			}
			list<overDraftAccount>::iterator OverdraftIterator2;
			for (OverdraftIterator2 = overDraftAccounts.begin(); OverdraftIterator2 != overDraftAccounts.end(); OverdraftIterator2++)
			{
				cout << "Account owner: " << OverdraftIterator2->getName();
				cout << " Account Type: OverDraft ";
				cout << " Account Balance: " << OverdraftIterator2->getbalance();
			}
		}
	}
}
int main()
{
	createBank();
}
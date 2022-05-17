#include <stdlib.h>
#include <iostream>

#include "account.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

Account::Account(double newBalance) 
{
	if (newBalance > 0)
	{
		balance = newBalance;
	}
	else
	{
		cerr << "Illegal Balance" << endl << endl;
	}
}
//----------------------------------------------------------------------------------------------------

double Account::getBalance() const 
{
	return balance;
}
//----------------------------------------------------------------------------------------------------

void Account::setBalance(double newBalance)
{
	if (newBalance > 0)
	{
		balance = newBalance;
	}
	else
	{
		cerr << "Illegal Balance" << endl << endl;
	}
}
//----------------------------------------------------------------------------------------------------

double Account::deposit(double amount)
{
	if (amount >= 0)
	{
		balance = balance + amount;
	}
	else
	{
		cerr << "Illegal deposit" << endl << endl;
	}
	return balance;

	
}
//----------------------------------------------------------------------------------------------------

double Account::withdrawal(double amount)
{
	if (amount > 0)
	{
		balance = balance - amount;
	}
	else
	{
		cerr << "Illegal withdrawal" << endl << endl;
	}
	return balance;
}
//----------------------------------------------------------------------------------------------------

double Account::transferFrom(char* accountTrans, double moneyTrans)
{
	accountTrans->balance = accountTrans->balance - moneyTrans;
	this->balance = this->balance + moneyTrans;
	return balance;
}


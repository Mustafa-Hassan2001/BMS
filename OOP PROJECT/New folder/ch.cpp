#include "checking.h"

Checking::Checking(double newBalance): Account(balance)
{
  
   Account::setBalance(balance);
}

double Checking::withdrawal(double amount)
{
   if (  Account::getBalance() - amount >= 0)
   {
	  Account::withdrawal(amount);
   }
   else 
   {
	  cout << "Not enough funds in checking for transaction" << endl << endl;
   } 
}

double Checking::deposit(double amount)
{
   Account::deposit(amount);
}


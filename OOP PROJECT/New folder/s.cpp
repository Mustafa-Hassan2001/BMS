#include <iostream>
#include <stdlib.h>

#include "savings.h"



//--------------------------------------------------------------------------------------

Savings::Savings(double balance, double interestRate) : Account(balance)
{
   Account::setBalance(balance);
   setRate(interestRate);
}

//--------------------------------------------------------------------------------------

void Savings::setRate(double interest)
{
   interestRate = interest;
   interestRate = (interestRate/100)/12; // to get interest in monthly format
}
//--------------------------------------------------------------------------------------

double Savings::getRate() const
{
   return interestRate;
} 

//--------------------------------------------------------------------------------------

double Savings::withdrawal(double amount)
{
   if (  (Account::getBalance() - amount) >= 0)
   {
	  Account::withdrawal(amount);
	  Account::setBalance(Account::getBalance() + ( interestRate * Account::getBalance() ) );
   }
   else 
   {
	  cerr << "Not enough funds in savings for transaction" << endl << endl;
   } 
}

//--------------------------------------------------------------------------------------

double Savings::deposit(double amount)
{
   Account::deposit(amount);
   Account::setBalance(Account::getBalance() + ( interestRate * Account::getBalance() ) );
}


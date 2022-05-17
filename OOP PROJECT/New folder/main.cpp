#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

#include "ch.h"
#include "s.h"
//#include "moneymarket.h"
//#include "certificatedeposit.h"

using namespace std;

void main
{
//declare all 4 types, call withdrawl, deposit, 
//and transfer from on each account

Checking Brad (200);
Savings Brad (100);

Checking Jessi (10000);
Savings Jessi (10);

cout << "Brad's Checking balance: " << Brad->Checking::getBalance() << endl << endl;

cout << "Brad's Saving balance: " << Brad->Saving::getBalance() << endl << endl;

cout << "Jessi's Checking balance: " << Jessi->Checking::getBalance() << endl << endl;

cout << "Jessi's Savings balance: " << Jessi->Savings::getBalance() << endl << endl;
}



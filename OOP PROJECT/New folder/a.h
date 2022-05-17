#pragma once
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Accounts
{
public:
    Accounts();
    ~Accounts();
    virtual void WithDraw(int) = 0;
    virtual void Deposit(int, string, int, int) = 0;//Also can be named as add Account
    virtual void Balance() {};
    virtual void DeleteAccount(int)=0;
    virtual int getAccountsNumber()=0;
};
//Definning classes methods
Accounts::Accounts()
{
    cout << "\nThe Accounts class started\n";
    //no need to initialize vectors.They work perfect without initializing.C++ has done work for it
}
Accounts::~Accounts()
{
    cout << "\nThe Accounts class Ended\n";
}

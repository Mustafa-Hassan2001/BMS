#include <iostream>
#include "Employee_end.h"
#include "customer_end2.h"
#include "ATM.h"
#include "new.h"
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//class Bank{
//int banking() = 0;	
//};

int main(){
	cout<<"\n\t\t***************WELCOME TO WITHOUT MY INTEREST BANK*************\n\n";
	
	string name,id,address;
	string username,password;
	
    cout<<"\n\n\t\t\t******Signup******"<<endl;
	cout<<"\n\t\t\tEnter new username: ";
	cin>>username;
	cout<<"\t\t\tEnter new password: ";
	cin>>password;
	cout<<"\t\t\tYour new id is creating please wait";
	for(int i=0;i<6;i++){
		cout<<".";
		Sleep(500);
	}
	cout<<"\n\t\t\tYour id created successfully";
	Sleep(2000);

	system("CLS");
	string usrn,pswd;
	
start:
	cout<<"\n\n\t\t\t   LOGIN"<<endl;
	cout<<"\t\t\tConfirm username: ";
	cin>>usrn;
	cout<<"\t\t\tConfirm password: ";
	cin>>pswd;
	system("cls");
	if(usrn==username&&pswd==password){
    cout << "\n\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t>> BANK MANAGEMNET SYSTEM <<" << endl;
    cout << "\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t 1. Employee End" << endl;
    cout << "\t\t\t\t\t 2. ATM" << endl;
    cout << "\t\t\t\t\t 3. Customer End" << endl;
    cout << "\t\t\t\t\t 4. Exit" << endl;        
	cout << "\t\t\t\t\t.................................." << endl;
    cout << "\t\t\t\t\t>> Choice Options: [1/2/3] <<" << endl;
    cout << "\t\t\t\t\t.................................." << endl;
    cout << "\t\t\t\t\t Enter Your Choice: "; // Taking the action input
    cin>>opt;
    if(opt==1){
	Employee_management e;
	e.menu();
	}
	else if(opt==2){
	atm a;
	a.add_user();
	}
	else if(opt==3){
	account acc;
	acc.MENU();
	}
	}	
	else if(pswd!=password){
		cout<<"\t\t\tInvaid Password\n"<<endl;
		goto start;
	}
	else if(usrn!=username){
		cout<<"\tInvaid Username\n"<<endl;
		goto start;
	}		

	return 0;
}

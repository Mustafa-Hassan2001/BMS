#include <iostream>
#include "Admin.h"
#include "Employee_end.h"
#include "ATM.h"
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(){
	int opt;
//	cout<<"\n\n\t\t================================================================================="<<endl;
//	cout<<"\n\t\t\t***************WELCOME TO WITHOUT MY INTEREST BANK*************\t\t\n";
//	int opt;
//	string name,id,address;
//	string username,password;
//	
//    cout<<"\n\n\t\t\t\t\t\t******Signup******\t\t\t\t"<<endl;
//	cout<<"\n\t\t\t\t\t\tEnter new username : ";
//	cin>>username;
//	cout<<"\t\t\t\t\t\tEnter new password : ";
//	cin>>password;
//	cout<<"\t\t\t\t\tYour new id is creating please wait";
//	for(int i=0;i<4;i++){
//		cout<<".";
//		Sleep(400);
//	}
//	cout<<"\n\t\t\t\t\tYour id created successfully"<<endl<<endl;
//	cout<<"\t\t=================================================================================";	
//	Sleep(2000);
//
//	system("CLS");
//	string usrn,pswd;
//	
//start:	
//	cout<<"\n\n\t\t================================================================================="<<endl;
//	cout<<"\n\t\t\t\t\t***********ADMIN LOGIN*********"<<endl;
//	cout<<"\n\t\t\t\t\t\t Enter username: ";
//	cin>>usrn;
//	cout<<"\t\t\t\t\t\t Enter password: ";
//	cin>>pswd;
//	cout<<endl;
//	if(usrn==username&&pswd==password){
	account A;
	A.mainpage();
	system("CLS");
	cout<<"\n\n\t\t================================================================================="<<endl;
    cout << "\n\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t>> BANK MANAGEMNET SYSTEM <<" << endl;
    cout << "\t\t\t\t\t-------------------------------" << endl;
    cout << "\t\t\t\t\t 1. Employee End" << endl;
    cout << "\t\t\t\t\t 2. Customer End" << endl;
    cout << "\t\t\t\t\t 3. ATM" << endl;
    cout << "\t\t\t\t\t 4. Exit" << endl;        
	cout << "\t\t\t\t\t.................................." << endl;
    cout << "\t\t\t\t\t>> Choice Options: [1/2/3] <<" << endl;
    cout << "\t\t\t\t\t.................................." << endl;
    cout << "\t\t\t\t\t Enter Your Choice: "; // Taking the action input
    cin>>opt;
    if(opt==1){
//	Employee_end e;
//	e.menu();
	}
	else if(opt==2){
	A.logscreen();
	}
	else if(opt==3){
	atm a;
	a.add_user();
	}
	else if(opt==4){
	cout<<"\n\n\t\t\t\t\tHave a nice day...Thank you!!"<<endl;	
	}	
	cout<<"\n\n\t\t================================================================================="<<endl;
//	char ch;
//	}	
//	else if(pswd!=password){
//		cout<<"\n\t\t\t\t\t\t Invaid Password\n"<<endl;
//		goto start;
//	}
//	else if(usrn!=username){
//		cout<<"\n\t\t\t\t\t\t Invaid Username\n"<<endl;
//		goto start;
//	}		

	return 0;
}



#include "project.h"
#include <iostream>
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

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
	cout<<"\t\t\tEnter username: ";
	cin>>usrn;
	cout<<"\t\t\tEnter password: ";
	cin>>pswd;
	if(usrn==username&&pswd==password){
	system("CLS");
	Bank b;
	b.choice();
	char ch;
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



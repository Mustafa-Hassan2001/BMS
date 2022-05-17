//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<direct.h>
#include<process.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include "ATM.h"
#include "Employee_end.h"
using namespace std;

class account
{
	int accNo;
	char name[50];
	int deposit;
	char type;
public:
	void logscreen();
	void mainpage();
	void createAccount();
	void displayAccount() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retaccNo() const;
	int retdeposit() const;
	char rettype() const;
};


//This FUnction is used to create an Account of User.

void account::createAccount()
{
	system("cls");
	cout<<endl;
	cout<<"\t\t\tPlease enter your Account No. : ";
	cin>>accNo;
	cout<<endl<<endl;
	cout<<"\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<endl;
	cout<<"\t\t\tEnter Type of the Account (C(Current)/S(Savings)) : ";
	cin>>type;
	type=toupper(type);
	while (type != 'S' && type != 'C') {
        cout <<"\t\t\tPlease enter either S or C to avoid data corruption: ";
		cin.clear();
		fflush(stdin);
        cin >> type;
        type = toupper(type);
    }
	cout<<endl;
	cout<<"\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<endl<<endl;
	cout<<"\t\t\tAccount Created..";
}

//This FUnction is used to display an Account of User.

void account::displayAccount() const{
	cout<<"\n\t\t\tAccount No. : "<<accNo;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

//This FUnction is used to Modify an Account of User.

void account::modify(){
	cout<<"\n\t\t\tAccount No. : "<<accNo;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x){
	deposit+=x;
}

void account::draw(int x){
	deposit-=x;
}

void account::report() const{
	cout<<accNo<<setw(10)<<"  "<<name<<setw(10)<<" "<<type<<setw(6)<<"  "<<deposit<<endl;
}

int account::retaccNo() const{
	return accNo;
}

int account::retdeposit() const{
	return deposit;
}

char account::rettype() const{
	return type;
}

void accountDetails(){
	account ac;
	ofstream outFile;
	outFile.open("account.csv",ios::binary|ios::app);
	ac.createAccount();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n){
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.retaccNo()==n){
			ac.displayAccount();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false){
        cout<<"\n\n\t\t\tAccount number does not exist";
    }
		
}

void modifyAccount(int n){
	bool found=false;
	account ac;
	fstream File;
    File.open("account.csv",ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccNo()==n){
			ac.displayAccount();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(account));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

void deleteAccount(int n){
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.csv",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		if(ac.retaccNo()!=n){
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.csv");
	rename("Temp.csv","account.csv");
	cout<<"\n\n\t\tRecord Deleted ..";
}


void displayRecords(){
	system("cls");
	account ac;
	ifstream inFile;
	inFile.open("account.csv",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type        Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account))){
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	account ac;
	fstream File;
    File.open("account.csv", ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retaccNo()==n){
			ac.displayAccount();
			if(option==1){
				//cout<<"\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2){
				//cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<"Sorry !! Insufficience balance..";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t\t\tSuccess... Record Updated Successfully";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tOops! We Couldn't find your record";
}

//To Display Date on Screen

void date(){
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T);
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t\t   Date :: %02d/%02d/%04d\n",tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
}

//To give delay to load Login System

void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

//If Invalid Attempts will exceed the 3 then 

void callExit(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    fflush(stdin);
    printf("You are out of the System.");
    printf("\n\n");
    printf("\t\t\t\t");
    printf("   Press Enter to Continue Exit Program...");
    getchar();
    exit(0);
}

// Mainpage of the Project

void mainpage(){
  int process=0;
  system("cls");
  date();
  cout<<endl;
  printf("\t\t\t\t    ---------------------------\n");
  printf("\t\t\t\t     |BANK MANAGEMENT SYSTEM|\n");
  printf("\t\t\t\t    ---------------------------\n");
  cout<<endl<<endl<<endl;
  printf("\t\t\t\t");
  printf("Prepared By    :");
  printf("   Mustafa Hassan");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("Mini Project    :");
  printf("   Bank Management System");
  printf("\n\n");
  printf("\t\t\t\t");
  printf("\n\n");
  printf("\t\t\t\t    Press Enter to continue......");
  printf("\n\n");
  getchar();
  printf("\t\t\t\tLoading");

  for(process=0;process<25;process++){
    delay(150);
    printf(".");
  }
}

// MenuList of Project


void menulist(){
    char ch,my_git;
	int num;
	
	do{
	system("cls");
	cout<<"\n\n\t\t\t\t==============================\n";
	cout<<"\t\t\t\t|    BANK MANAGEMENT SYSTEM  |";
	cout<<"\n\t\t\t\t==============================\n";

        cout<<endl<<endl;
		cout<<"\t\t\t\t   :: :: MAIN MENU :: ::\n";
        cout<<endl<<endl;
		cout<<"\n\n\t\t\t\t1. Create New Account";
		cout<<"\n\t\t\t\t2. Deposit Amount to Account";
		cout<<"\n\t\t\t\t3. Withdraw Amount from Account";
		cout<<"\n\t\t\t\t4. Balance Enquiry";
		cout<<"\n\t\t\t\t5. Display list of Account holders";
		cout<<"\n\t\t\t\t6. Delete an Account";
		cout<<"\n\t\t\t\t7. Modify the existing Account";
		cout<<"\n\t\t\t\t8. Visit My Website";
		cout<<"\n\t\t\t\t9. Exit";
		cout<<"\n\n\t\t\t\tChoose options:[1/2/3/4/5/6/7/8/9] :: ";
		cin>>ch;

		switch(ch){
		case '1':
			accountDetails();
			break;
		case '2':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			displayRecords();
			break;
		case '6':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deleteAccount(num);
			break;
		 case '7':
		 	system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modifyAccount(num);
			break;
        case '8':
            cout <<"\n\n\t\t\t\tThanks for using Bank Record System.\n\n";
            cout <<"\n\n\n\n\n\t\t\t\tDo you want to visit my Website [Y/N]: ";
            cin >> my_git;
            my_git = toupper(my_git);
            if (my_git == 'Y') {
                system("start https://github.com/Mustafa-Hassan2001");
            }
            break;	
		 case '9':
		 	system("cls");
			cout<<"\n\n\t\t\tThank You.. Visit Again";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
}

//Set Username & Password here for Login System

int logscreen(){
	
  char username[30];
  char password[30];
  int chances = 0;
  int flag = 1;
  
  do{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t");
    printf("Username: ");
    scanf("%s",username);
    printf("\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t\t");
    printf("Password: ");
    scanf("%s",password);
    if(strcmp(username,"Mustafa")==0 && strcmp(password,"Hassan")==0)
      {
        printf("\n\n");
        printf("\t\t\t\t");
        printf("You are accessed to the system!\n\n");
        printf("\t\t\t\t   Press Enter to continue...");
        fflush(stdin);
        getchar();
        menulist();
        system("cls");
        getchar();
        flag =0;
      }
      else
      {
        system("cls");
        chances = chances+1;
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t");
        printf("No. of attempts remain: %d",3-chances);
        fflush(stdin);
        getchar();
        if(chances>=3)
        {

          printf("\t\t\t\t\t\t");
          printf("\n");
          printf("\t\t\t\t");
          printf("   No permission to enter the system!" );
          getchar();
          callExit();
          getchar();
      ;
      }
  } //END OF ELSE
 }
 while(true==1);
}



//Actual Execution Starts here :) Main Function Started

//int main(){
//	int opt;
//	atm a;
//	Employee_management e;
//	mainpage();
//	system("cls");
//	cout<<"\t\t\tPlease Enter Your Choice : ";
//	cin>>opt;
//	if(opt==1)
//	logscreen();
////	if(opt==2) 
////	a.atmUser();
//	if(opt==3)
//	e.menu();
//	return 0;
//}


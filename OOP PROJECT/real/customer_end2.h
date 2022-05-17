#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<windows.h>
#include "account.h"

using namespace std;

class admin{
	int accNo;
	char name[50];
	char city[50];
	int deposit,x;
	double contact;
	double CNIC;
	string statius;
	char type;
public:
	void createAccount();
	void displayAccount() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retaccNo() const;
    int retdeposit() const;
	char rettype() const;
	void menulist();
};


int gen_acc_num(){  			//This FUnction is used to create an Account of User.
     static int s_nID = 1;  
     return s_nID++;    
   }  
   
void admin::createAccount(){
	system("cls");
	cout<<endl;
 	cout<<"\nYour Acount number is: ";  
    x= gen_acc_num();  
    cout<<setw(3)<<setfill('0')<< x <<endl;  
	cout<<endl;
	cout<<"\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<endl;
	cout<<"\t\t\tPlease enter your contact number : ";
	cin>>contact;
	cout<<endl;
	cout<<"\t\t\tPlease enter your CNIC number : ";
	cin>>CNIC;
	cout<<endl;
	cout<<"\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<endl;
	cout<<"\t\t\tEnter Type of the Account (C(Current)/S(Savings)) : ";
	cin>>type;
	if(type==c){
		account ac;
		ac.menu();
	}
	
//	cout<<"\t\t\tAccount Created..";
}

void admin::displayAccount() const{		//display Account FUnction.
	cout<<"\n\t\t\tAccount No. : "<<accNo;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

void admin::modify(){			//Modify Account FUnction.
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


void admin::dep(int x){
	deposit+=x;
}

void admin::draw(int x){
	deposit-=x;
}

void admin::report() const{
	cout<<accNo<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

int admin::retaccNo() const{
	return accNo;
}

int admin::retdeposit() const{
	return deposit;
}

char admin::rettype() const{
	return type;
}


void accountDetails(){  //
	admin ad;
	ofstream outFile;
	outFile.open("admin.txt",ios::binary|ios::app);
	ad.createAccount();
	outFile.write(reinterpret_cast<char *> (&ad), sizeof(admin));
	outFile.close();
}


void display_sp(int n){
	admin ad;
	bool flag=false;
	ifstream inFile;
	inFile.open("admin.txt",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
//		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    while(inFile.read(reinterpret_cast<char *> (&ad), sizeof(admin))){
		if(ad.retaccNo()==n){
			ad.displayAccount();
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
	admin ad;
	fstream File;
    File.open("admin.txt",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof()){				//&& found==false
		File.read(reinterpret_cast<char *> (&ad), sizeof(admin));
		if(ad.retaccNo()==n)
		{
			ad.displayAccount();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ad.modify();
			int pos=(-1)*static_cast<int>(sizeof(admin));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ad), sizeof(admin));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}


void deleteAccount(int n){
	admin ad;
	ifstream inFile;
	ofstream outFile;
	inFile.open("admin.txt",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.txt",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ad), sizeof(admin))){
		if(ad.retaccNo()!=n){
			outFile.write(reinterpret_cast<char *> (&ad), sizeof(admin));
		}
	}
    inFile.close();
	outFile.close();
	remove("admin.txt");
	rename("Temp.txt","admin.txt");
	cout<<"\n\n\t\tRecord Deleted ..";
}


void displayRecords(){
	system("cls");
	admin ad;
	ifstream inFile;
	inFile.open("admin.txt",ios::binary);
	if(!inFile){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type        Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ad), sizeof(admin))){
		ad.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	admin ad;
	fstream File;
    File.open("admin.txt", ios::binary|ios::in|ios::out);
	if(!File){
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false){
		File.read(reinterpret_cast<char *> (&ad), sizeof(admin));
		if(ad.retaccNo()==n){
			ad.displayAccount();
			if(option==1){
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ad.dep(amt);
			}
		    if(option==2){
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ad.retdeposit()-amt;
				if(bal<0)
					cout<<"Sorry !! Insufficience balance..";
				else
					ad.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ad));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ad), sizeof(admin));
			cout<<"\n\n\t\t\tSuccess... Record Updated Successfully";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tOops! We Couldn't find your record";
}


// MenuList of Project


void menulist(){
    char ch;
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
		cout<<"\n\t\t\t\t8. Exit";
		cout<<"\n\n\t\t\t\tChoose options:[1/2/3/4/5/6/7/8]:: ";
		cin>>ch;
		switch(ch){
		case '1':
			accountDetails();
			break;
		case '2':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
			cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : ";
			 cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
			cin>>num;
			display_sp(num);
			break;
		case '5':
			displayRecords();
			break;
		case '6':
			system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
			cin>>num;
			deleteAccount(num);
			break;
		 case '7':
		 	system("cls");
			cout<<"\n\n\t\t\tEnter The account No. : "; 
			cin>>num;
			modifyAccount(num);
			break;
		 case '8':
		 	system("cls");
			cout<<"\n\n\t\t\tThank You For Banking With WOI-BANK....";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
}

//int main(){
//	admin add;
//	add.menulist();
//	return 0;
//}

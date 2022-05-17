#include <iostream>
#include<fstream>
#include <limits>
#include <string.h>
#include <unistd.h>
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h>   // for get function

using namespace std;

class atm{
 private:
	char username[30];
	int password;
	int balance;
	
public:
	char* usernames(void){
		return  username;
	}

	int passwords(void){
		return password;
	}

	
	void getData(void){ 						// Function to get the data (getter)
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\nEnter username:";
		cin.getline(username, 30);
		cout << "\nEnter 4-digit password:";
		cin >> password;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "\nEnter initial balance:";
		cin >> balance;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	void showData(void){										// Function displaying the data (setter)
		cout << "Username:" << username<<endl;
		cout << "Password:" << password<<endl;
		cout << "Balance:" << balance<<endl;
	}

	void atmUser();
	int add_user();									// Member Functions					
	int view_all_users();
	int delete_user(char*);
	void update_user_as_deposit(char*);
	void update_user_as_withdraw(char*);
	int search_specific_user(char*, int);
	int search_all_user_to_display(char*);
};

void atm::atmUser(){
	atm a;
	char uname[30];
	int pass, ch, ch1, ch2, found = 0;

mainmenu:
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> ATM SYSTEM LOGIN AS: <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Admin" << endl;
        cout << "\t\t\t\t\t 2. User" << endl;

        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t Enter Your Choice: "; // Taking the action input
        cin >> ch;

	switch (ch) {
	case 1:
	rerun:
		 system("cls");
		cout << "\nEnter details to login as Admin..!!\n";
		cout << "\nEnter password:";
		cin >> pass;
		if (pass == 1234) {
		admin:
			 system("cls");
			cout << "\nWelcome to Admin Menu..!"<<endl;
			cout << "\n1->Add User\n2.->Delete User\n3->View All User\n4->Exit\n";
			cout << "\nSelect one : ";
			cin >> ch1;
			switch (ch1) {
			case 1:
				a.add_user();
				goto admin;

			case 2:
				cout << "\nEnter the Username to be deleted : "<<endl;
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cin.getline(uname, 30);
				a.delete_user(uname);
				goto admin;

			case 3:
				a.view_all_users();
				 sleep(4);
				goto admin;

			case 4:
				break;
			}
		}
		else {
			cout << "\nDetails are incorrect ! Please try again.....";
			cin.get();
			goto rerun;
		}
		goto mainmenu;

	case 2:
		system("cls");
		cout << "\n Enter details to login as User\n";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Enter username:";
		cin.getline(uname, 30);
		cout << "\nEnter password:";
		cin >> pass;
		found = a.search_specific_user(uname, pass);
		if (found) {
		user:
			system("cls");
			cout << "\nWelcome "<< uname;
			cout << "\nWelcome to User Menu..!!";
			cout << "\n1->Deposit\n2->Withdraw\n3->View Account\n4->Exit\nEnter your choice:";
			cin >> ch2;
			switch (ch2) {
			case 1:
				a.update_user_as_deposit(uname);
				goto user;
			case 2:
				a.update_user_as_withdraw(uname);
				goto user;
			case 3:
				a.search_all_user_to_display(uname);
				 sleep(4);
				goto user;
			case 4:
				cout << "Thank you";
				break;
			}
		}
		else {
			cout << "\nNo account found with username "<<uname;
			cin.get();
		}
		goto mainmenu;

	case 3:
		cout << "\nThankyou for banking with WOI-BANK";
		cin.get();
		break;
	}
}

int atm::add_user(){			// Function to add new recourd of new user
	atm a;
	ofstream file1;	
	file1.open("atm.txt",ios::out | ios::app);		// Open file in write mode
	if (!file1) {
		cout << "Error in creating file.." << endl;
		return 0;
	}
	a.getData();			// Read from user
	file1.write((char*)&a, sizeof(a));			// Write into file
	file1.close();
	return 0;
}

int atm::view_all_users(){			// View recourds of all Users
	atm a;
	ifstream file1;
	file1.open("atm.txt", ios::in);
	if (!file1) {
		cout << "Error in opening file..";
		return 0;
	}
	file1.read((char*)&a, sizeof(a));  			// Read data from file
	while (!file1.eof()) {	
		a.showData();							// Display data on screen
		file1.read((char*)&a, sizeof(a));
	}
	file1.close();
	return 0;
}

int atm::delete_user(char* uname){			// Function to delete the user
	atm a;
	fstream original, temp;
	original.open("aaa.txt", ios::in);
	if (!original) {
		cout << "\nfile not found";
		return 0;
	}
	else {
		temp.open("temp.txt",ios::out | ios::app);
		original.read((char*)&a, sizeof(a));
		while (!original.eof()) {
			if (!strcmp(a.usernames(),uname)) {
				cout << "data found and deleted\n"<< a.username<<"\n";
			}
			else {
				temp.write((char*)&a,sizeof(a));
			}
			original.read((char*)&a,sizeof(a));
		}
		original.close();
		temp.close();
		remove("atm.txt");
		rename("temp.txt", "atm.txt");
		a.view_all_users();
	}
	return 0;
}

void atm::update_user_as_deposit(char* uname){			// Function to update user by
	atm a;												// depositing money
	fstream file, temp;	
	file.open("aaa.txt",ios::in | ios::out | ios::ate);
	temp.open("temp.txt",ios::out | ios::app);
	file.seekg(0);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {				/// sraech Till end of the file by help of .eof()
		if (!strcmp(a.usernames(), uname)) {
			int b;
			cout << "\nEnter amount to deposit:";
			cin >> b;
			a.balance = a.balance + b;
			cout << "\nBalance is:"<< a.balance;
			temp.write((char*)&a, sizeof(a));
		}
		else {
			temp.write((char*)&a, sizeof(a));
		}
		file.read((char*)&a, sizeof(a));
	}
	file.close();
	temp.close();
	remove("atm.txt");
	rename("temp.txt", "atm.txt");
}

void atm::update_user_as_withdraw(char* uname){					// Function to update user by
	atm a;												// depositing withdrawing user givcen amount				
	fstream file, temp;	
	file.open("atm.txt",ios::in | ios::out | ios::ate);
	temp.open("temp.txt",ios::out | ios::app);
	file.seekg(0);
	file.read((char*)&a, sizeof(a));
	while (!file.eof()) {				// Till end of file is reached
		if (!strcmp(a.usernames(), uname)) {
			int b;
			cout << "\nEnter amount to withdraw:";
			cin >> b;
			if (a.balance < b) {
				cout<< "\nInsufficient balance to withdraw";
			}
			else {
				a.balance = a.balance - b;
				temp.write((char*)&a,sizeof(a));
				cout << "\nBalance is:"<< a.balance;
			}
		}
		else {
			temp.write((char*)&a,sizeof(a));
		}
		file.read((char*)&a, sizeof(a));
	}
	file.close();			// Close the file
	temp.close();
	remove("atm.txt");
	rename("temp.txt", "atm.txt");
}

int atm::search_specific_user(char* uname, int pass){		// Search user
	atm a;
	fstream f;
	f.open("atm.txt", ios::in);			// Open the file
	if (!f) {
		cout << "Error in opening file..";
		return 0;
	}	
	f.read((char*)&a, sizeof(a));		// Read data from file
	while (!f.eof()) {
		if (!strcmp(a.usernames(), uname)) {
			if (a.passwords() == pass) {
				return 1;
			}
		}
		f.read((char*)&a, sizeof(a));
	}
	f.close();			// Close the file
	return 0;
}

int atm::search_all_user_to_display(char* uname){ 			// Search specific user
	atm a;
	fstream file1;
	file1.open("atm.txt", ios::in); 		// Open the file
	if (!file1) {
		cout << "Error in opening file..";
		return 0;
	}                                     // Read data from file
	file1.read((char*)&a, sizeof(a));
	while (!file1.eof()) {
		if (!strcmp(a.usernames(), uname)) {
			a.showData();
			return 0;
		}
		file1.read((char*)&a, sizeof(a));
	}
	// Close the file
	file1.close();
	return 0;
}

// Driver Code
//int main(){
//	// Function Call
//	atmUser();
//	return 0;
//}


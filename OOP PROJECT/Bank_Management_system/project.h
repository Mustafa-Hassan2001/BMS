//#include <iostream>
#include <string>
#include <windows.h> //for system cls and sleep and goto back: functions. 
#include <conio.h>   // for get function
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Bank{				 // Main class
	private: 
	    int total;
	    string id;
	    struct person{				// Inheritance Structure to store basic data.
	    	string name,ID,address;
	    	int contact,cash;
		}person[100];				// Array to store data.
	public:
		Bank(){                 // Constructor
			total=0;
		void choice();
		void Createaccount();
		void show();
		void update();
		void search();
		void transactions();
		void del();
	}
		
	void choice(){      
	int ch;
	while(1){
	cout<<"PRESS FOLLOWIING OF YOUR CHOICE..!!"<<endl;
	cout<<"1-> Create new account"<<endl;
	cout<<"2-> View customers list"<<endl;
	cout<<"3-> Update information of existing account"<<endl;
	cout<<"4-> Check the details of an existing account"<<endl;
	cout<<"5-> For transactions"<<endl;
	cout<<"6-> Remove existing account"<<endl;
	cout<<"7-> Exit"<<endl;
	ch=getch();				// It is bydefault function to get input from user.		
	system("CLS");			// To see all function on new windows it clear privous data in output. 
	switch(ch){
		case '1':
			Bank::Createaccount();  // This is "::" the  scope resolution operator to access the function of class.
			break;
		case '2':
			if(total==0){   // it runs when there is no account in back.
				cout<<"No data is entered"<<endl;
			}else{
			Bank::show();
		   }
			break;
		case '3':
			if(total==0){
			cout<<"No data is entered"<<endl;
		}
			else{
			Bank::update();
		}
			break;
		case '4':
			if(total==0){
			cout<<"No data is entered"<<endl;
		}
			else{
			Bank::search();
		}
			break;
		case '5':
			if(total==0){
			cout<<"No data is entered"<<endl;
		}
			else{
			Bank::transactions();
	}
			break;
		case '6':
			if(total==0){
			cout<<"No data is entered"<<endl;
		}
			else{
			Bank::del();
		}
			break;
		case '7':
			exit(0);
			break;
		default:
			cout<<"Invalid input"<<endl;
			break;
	}
    }
}

void Createaccount(){		//Create NEW Account
	cout<<"Enter data of person "<<total+1<<endl;
	cout<<"Enter name:";
	cin>>person[total].name;
	cout<<"ID:";
	cin>>person[total].ID;
	cout<<"Address:";
	cin>>person[total].address;
	cout<<"Contact: ";
	cin>>person[total].contact;
	cout<<"Total Cash: ";
	cin>>person[total].cash;
	total++;
}

void show(){			// View customers list
	for(int i=0;i<total;i++){
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
	}
}

void update(){		// Update information of existing account
	cout<<"Enter id of person those data you want to update"<<endl;  // Varifaction by id.
	cin>>id;
	for(int i=0;i<total;i++){
		if(id==person[i].ID){
		cout<<"Previous data"<<endl;
		cout<<"Data of person "<<i+1<<endl;
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		cout<<"Enter new data"<<endl;
		cout<<"Enter name: ";
		cin>>person[i].name;
		cout<<"ID: ";
		cin>>person[i].ID;
		cout<<"Address: ";
		cin>>person[i].address;
		cout<<"Contact: ";
		cin>>person[i].contact;
		cout<<"Total Cash: ";
		cin>>person[i].cash;
		break;
	}
		if(i==total-1){							//It is for any worng input those id which doesn't esixted.
			cout<<"No such record found"<<endl;
		}
	}
}

void search(){			// Check the details of any existing account.
cout<<"Enter id of person those data you want to search"<<endl;   //Through ID.
cin>>id;
for(int i=0;i<total;i++){
	if(id==person[i].ID){
		cout<<"Name: "<<person[i].name<<endl;
		cout<<"ID: "<<person[i].ID<<endl;
		cout<<"Address: "<<person[i].address<<endl;
		cout<<"Contact: "<<person[i].contact<<endl;
		cout<<"Cash: "<<person[i].cash<<endl;
		break;
	}
	if(i==total-1){        //It is for any worng input those id which doesn't esixted.
		cout<<"No such record found"<<endl;
	}
}
}

void transactions(){		// For Transactions
	int cash;
	char ch;
	cout<<"Enter id of person those data you want to transaction"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		cout<<"Name: "<<person[i].name<<endl;
     	     cout<<"Address: "<<person[i].address<<endl;
		     cout<<"Contact: "<<person[i].contact<<endl;
		     cout<<"\nExisting Cash "<<person[i].cash<<endl;
		     cout<<"Press 1 to deposit"<<endl;
		     cout<<"Press 2 to withdraw"<<endl;
//		     cin>>ch;
		     ch=getch();
		     switch(ch){
		     	case '1':
		     		cout<<"How much cash you want to deposit??"<<endl;
		     		cin>>cash;
		     		person[i].cash+=cash;
		     		cout<<"Your new cash is "<<person[i].cash<<endl;
		     		break;
		     	case '2':
		     		back:		//	<-------------------------------------------------------														
		     		cout<<"How much cash you want to withdraw??"<<endl;					 // |	
		     		cin>>cash;															 // |	
		     		if(cash>person[i].cash){											 // |		
		     			cout<<"Your existing cash is just "<<person[i].cash<<endl;		 //	|
		     			Sleep(3000);													 // |
		     			goto back;										//<-----------------
					 }
					 person[i].cash-=cash;
					 cout<<"Your new cash is "<<person[i].cash<<endl;
					 break;
				default:
					cout<<"Invalid input"<<endl;
					break;
			 }
			 break;
		 }
		 if(i==total-1){
		 	cout<<"No such record found"<<endl;
		 }
	 }
}

void del(){			// Remove existing account
	char ch;
	cout<<"Press 1 to remove specific record"<<endl;
	cout<<"Press 2 to remove full record"<<endl;
//	cin>>ch;
 ch=getch();
	switch(ch){
		case '1':
	cout<<"Enter id of person those data you want to remove"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
     	if(id==person[i].ID){
     		for(int j=i;j<total;j++){                    //
     		person[j].name=person[j+1].name;            // Bubble sorting data,
     		person[j].ID=person[j+1].ID;               // overwrite.
     		person[j].address=person[j+1].address;	  //
     		person[j].contact=person[j+1].contact;   //
     		person[j].cash=person[j+1].cash;		//
     		total--;
     		cout<<"Your required data is deleted"<<endl;
     		break;
			 }
		 }
		 if(i=total-1){
		cout<<"No such record found"<<endl;
		 }
	 }
	 break;
	 case '2':
	 	total=0;
	 	cout<<"All record is deleted"<<endl;
	 	break;
	default:
		cout<<"Invalid Input"<<endl;
		break;
	}
}
//		~Bank(){
//			delete choice;
//			delete Createaccount;
//			delete show;
//			delete update;
//			delete search;
//			delete transactions;
//			delete del;
//		}
 
};


class login{
	
	string name,id,address;
	
	cout<<"\n\n\t\tEmployee Management System"<<endl;

	string username,password;

    cout<<"\n\n\n\t\t******Signup******"<<endl;

	cout<<"\t\tEnter new username: ";

	cin>>username;

	cout<<"\t\tEnter new password: ";

	cin>>password;

	cout<<"\t\tYour new id is creating please wait";

	for(int i=0;i<6;i++)

	{

		cout<<".";

		Sleep(500);

	}

	cout<<"\n\t\tYour id created successfully";

	Sleep(2000);

	start:

	system("CLS");

	string usrn,pswd;

	cout<<"\n\n\t\tEmployee Management System"<<endl;

	cout<<"\n\n\n\t\t   LOGIN"<<endl;

	cout<<"\t\tEnter username: ";

	cin>>usrn;

	cout<<"\t\tEnter password: ";

	cin>>pswd;

	if(usrn==username&&pswd==password)

	{

	system("CLS");

	char ch;

};



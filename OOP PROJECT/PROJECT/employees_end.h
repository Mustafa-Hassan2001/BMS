#include <iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<string>

using namespace std;


class Employees{
	public:
	string name,id,address;

	int salary,contact;

};

int total=0;

Employees e[100];

void empdata(){

	int user=0;

	cout<<"How many employees data do you want to enter??"<<endl;

	cin>>user;

	for(int i=total;i<total+user;i++){

		cout<<"Enter data of employee "<<i+1<<endl<<endl;

		cout<<"Enter employee name: ";

		cin>>e[i].name;

		cout<<"Enter id: ";

		cin>>e[i].id;

		cout<<"Enter address: ";

		cin>>e[i].address;

		cout<<"Enter contact: ";

		cin>>e[i].contact;

		cout<<"Enter salary: ";

		cin>>e[i].salary;

	}

	total=total+user;

}

void show(){

	if(total!=0){

	for(int i=0;i<total;i++){

		cout<<"Data of employee "<<i+1<<endl;

		cout<<"Name: "<<e[i].name<<endl;

		cout<<"ID: "<<e[i].id<<endl;

		cout<<"Address: "<<e[i].address<<endl;

		cout<<"Contact: "<<e[i].contact<<endl;

		cout<<"Salary: "<<e[i].salary<<endl;

	}

    }

    else{

    	cout<<"No data is entered"<<endl;

	}

}

void search(){

	if(total!=0){

	string id;

	cout<<"Enter id of employee which you want to search"<<endl;

	cin>>id;

	for(int i=0;i<total;i++){

		if(e[i].id==id){

		cout<<"Data of employee "<<i+1<<endl;

		cout<<"Name: "<<e[i].name<<endl;

		cout<<"ID: "<<e[i].id<<endl;

		cout<<"Address: "<<e[i].address<<endl;

		cout<<"Contact: "<<e[i].contact<<endl;

		cout<<"Salary: "<<e[i].salary<<endl;

		break;

		}

		if(i==total-1){

			cout<<"No such record found"<<endl;

		}

	}

}else{

	cout<<"No data is entered"<<endl;

}

}

void update(){

	if(total!=0){

	string id;

	cout<<"Enter id of employee which you want to update"<<endl;

	cin>>id;

	for(int i=0;i<total;i++){

		if(e[i].id==id){

		cout<<"Old data of employee "<<i+1<<endl;

		cout<<"Name: "<<e[i].name<<endl;

		cout<<"ID: "<<e[i].id<<endl;

		cout<<"Address: "<<e[i].address<<endl;

		cout<<"Contact: "<<e[i].contact<<endl;

		cout<<"Salary: "<<e[i].salary<<endl;

		cout<<"\nEnter new data"<<endl;

		cout<<"Enter employee name: ";

		cin>>e[i].name;

		cout<<"Enter id: ";

		cin>>e[i].id;

		cout<<"Enter address: ";

		cin>>e[i].address;

		cout<<"Enter contact: ";

		cin>>e[i].contact;

		cout<<"Enter salary: ";

		cin>>e[i].salary;

		break;

		}

		if(i==total-1){

			cout<<"No such record found"<<endl;

		}

	}

}else{

	cout<<"No data is entered"<<endl;

}

}

void del(){

	if(total!=0){

	int press;

	cout<<"Press 1 to delete specific record"<<endl;

	cout<<"Press 2 to delete full record"<<endl;

	cin>>press;

	if(press==1){

		string id;

		cout<<"Enter id of employee which you want to delete"<<endl;

		cin>>id;

		for(int i=0;i<total;i++){

			if(e[i].id==id){

				e[i].name=e[i+1].name;

				e[i].id=e[i+1].id;

				e[i].address=e[i+1].address;

				e[i].contact=e[i+1].contact;

				e[i].salary=e[i+1].salary;

				total--;

				cout<<"Your required record is deleted"<<endl;

				break;

			}

			if(i==total-1){

			cout<<"No such record found"<<endl;

		}

		}

	}

	else if(press==2){

		total=0;

		cout<<"All record is deleted"<<endl;

	}

	else{

		cout<<"Invalid Input"<<endl;

	}

}else{

	cout<<"No data is entered"<<endl;

}

}

int main(){



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


	cout<<"\n\n\n\t\t   LOGIN"<<endl;

	cout<<"\t\tEnter username: ";

	cin>>usrn;

	cout<<"\t\tEnter password: ";

	cin>>pswd;

	if(usrn==username&&pswd==password)

	{

	system("CLS");

	char ch;

	while(1){

	cout<<"\n\nPress 1 to enter data"<<endl;

	cout<<"Press 2 to show data"<<endl;

	cout<<"Press 3 to search data"<<endl;

	cout<<"Press 4 to update data"<<endl;

	cout<<"Press 5 to delete data"<<endl;

	cout<<"Press 6 to logout"<<endl;

	cout<<"Press 7 to exit"<<endl;

	ch=getch();

	system("CLS");

	switch(ch){

		case '1':

			empdata();

			break;

		case '2':

			show();

			break;

		case '3':

			search();

			break;

		case '4':

			update();

			break;

		case '5':

			del();

			break;

		case '6':

			goto start;

			break;

		case '7':

			exit(0);

			break;

		default:

			cout<<"\aInvalid Input"<<endl;

			break;

	}

}

}

  else if(usrn!=username)

  {

  	cout<<"\t\t\aInvalid username please try again";

  	Sleep(3000);

  	goto start;

  }

  else if(pswd!=password)

  {

  	cout<<"\t\t\aInvalid password please try again";

  	Sleep(3000);

  	goto start;

  }

  else{

  	cout<<"\t\t\aInvalid username and password";

  	Sleep(3000);

  	goto start;

  }

}

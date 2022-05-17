#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Insurance{
	public:
		string name;
		string dob;
		string address;
		string gender;
		int years;
		int age;
		int cinc;
		int sd; 
		int ed;
		void meun();
void Register(){
	cout<<"\t\t\tEnter your name : ";
	cin>>name;
	cout<<"\t\t\tEnter your Address : ";
	cin>>address;
	cout<<"\t\t\tEnter your gender : ";
	cin>>gender;
	cout<<"\t\t\tEnter your Date of Birth : ";
	cin>>dob;
	cout<<"\t\t\tEnter your age : ";
	cin>>age;
	cout<<"\t\t\tEnter your CNIC : ";
	cin>>cinc;	
	cout<<"\t\t\tEnter number of years : ";
	cin>>years;	
	cout<<"\t\t\tEnter Date For When Policy To Be Effective: ";
	cin>>sd;
	cout<<"\t\t\tEnter Date For When Policy To Be Expiry: ";
	cin>>ed;			
}
void monthlyins(){
	int mon_ins = 5000/years;
	cout<<"\n\t\t\tYOUR MONTHLY INSTALMENT =  "<<mon_ins;
}
};

class Vehicle_Insurance{
	public:	
	string Vehicle_num;
		int get_Vehicle_num(){
			cout<<"\t\t\tEnter your Vehicle number : ";
			cin>>Vehicle_num;
//			return Bill_num; 
		}
//start of nested class declaration	
	
class Engine{
	
	public:
	string Enginecc;
		int get_Enginecc(){
			cout<<"\t\t\tCar Engine Specifications are : ";
			cin>>Enginecc;			
//			return Enginecc;
		}//declaration nested class ends here
		void inu(){
			cout<<"\t\t\tFor Vehicle Insurance your monthly instalment is 5000/= Rupees ";
		}
};		
	Engine Enginecc;
};

void meun(){
	Insurance i;
	Vehicle_Insurance *obj1 = new Vehicle_Insurance();
	i.Register();
	obj1->get_Vehicle_num();
	obj1->Enginecc.get_Enginecc();
	obj1->Enginecc.inu();
	i.monthlyins();
	delete obj1;
//	return 0;
}

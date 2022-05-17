#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Topic#1->FRIND CLASS & FRIEND FUNCTION 

class client;

class Agent{
	protected:
		static int AWallet_Amount;
		public:
			Agent(int WAM){
				AWallet_Amount=WAM;
				cout<<endl<<"\t\t\t\tAmount Updated"<<endl;
			}
			Agent(){
			}
			void set_AWallet_Amount(int amount){
				AWallet_Amount=amount;
			}
			int get_AWallet_Amount(){
				return AWallet_Amount;
			}
		 friend class client;
		 friend void shopkeeper(int);		
};

int Agent::AWallet_Amount=0;

class client{
	private:
		static int CWallet_Amount;
		public:
			client(){
			}
			void Give_PM(int amount){
				Agent objCall;
				CWallet_Amount -= amount;
				objCall.AWallet_Amount+=amount;
				
			}
			int get_CWallet_Amount(){
				return CWallet_Amount;
			}			
};

int  client::CWallet_Amount=150000;

void shopkeeper(int PayAmount){
	Agent objPay;
	objPay.AWallet_Amount-= PayAmount;
	cout<<endl<<"\t\t\t\t"<<PayAmount<<"Amount of hajj form is Received from your agent"<<endl;
}
int main(int argc, char** argv) {
	Agent objPm1;
	string name, age, address, cnic, gender; 
	int  c, a, f;
	client ObjGPm;
	cout<<endl<<"\t\t\t\tEnter your name : ";
	cin>>name;
	cout<<endl<<"\t\t\t\tEnter your age : ";
	cin>>age;
	cout<<endl<<"\t\t\t\tEnter your gender : ";
	cin>>gender;
	cout<<endl<<"\t\t\t\tEnter your address : ";
	cin>>address;
	cout<<endl<<"\t\t\t\tEnter your CNIC : ";
	cin>>cnic;			
	cout<<endl<<"\t\t\t\tAgent Wallet Amount Was:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tPay 10,000/=  for agent commission : ";
	cin>>a;
	Agent ObjPm(a);
	cout<<endl<<"\t\t\t\tNow Agent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tClient's Wallet Amount Was:" <<ObjGPm.get_CWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tPlease Pay 1200/= to your agent for paper work : ";
	cin>>c; 
	ObjGPm.Give_PM(c);
	cout<<endl<<"\t\t\t\tClient's Wallet Amount is:"<<ObjGPm.get_CWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tAgent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\tYour Agent will Pay 500 for Hajj form : ";
	cin>>f;
	shopkeeper(f);
	cout<<endl<<"\t\t\t\tAgent Wallet Amount is:"<<objPm1.get_AWallet_Amount()<<endl;
	cout<<endl<<"\t\t\t\t----------------------------------------------------------------------"<<endl;	
	cout<<endl<<"\t\t\t\tYour application for Hajj is sumitted you will get  replay soon...!!";
	cout<<endl<<"\t\t\t\t-----------------------------------------------------------------------"<<endl;	
	return 0;
}



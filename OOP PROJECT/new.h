#include <iostream>  
#include<stdlib.h>  
#include<string.h>  
#include<math.h>  
#include <iomanip>  
#define MAX 15  
//#include "main.h" 

using namespace std;  
 
class account{  
   protected:  
     char cust_name[MAX];  
     char acc_type[MAX];  
     int acc_num; 
	 double contact;
	 double CNIC; 
   public:  
	 void menu();  
     virtual void display()=0;  
     virtual void create_ac()=0;  
     virtual void deposit()=0;  
     virtual void withdraw()=0;  
     virtual void intrest()=0;  
     virtual void balance()=0;  
 };  
 
class current: public account{ 
 
   protected:  
     float bal,initial_amt,amt,intr,CI;  
     int num,dummy,years,n,w_slip,x;  
   public:  
     current(){  
       strcpy(acc_type,"Current Account.");  
       acc_num=000;   
       n=2;  
     }  
   //Static Acount number  
   int gen_acc_num(){  
     static int s_nID = 1;  
     return s_nID++;    
   }  
//   void virtual getdata()  
//   { 
//    cout<<"\nYour Acount number is: ";  
//    x= gen_acc_num();  
//    cout<<setw(3)<<setfill('0')<< x <<endl;  
//    cout<<"\nEnter the Customer name: ";  
//    cin>>cust_name;    
//   }  

   virtual void display(){  
     cout<<"----FULL DETAILS----\n";  
     cout<<"Customer Name: "<<"\t"<<cust_name<<endl;  
     cout<<"Account No.: "<<"\t"<<setw(3)<<setfill('0')<<x<<endl;  
     cout<<"Accout Type: "<<"\t"<<acc_type<<endl;  
     cout<<"Contact : "<<"\t"<<contact<<endl;
     cout<<"CNIC : "<<"\t"<<CNIC<<endl;
     cout<<"------------------------\n";  
     cout<<"BALANCE: "<<"\t"<<bal<<endl;   
   }  
   
   void virtual create_ac(){ 
    cout<<"\nNEW Current Account\n"; 
    cout<<"\nYour Acount number is: ";  
    x= gen_acc_num();  
    cout<<setw(3)<<setfill('0')<< x <<endl;  
    cout<<"\nEnter the Customer name: ";  
    cin>>cust_name;     
    cout<<"Enter number of years the amount is deposited for: ";  
    cin>>years;  
    cout<<"Enter your contact number : ";
	cin>>contact;
	cout<<endl;
	cout<<"Enter your CNIC number : ";
	cin>>CNIC;
	cout<<endl;
     retry:  
     cout<<"\nEnter initial amount of deposit: ";  
     cin>>amt;  
     if(amt<500){  
       cout<<"Minimum deposit amount: Rs500\nTry Again\n";  
       goto retry;  
     }else  
     bal = amt;  
     initial_amt=amt;  
   }  
   
   void virtual deposit(){ 
     cout<<"Enter Account no.\n";  
     cin>>dummy;  
     if(x==dummy){  
       cout<<"Enter the amount to deposit\n";  
       cin>>amt;  
       bal +=amt;  
     }else  
     cout<<"Hacker! We've informed Police about this incident\n";  
   }  
   
   void virtual withdraw(){  
      cout<<"Enter Account no.\n";  
     cin>>dummy;  
    if(x==dummy){  
       cout<<"Enter the Withdraw slip no.\n";  
       cin>>w_slip;  
       cout<<"\nEnter amount to be withdrawn: ";  
       cin>>amt;  
       if(bal <= 500)  
         cout<<"Withdrwal not possible. Reached minimum balance\n";  
         else  
         bal = bal - amt;  
    }else  
     cout<<"Hacker! We've informed Police about this incident\n";  
   }  
    
   virtual void balance(){  
     cout<<"\nCurrent Balance: Rs"<<bal<<endl;  
   } 
    
 };  
 
class savings: public account{  
   protected:  
     float bal,initial_amt,amt,intr,SI;  
     int num,dummy,years,n,c_no,x;  
   public:  
     savings(){  
       strcpy(acc_type,"Savings Account.");  
       acc_num=000;     
       n=2;  
     }  
     
   int gen_acc_num(){  		//Static Acount number
     static int s_nID = 1;  
     return s_nID++;    
   }  
   
   virtual void display(){  
     cout<<"----FULL DETAILS----\n";  
     cout<<"Customer Name: "<<"\t"<<cust_name<<endl;  
     cout<<"Account No.: "<<"\t"<<setw(3)<<setfill('0')<<x<<endl;  
     cout<<"Accout Type: "<<"\t"<<acc_type<<endl;
	 cout<<"Contact : "<<"\t"<<contact<<endl;
     cout<<"CNIC : "<<"\t"<<CNIC<<endl;  
     cout<<"------------------------\n";  
     cout<<"BALANCE: "<<"\t"<<bal<<endl;   
   }  
   
   void virtual create_ac(){  
    cout<<"\nNEW Savings Account\n"; 
   	cout<<"\nYour Acount number is: ";  
    x= gen_acc_num();  
    cout<<setw(3)<<setfill('0')<< x <<endl; 
    cout<<"\nEnter the Customer name: ";  
    cin>>cust_name;   
     cout<<"Enter number of years the amount is deposited for: ";  
     cin>>years;  
     cout<<"Enter your contact number : ";
	 cin>>contact;
	 cout<<endl;
 	 cout<<"Enter your CNIC number : ";
	 cin>>CNIC;
	 cout<<endl;
     retry:  
     cout<<"Enter initial amount of deposit: ";  
     cin>>amt;  
     if(amt<500){  
       cout<<"Minimum deposit amount: Rs500\nTry Again\n";  
       goto retry;  
     }else  
     bal = amt;  
     initial_amt=amt;  
   }  
   
   void virtual deposit(){  
     cout<<"Enter Account no.\n";  
     cin>>dummy;  
     if(x==dummy){  
       cout<<"Enter the amount to deposit\n";  
       cin>>amt;  
       bal +=amt;  
     }else  
     cout<<"Hacker! We've informed Police about this incident\n";  
   }  
   
   void virtual withdraw(){  
      cout<<"Enter Account no.\n";  
     cin>>dummy;  
     if(x==dummy){  
       cout<<"Enter the Cheque no.\n";  
       cin>>c_no;  
       cout<<"\nEnter amount to be withdrawn: ";  
       cin>>amt;  
       if(bal <= 500)  
         cout<<"Withdrwal not possible. Reached minimum balance\n";  
         else  
         bal = bal - amt;  
     }else  
     cout<<"Hacker! We've informed Police about this incident\n";  
   }  
      
   virtual void balance(){
     cout<<"\nCurrent Balance: Rs"<<bal<<endl;  
   }  
 }; 
  
void account::menu(){
   account *a;   
   int ch;  
   back:  
   cout<<"----MENU----\n1.Current Acc\n2.Savings Acc\n3.Exit\n";  
   cout<<"Select account type: ";  
   cin>>ch;  
   switch(ch)  
   {  
     case 1: //Savings Accout  
       {  
         int ch;  
//         current c;  
  //       a=&c;  
         while(1)  
         {  
           cout<<"\n\nCurrent Account Facilities\n";  
           cout<<"--------------------------\n";  
           cout<<"1.Create Accout\n2.Deposit Account\n3.Witdrawal\n";  
           cout<<"4.Balance\n5.Full Account Details\n6.Exit\n";  
           cout<<"Enter choice from menu to make transactions: \n";  
           cin>>ch;  
           switch(ch)  
           {  
             case 1:  
                a->create_ac();  
                break;  
             case 2:  
               a->deposit();  
               break;  
             case 3:  
               a->withdraw();  
               break;  
             case 4:  
               a->balance();  
               break;  
             case 5:  
               a->display();  
               break;  
             case 6:  
               goto back;  
             default: cout<<"Invalid Input\n";  
           }  
         }  
       }  
     case 2: //Savings Accout  
       {  
          int ch;  
//         savings s;  
//         a=&s;    
         while(1){  
           cout<<"\n\nSavings Account Facilities\n";  
           cout<<"--------------------------\n";  
           cout<<"1.Create Accout\n2.Deposit Account\n3.Witdrawal\n";  
           cout<<"4.Balance\n5.Full Account Details\n6.Exit\n";  
           cout<<"Enter choice from menu to make transactions: \n";  
           cin>>ch;  
           switch(ch){  
             case 1:  
                a->create_ac();  
                break;  
             case 2:  
               a->deposit();  
               break;  
             case 3:  
               a->withdraw();  
               break;  
             case 4:  
               a->balance();  
               break;  
             case 5:  
               a->display();  
               break;  
             case 6:  
               goto back;  
             default: cout<<"Invalid Input\n";  
           }  
         }  
       }  
     case 3:  
       exit(0);  
     default: cout<<"Invalid Input\n";  
   }  
 system("pause");  
 } 

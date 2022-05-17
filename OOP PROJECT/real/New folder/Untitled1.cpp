#include <iostream>
using namespace std;

////Personal information
//struct Personal_information{
//char email[20];
//char address[20];
//char Education[20];
//int age;
//int phone_number;
//};
//
////Professional information
//struct Professional_information{
//float salary;
//int ID;
//char company_name[20];
//int working_experience;
//int working_hours;
//};
//
////Baank information
//struct Bank_information{
//int Acc_number;
//char ac_email[20];
//char Bank_name[20];
//int balance;
//int credit_card;
//};

//National record

struct National_record{

char Nationality[20];
char Gender[20];
int Cnic;
char Religion[20];
char name[20];

//Personal information
struct Personal_information{
char email[20];
char address[20];
char Education[20];
int age;
int phone_number;
};

//Professional information 
struct Professional_information{
float salary;
int ID;
char company_name[20];
int working_experience;
int working_hours;
};

//Baank information
struct Bank_information{
int Acc_number;
char ac_email[20];
char Bank_name[20];
int balance;
int credit_card;


};
struct Personal_information Pers;
struct Professional_information Prof;
struct Bank_information Acinfo;
};

int main(){
National_record nat[2];
int i;

for(i=0;i<2;i++){

cout<<"National record of client No."<<i+1<<endl;

//National record of client
cout<<"Enter Name:";
cin>>nat[i].name,19;

cout<<"Enter CNIC:";
cin>>nat[i].Cnic;

cout<<"Enter Gender:";
cin>>nat[i].Gender,19;

cout<<"Enter Nationality:";
cin>>nat[i].Nationality,19;

cout<<"Enter Religion:";
cin>>nat[i].Religion,19;

//Personal information of client
cout<<"Personal record of client No."<<i+1<<endl;

cout<<"Enter address:";
cin>>nat[i].Pers.address,19;

cout<<"Enter Age:";
cin>>nat[i].Pers.age;

cout<<"Enter Education:";
cin>>nat[i].Pers.Education,19;

cout<<"Enter Email:";
cin>>nat[i].Pers.email,19;

cout<<"Enter Phone number:";
cin>>nat[i].Pers.phone_number;

//Professional information of client
cout<<"Professional record of client No."<<i+1<<endl;

cout<<"Enter Business ID:";
cin>>nat[i].Prof.ID;

cout<<"Enter Working experience:";
cin>>nat[i].Prof.working_experience;

cout<<"Enter Company name:";
cin>>nat[i].Prof.company_name,19;

cout<<"Enter working hours:";
cin>>nat[i].Prof.working_hours;

cout<<"Enter salary:";
cin>>nat[i].Prof.salary;

//Bank Information of Client
cout<<"Bank record of client No."<<i+1<<endl;
cout<<"Enter Account number:";
cin>>nat[i].Acinfo.Acc_number;
cout<<"Enter Bank name:";
cin>>nat[i].Acinfo.Bank_name,19;

cout<<"Enter Balance:";
cin>>nat[i].Acinfo.balance;

cout<<"Enter Bank email:";
cin>>nat[i].Acinfo.ac_email,19;

cout<<"Enter ATM card number:";
cin>>nat[i].Acinfo.credit_card;

cin.get();
}

cout<<endl<<endl;
//National Record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tNational Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Name\t"<<"CNIC\t"<<"Gender\t"<<"Nationality\t"<<"Religion\t"<<endl;
for(i=0;i<2;i++){
cout<<nat[i].name<<"\t"<<nat[i].Cnic<<"\t"<<nat[i].Gender<<"\t"<<nat[i].Nationality<<"\t"<<nat[i].Religion<<endl;
}
//Personal record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tPersonal Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Address\t"<<"Age\t"<<"Education\t"<<"Email\t"<<"Phone number\t"<<endl;
for(i=0;i<2;i++){
cout<<nat[i].Pers.address<<"\t"<<nat[i].Pers.age<<"\t"<<nat[i].Pers.Education<<"\t"<<nat[i].Pers.email<<"\t"<<nat[i].Pers.phone_number<<endl;
}
//Professional record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tProfessional Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Business ID\t"<<"Working experience\t"<<"Company name\t"<<"Working hour\t"<<"Salary\t"<<endl;
for(i=0;i<2;i++){
cout<<nat[i].Prof.ID<<"\t\t"<<nat[i].Prof.working_experience<<"\t\t"<<nat[i].Prof.company_name<<"\t\t"<<nat[i].Prof.working_hours<<"\t\t"<<nat[i].Prof.salary<<endl;
}
//Bank record
cout<<"----------------------------------------------------------------"<<endl;
cout<<"\t\tBank Record\t\t"<<endl;
cout<<"----------------------------------------------------------------"<<endl;

cout<<"Account number\t\t"<<"Bank name\t\t"<<"Balance\t\t"<<"Bank email\t\t"<<"ATM card \t\t"<<endl;
for(i=0;i<2;i++){
cout<<nat[i].Acinfo.Acc_number<<"\t\t"<<nat[i].Acinfo.Bank_name<<"\t\t"<<nat[i].Acinfo.balance<<"\t\t"<<nat[i].Acinfo.ac_email<<"\t\t"<<nat[i].Acinfo.credit_card<<endl;
}
return 0;
}


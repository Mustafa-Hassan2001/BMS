#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
//#include <cstdlib>
//#include <cstring>
#include <cstdio>
#include <fstream>
#include "project.cpp"
using namespace std;

//class Bank{
//virtual int banking() = 0;	
//};

class Employee_management:public Bank{
private:					 // Variables for employee details
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc;
    char experience[20];
public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void Employee_management::menu(){			 //Project Menu
    while (true){
        int choice;
        char x; 			// Options to choose an action
        system("cls");
        cout << "1. Enter New Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Modify Record" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;
        cout << ".................................." << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice){
        case 1:
            do{
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            }while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            system("cls");
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert(){		 // add data of employees
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee New Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee CTC: ";
    cin >> ctc;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
    file.close();
}

void Employee_management::display(){		 // Display data of employe
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else{
        file >> name >> id >> designation >> age >> ctc >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      CTC      ||    EXPERIENCE    ||";
        cout << "\n -------------------------------------------------------------------------------------------------";
        while (!file.eof()){
            cout << "\n";
            cout << total++ << ". " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << ctc << "\t\t" << experience;
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::modify(){			// Modify data of employees
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else{
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) == 0){
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee CTC: ";
                cin >> ctc;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
                found++;
            }
            else{
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0){
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search(){ // Search data of employee's by id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file){
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else{
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) == 0){
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee CTC: " << ctc << "\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "---------------------\n";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted(){ // Delete data of employe
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file){
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else{
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> ctc >> experience;
        while (!file.eof()){
            if (strcmp(checkId, id) != 0){
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
            }
            else{
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> ctc >> experience;
        }
        if (found == 0){
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Employee_management::waitForEnter(){
    cout << "\n\nPress enter to go back: ";
    cin.get();
}

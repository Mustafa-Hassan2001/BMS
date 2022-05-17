//#include "mortgagePayment.h"
#include <iostream>
#include <math.h>

using namespace std;

class mortgagePayment {
public:
	void Mortgage();
	void display();
	
	
private:
	double tPayment(double principle, double term, double interest);
};


double mortgagePayment::tPayment(double principle, double term, double interest) {
	term = 0;
	int years = term *12;
	double monthlyInterest = interest/12/100;
	double total = (principle * monthlyInterest)/(1-pow(1 + monthlyInterest, -years)); //total for mortgage
	return(total);
}

void mortgagePayment::Mortgage() {
	double principle = 0;
	double rate = 0;
	int term = 0;
	double total = 0;
	
	cout << "Please enter Loan amount: ";
	cin >> principle;
	cout << "Please enter desired interest rate: ";
	cin >> rate;
	cout << "Please enter term: ";
	cin >> term;
	cout << "Your total monthly payment is: $" <<total;
	cout << "\n";
}

void mortgagePayment::display(){
	bool Exit = false;
	char ch;
	mortgagePayment calculator;  // A mortgage calculator object
	
	while (!Exit) {
		
		calculator.Mortgage();
		
		cout << "Would you like to enter another loan? (y/n):";
		cin >> ch;

		if (ch != 'y') {
			Exit = true;
		}
	}
}

int main(){
	mortgagePayment m;
	m.Mortgage();
	m.display();
	return 0;
}

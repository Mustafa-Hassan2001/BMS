#include "a.h"

class Savings: public Account {

public:

	Savings(double newBalance, double newInterestRate);

   double withdrawal(double amount);
   double deposit(double amount);

	
protected:

	double getRate() const;
	double setRate();

private:
	
	double interestRate;

};


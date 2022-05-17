#include "a.h"

class Checking: public Account {

public:
	
	Checking(double newBalance);

	double withdrawal(double);
	double deposit(double);
};

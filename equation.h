#include <iostream>
using namespace std;
#include "hugeinteger.h"

	ostream& operator <<(ostream&, const Equation&);

class Equation {

public:

	Equation();
	Equation(const HugeInteger &, const HugeInteger &, char op);

private:
	HugeInteger op1;
	HugeInteger op2;

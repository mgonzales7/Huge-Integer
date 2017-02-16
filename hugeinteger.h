#include <iostream>
#include <string>
using namespace std;

const int MAXDIGITS = 40;
class HugeInteger
{
	public:
	HugeInteger();
	HugeInteger(const string& strVal);
	
	void setZero(HugeInteger &);
	void display();
	bool isZero();
	
	HugeInteger& operator=(const HugeInteger&);
	HugeInteger operator+ (const HugeInteger&);	
	HugeInteger operator* (const HugeInteger&);

	bool operator==(const HugeInteger&) const ;
	bool operator!=(const HugeInteger&) const ;
	bool operator>=(const HugeInteger&) const ;
	bool operator<=(const HugeInteger&) const ;

	friend void operator <<(ostream &out, const HugeInteger &x);
	friend void operator >>(istream &in, HugeInteger &x);
	
	private:

	int DIGITS[MAXDIGITS];
	int length;
};


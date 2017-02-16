#include <iostream>
#include "hugeinteger.cpp"
using namespace std;

int main()
{
	HugeInteger num1;
	HugeInteger num2;
	HugeInteger answer;
	char op1;
	

	cout <<"Enter Equation: ";
	cin>>num1>>op1>>num2;

	cout << "=";

	if(op1=='+')
		answer = num1+num2;
	else if(op1=='*')
		answer = num1*num2;
	cout << answer;
	cout << endl;

	if(num1==num2)
		cout<<"Number 1 equals number 2\n";
	if(num1!=num2)
		cout<<"The numbers are not equal\n";
	if(num1>=num2)
		cout<<"Number 1 is greater than or equal to number 2\n";
	if(num1<=num2)
		cout<<"Number 1 is less than or equal to number 2\n";
	return 0;
}
	

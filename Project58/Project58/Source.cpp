#include <iostream>
using namespace std;
void main()
{
	cout << "Enter first number";
	int n1;
	cin >> n1;
	cout << "Enter second number";
	int n2;
	cin >> n2;
	cout << "Enter operator";
	char op;
	cin >> op;
	if (op == '+')
		cout << "Sum is " << (n1+n2);
	
	if (op == '-')
		cout << "Subtraction is " << (n1-n2);
	
	if (op == '*')
		cout << "Multiplication is " << (n1*n2);
	
	if (op == '/')
		cout << "Division is " << (n1/n2);
}

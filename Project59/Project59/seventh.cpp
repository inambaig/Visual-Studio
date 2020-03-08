#include <iostream>
using namespace std;

void main()
{
	int num;
	cout << "What is your number";
	cin >> num;
	if (num > 0)
		cout << "More than 0" << endl;
	else
		cout << "Less than or equal to 0" << endl;
}
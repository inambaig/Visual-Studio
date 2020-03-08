#include <iostream>
using namespace std;

int doubledSum(int n1, int n2, int n3, int n4)
{
	return n1 * 2 + n2 * 2 + n3 * 2 + n4 * 2;
}



void main()
{
	int n1, n2, n3, n4;
	cout << "Enter first number : ";
	cin >> n1;
	cout << "Enter second number : ";
	cin >> n2;
	cout << "Enter third number : ";
	cin >> n3;
	cout << "Enter fourth number : ";
	cin >> n4;
	cout << "Doubled sum = " << doubledSum(n1, n2, n3, n4) << endl;
	system("pause");
}
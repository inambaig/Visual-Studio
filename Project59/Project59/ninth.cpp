#include <iostream>
using namespace std;

void main()
{
	int num;
	cout << "What is your age";
	cin >> num;
	for (int i = 1;i<=num;i++)
		cout << "Happy Birthday! (year " << i <<" )"<< endl;
}
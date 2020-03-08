#include <iostream>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}


void main()
{
	int num;
	cout << "Enter a number to check prime : ";
	cin >> num;
	if (isPrime(num))
		cout << "Input number is a prime number." << endl;
	else
		cout << "Input number is not a prime number." << endl;
	system("pause");
}
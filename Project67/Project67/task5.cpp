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

void primeSequence(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (isPrime(i))
			cout << i << ", ";
	}
}


void main()
{
	int num;
	cout << "Enter a number : ";
	cin >> num;
	primeSequence(num);
	system("pause");
}
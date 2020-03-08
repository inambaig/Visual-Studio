#include <iostream>
using namespace std;

void greatrThanN(int arr[], int size, int n)
{
	cout << "Numbers that are greater than n" << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > n)
		{
			cout << arr[i] << "\t";
		}
	}
	cout << endl;
}

void main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter Number " << i + 1 << " : ";
		cin >> arr[i];
	}
	int n;
	cout << "Enter number n : ";
	cin >> n;
	greatrThanN(arr, 10, n);
}
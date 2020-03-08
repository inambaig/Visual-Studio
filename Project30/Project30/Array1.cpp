#include <iostream>
using namespace std;

void main()
{
	int arr[10];
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter Number " << i+1<< " : ";
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	cout << "Minimum element in array is " << min << endl;
	cout << "Maximum element in array is " << max << endl;

}
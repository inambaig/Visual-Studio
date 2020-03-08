#include <iostream>
using namespace std;


int func3(int x[], int size)
{
	int largest = INT_MIN;

	for (int i = 0; i < size; i++)
	{
		if (largest < x[i])
		{
			largest = x[i];
		}
	}
	return largest;
}


int main()
{
	int i;


	int x[] = { 3, 5, 1, 2, 8, 5, 9, 7};
	cout << "largest Number in array is : " << func3(x, 8)<<endl;
}
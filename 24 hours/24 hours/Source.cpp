#include <iostream>
using namespace std;

void main()
{
	float num1 = 1.00000115;
	float num2 = 1;
	float num3 = 4.00000115;
	float num4 = 2;
	float sum = num1 + num2;
	float diff = num3 - num4;

	if (sum == diff)
	{
		cout << "Both are equal." << endl;
	}
	else
	{
		cout << "Both are not equal." << endl;
	}

	system("pause");
}
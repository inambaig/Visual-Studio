#include <iostream>
using namespace std;

void showValues(int);
void main()
{
	int collection[10];
	char greeting[] = { 'h', 'e', 'l', 'l', 'o' };
	cout << greeting;

	int array1[4], array2[4] = { 1, 2, 3, 4 };

	for (int i = 0; i<4; i++)
		array1[i] = array2[i];
	showValues(array1);
}
void showValues(int num[])
{

	for (int i = 0; i < 5; i++)

	{
		cout << num[i];

	}

}



int table[3] = 9, 12, 18;
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

int findCloset(int angle)
{
	int closest = 100; int value = 0;
	for (int i = 0; i < 350; i = i + 90)
	{
		if (abs(angle - i) < closest)
		{
			value = i;
			closest = abs(angle - i);
		}
	}
	return value;
}

int min(int arr[])
{
	int min = 100000;
	int minIndex = 0;
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}
int findClosest1(int num)
{
	int arr[7] = { 0 };
	arr[0] = abs(num - (-30));
	arr[1] = abs(num - (+30));
	arr[2] = abs(num - (-90));
	arr[3] = abs(num - (+90));
	arr[4] = abs(num - (-135));
	arr[5] = abs(num - (+135));
	arr[6] = abs(num - (+180));

	int arr1[7] = { 0 };
	arr1[0] = -30;
		arr1[1] = +30;
	arr1[2] = -90;
	arr1[3] = +90;
	arr1[4] = -135;
		arr1[5] = +135;
	arr1[6] = +180;
	return arr1[min(arr)];
}

int solution(int X, int Y)
{
	int x1 = X;
	if (X == 0 || X == 90 || X == 180 || X == 270)
		X = 0;
	int Y1 = findCloset(Y);

	int diffY = Y1 - Y;
	int ans = abs(X + diffY);
	if (x1 > Y)
		ans *= -1;
	return findClosest1(ans);
}
void main()
{
	cout << solution(270, 50)<<endl;
	cout << solution(5, 200)<<endl;
	system("pause");
}
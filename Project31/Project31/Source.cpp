#include<iostream>
#include <string>
using namespace std;

string*arr;
int currentSize = 0;
int currentElements = 0;

void doubleSize()
{
	string*arr1 = arr;
	currentSize = currentSize * 2;
	arr = new string[currentSize];

	for (int i = 0; i < currentSize / 2; i++)
	{
		arr[i] = arr1[i];
	}
}
void main()
{
	currentSize = 2;
	arr = new string[currentSize];

	int index = 0;

	while (currentElements == 0 || arr[currentElements - 1] != "")
	{
		if (currentElements >= currentSize)
		{
			doubleSize();
		}
		getline(cin, arr[currentElements++]);
	}

	cout << "Entered statements are :\n\n";
	for (int i = 0; i < currentElements; i++)
	{
		cout << arr[i] << endl;
	}

	cout << "Enter left|right|center and paragraph width: ";
	string justify = "";
	int width = 0;


	cin >> justify;
	cin >> width;

	if (justify == "left")
	{
		for (int i = 0; i < currentElements; i++)
		{
			if (arr[i].length() < width)
			{
				int length = arr[i].length();
				for (int j = 0; j < (width - length); j++)
				{
					arr[i] = arr[i] + " ";
				}
			}

		}
	}

	else if (justify == "right")
	{
		for (int i = 0; i < currentElements; i++)
		{
			if (arr[i].length() < width)
			{
				int length = arr[i].length();
				for (int j = 0; j < (width - length); j++)
				{
					arr[i] = " " + arr[i];
				}
			}

		}
	}

	else if (justify == "center")
	{
		for (int i = 0; i < currentElements; i++)
		{
			if (arr[i].length() < width)
			{
				int length = arr[i].length();
				for (int j = 0; j < (width - length) / 2; j++)
				{
					arr[i] = " " + arr[i] + " ";
				}
			}

		}
	}

	cout << "\nJustified statements are :\n\n";
	for (int i = 0; i < currentElements; i++)
	{
		cout << arr[i] << endl;
	}
	system("pause");
}
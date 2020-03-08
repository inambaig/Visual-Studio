#include <iostream>
#include <string>
using namespace std;

string increment(string a)
{
	string newString = "";
	char newChar = a[3];
	if (a[3] != '9')
	{
		newChar++;
		for (int i = 0; i < 3; i++)
		{
			newString += a[i];
		}
		newString += newChar;
	}
	else
	{
		a[3] = '0';
		newChar = a[2];
		if (a[2] != '9')
		{
			newChar++;
			for (int i = 0; i < 2; i++)
			{
				newString += a[i];
			}
			newString += newChar;
			newString += a[3];
		}
		else
		{
			a[2] = '0';
			newChar = a[1];
			if (a[1] != '9')
			{
				newChar++;
				
				newString += a[0];
				newString += newChar;
				newString += a[2];
				newString += a[3];
			}
			else
			{
				a[1] = '0';
				newChar = a[0];
				if (a[0] != '9')
				{
					newChar++;
					newString += newChar;
					newString += a[1];
					newString += a[2];
					newString += a[3];
				}
			}
		}
	}


	
	return newString;
}
void main()
{
	string number = "";
	

	cout << "Press 1 to put your own code or 2 to generate it random : ";
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		cin >> number;
	}
	if (choice == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			char digit = (rand() % 10) + 48;
			number = number + digit;
		}
	}
	else
	{
		return;
	}

	cout << "Press 1 to play game or 2 to check all combinations : ";
	choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		cin >> number;
	}
	if (choice == 2)
	{
		for (int i = 0; i < 4; i++)
		{
			char digit = (rand() % 10) + 48;
			number = number + digit;
		}
	}
	else
	{
		return;
	}



	cout << "Code   Guess\t#right\t#right in wrong spot\tSum";
	string numbNow = "0000";
	int right4 = 0;
	int right3 = 0;
	int right2 = 0;
	int right1 = 0;
	int right0 = 0;


	int rightWrong1 = 0;
	int rightWrong2 = 0;
	int rightWrong3 = 0;
	int rightWrong4 = 0;
	int rightWrong0 = 0;

	for (int i = 0; i < 9999; i++)
	{
		numbNow = increment(numbNow);
		int countRight = 0;
		int countRightOnWrong = 0;
		for (int i = 0; i < 4; i++)
		{
			if (number[i] == numbNow[i])
			{
				countRight++;
			}

			for (int j = 0; j < 4; j++)
			{
				if (i != j)
				{
					if (number[i] == numbNow[j])
					{
						countRightOnWrong++;
					}
				}
			}
		}
		cout << number << "\t" << numbNow << "\t" << countRight << "\t" << countRightOnWrong << "\t" << countRight + countRightOnWrong << endl;
		if (countRight >= 4)
		{
			right4++;
		}
		else if (countRight == 3)
		{
			right3++;
		}
		else if (countRight == 2)
		{
			right2++;
		}
		else if (countRight == 1)
		{
			right1++;
		}
		else if (countRight == 0)
		{
			right0++;
		}


		if (countRightOnWrong >= 4)
		{
			rightWrong4++;
		}
		else if (countRightOnWrong == 3)
		{
			rightWrong3++;
		}
		else if (countRightOnWrong == 2)
		{
			rightWrong2++;
		}
		else if (countRightOnWrong == 1)
		{
			rightWrong1++;
		}
		else if (countRightOnWrong == 0)
		{
			rightWrong0++;
		}

	}
	cout << "Right should be 4 = " << right4 << endl;
	cout << "Right should be 3 = " << right3 << endl;
	cout << "Right should be 2 = " << right2 << endl;
	cout << "Right should be 1 = " << right1 << endl;
	cout << "Right should be 0 = " << right0 << endl;

	cout << "How many times should 0 right but wrong placed come up" << rightWrong0 << endl;
	cout << "How many times should 1 right but wrong placed come up" << rightWrong1 << endl;;
	cout << "How many times should 2 right but wrong placed come up" << rightWrong2 << endl;;
	cout << "How many times should 3 right but wrong placed come up" << rightWrong3 << endl;;
	cout << "How many times should 4 right but wrong placed come up" << rightWrong4 << endl;;


	system("pause");
}
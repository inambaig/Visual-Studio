
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void main()
{
	ifstream in;
	in.open("homework4.csv");
	string arr[100][8];
	string input;
	getline(in, input);
	int promotionalCount = 0;
	int marriedCount = 0;
	int methodVisa = 0;
	int genderMale = 0;
	int itemTotal = 0;
	int saleTotal = 0;
	int ageTotal = 0;
	int countAbove40 = 0;
	for (int i = 0;i<100;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			getline(in, arr[i][j], ',');
			if (j == 1)// type
			{
				if (arr[i][j] == "Promotional")
					promotionalCount++;
			}
			else if (j == 2) //items
			{
				itemTotal += stoi(arr[i][j]);
			}
			else if (j == 3) //sales
			{
				saleTotal += stoi(arr[i][j]);
			}
			else if (j == 4) //paymentMode
			{
				if (arr[i][j] == "Visa")
					methodVisa++;
			}
			else if (j == 5) //gender
			{
				if (arr[i][j] == "Male")
					genderMale++;
			}
			else if (j == 6) // marrital status
			{
				if (arr[i][j] == "Married")
					marriedCount++;
			}
			else if (j == 7) //age
			{
				int age = stoi(arr[i][j]);
				ageTotal += age;
				if (age > 40)
				{
					countAbove40++;
				}
			}
		}
		getline(in, input);
	}
	in.close();

	ofstream out;
	out.open("output_homework4.csv");
	cout << "Percentage of promotional customers : " << promotionalCount << "%" << endl;
	cout << "Percentage of married customers : " << marriedCount << "%" << endl;
	cout << "Percentage of male customers : " << genderMale << "%" << endl;
	cout << "Percentage of Visa users : " << methodVisa << "%" << endl << endl;

	cout << "Average of Items : " << itemTotal / 100 << endl;
	cout << "Average of Sales : " << saleTotal / 100 << endl;
	cout << "Average Age      : " << ageTotal / 100 << endl << endl;

	cout << "Own choice finding" << endl << endl;

	cout << "Percentage of customers have atlest 40 years of age : " << countAbove40 << "%" << endl<<endl;

	out << "Percentage of promotional customers : " << promotionalCount << "%" << endl;
	out << "Percentage of married customers : " << marriedCount << "%" << endl;
	out << "Percentage of male customers : " << genderMale << "%" << endl;
	out << "Percentage of Visa users : " << methodVisa << "%" << endl << endl;

	out << "Average of Items : " << itemTotal / 100 << endl;
	out << "Average of Sales : " << saleTotal / 100 << endl;
	out << "Average Age      : " << ageTotal / 100 << endl << endl;
	out << "Own choice finding" << endl << endl;
	out << "Percentage of customers have atlest 40 years of age : " << countAbove40 << "%" << endl << endl;

	out << "Customer Records" << endl << endl;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			out << arr[i][j] << ",";
		}
		out << endl;
	}
	system("pause");
}

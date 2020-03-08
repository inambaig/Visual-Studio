#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*
Format of input file

First line should contain count of students
Next lines should contains name of student, 1 student name should be in each line
*/
void main()
{
	int again = 0;
	do{
		int choice = 0;
		cout << "Please enter 1 to take input from file or press 2 to take input from keyboard : ";
		cin >> choice;

		if (choice == 1)
		{
			string filename = "";
			cin.ignore();
			cout << "Enter name of file : ";
			getline(cin, filename);
			string first = "z";
			string last = "A";
			ifstream in (filename);
			string line = "";
			int count = 0;
			in >> count;
			in.ignore();
			if (count >= 5 || count <= 45)
			{
				for (int i = 0; i < count; i++)
				{
					getline(in, line);
					if (line < first)
					{
						first = line;
					}
					if (line > last)
					{
						last = line;
					}
				}
			}
			else
			{
				cout << "Please enter valid student count (5-45)" << endl;
			}

			cout << "First Name in list should be : " << first << endl;
			cout << "Last Name in list should be : " << last << endl;

		}

		else if (choice == 2)
		{
			string first = "z";
			string last = "A";
			string line = "";
			int count = 0;
			cout << "Enter number of students : ";
			cin >> count;
			cin.ignore();
			if (count >= 5 || count <= 45)
			{
				for (int i = 0; i < count; i++)
				{

					cout << "Enter number of student # " << i + 1 << " : ";
					getline(cin, line);
					if (line < first)
					{
						first = line;
					}
					if (line > last)
					{
						last = line;
					}
				}

			}
			else
			{
				cout << "Student count not valid" << endl;
			}
			
			cout << "First Name in list should be : " << first << endl;
			cout << "Last Name in list should be : " << last << endl;

		}
		else
		{
			cout << "Invalid choice" << endl;
		}

		cout << "Enter 1 to do it again, and 0 to stop." << endl;
		cin >> again;
	} while (again == 1);

	cout << "My(Programmer) name is Ziwei Liu";

	system("pause");
}
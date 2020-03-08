#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input;
	input.open("input.txt");
	double a;
	double sum=0;
	double min = 100;
	double max = 0;
	string filename = "";
	cout << "Enter name of output file : ";
	cin >> filename;
	ofstream output(filename);
	for (int i = 0; i < 15; i = i + 1)
	{
		input >> a;
		if (a < min)
		{
			min = a;
		}

		if (a > max)
		{
			max = a;
		}
		sum = sum + a;

		output << a << endl;
		cout << a << endl;

	}
	output << "min = " << min << endl;
	output << "max = " << max << endl;
	output << "Average = " << sum / 15 << endl;
	cout << "min = " << min << endl;
	cout << "max = " << max << endl;
	cout << "Average = " << sum / 15 << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double salesPerson1[5];
	double salesPerson2[5];
	double salesPerson3[5];
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	for (int i = 0; i < 5; i++)
	{
		salesPerson1[i] = 0.0;
		salesPerson2[i] = 0.0;
		salesPerson3[i] = 0.0;

	}
	int choice = -1;
	do
	{

		cout << "Enter Salesperson number (1-3) or other number to quit: ";
		cin >> choice;
		if (choice == 1)
		{
			int productChoice = -1;
			double amount = 0.0;
			cout << "Enter product number (1-5): ";
			cin >> productChoice;
			if (productChoice >= 1 && productChoice <= 5)
			{
				cout << "Enter amount sold : ";
				cin >> amount;
				salesPerson1[productChoice-1] += amount;
			}
			else
			{
				cout << "Wrong product number, please reenter the records";
				continue;
			}
		}
		else if (choice == 2)
		{
			int productChoice = -1;
			double amount = 0.0;
			cout << "Enter product number (1-5): ";
			cin >> productChoice;
			if (productChoice >= 1 && productChoice <= 5)
			{
				cout << "Enter amount sold : ";
				cin >> amount;
				salesPerson2[productChoice-1] += amount;
			}
			else
			{
				cout << "Wrong product number, please reenter the records";
				continue;
			}
		}
		else if (choice == 3)
		{
			int productChoice = -1;
			double amount = 0.0;
			cout << "Enter product number (1-5): ";
			cin >> productChoice;
			if (productChoice >= 1 && productChoice <= 5)
			{
				cout << "Enter amount sold : ";
				cin >> amount;
				salesPerson3[productChoice-1] += amount;
			}
			else
			{
				cout << "Wrong product number, please reenter the records";
				continue;
			}
		}
		else
		{
		}

	} while (choice == 1 || choice == 2 || choice == 3);

	// displaying the records

	cout << "Product\t\tSalesperson 1\t\tSalesperson 2\t\tSalesperson 3\t\t\tTotal\n";
	double totalSP1 = 0.0;
	double totalSP2 = 0.0;
	double totalSP3 = 0.0;
	double totalTotal = 0.0;

	for (int i = 0; i < 5; i++)
	{
		cout <<"\t"<< i + 1 << "\t\t$" << salesPerson1[i] << "\t\t\t$" << salesPerson2[i] << "\t\t\t$" << salesPerson3[i] << "\t\t\t$"<<salesPerson1[i]+salesPerson2[i]+salesPerson3[i]<<"\n";
		totalTotal += salesPerson1[i] + salesPerson2[i] + salesPerson3[i];
		totalSP1 += salesPerson1[i];
		totalSP2 += salesPerson2[i];
		totalSP3 += salesPerson3[i];
	}

	cout << "Total" << "\t\t\t$" << totalSP1 << "\t\t\t$" << totalSP2 << "\t\t\t$" << totalSP3 << "\t\t\t$" << totalTotal << "\n";
	system("pause");
	return 0;
}
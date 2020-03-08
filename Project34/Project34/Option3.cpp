#include <iostream>
using namespace std;

void main()
{
	double totalSales;
	double stateTax;
	double localTax;

	cout << "Please input total sales of the month : " << endl;
	cin >> totalSales;
	cout << "Please input state tax percentage in decimal form (.02 for 2%)" << endl;
	cin >> stateTax;
	cout << "Please input local tax percentage in decimal form (.02 for 2%)" << endl;
	cin >> localTax;

	cout << "Total sales for the month is $" << totalSales << endl;
	cout << "Total state tax for the month is $" << totalSales*stateTax << endl;
	cout << "Total local tax for the month is $" << totalSales*localTax << endl;

	system("pause");
}
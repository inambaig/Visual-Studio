#include<iostream>
using namespace std;
double calculateGrossPay(double hwr, int hours[]) // Function that calculates the gross pay according to the working hours
{
	double grossPay = 0.0;
	for (int i = 0; i < 4; i++)
	{
		if (hours[i]>40)// if working hours are more than 40
		{
			grossPay += (hwr * 40) + (hwr*(hours[i] - 40)*1.5); 
		}
		else// if working hours are equal or less than 40
		{
			grossPay += hwr*hours[i];
		}
	}
	return grossPay;
}
int main()
{
	double hourlyWageRate = 0.0;
	int noOfHours[4] = {0};
	cout << "Please Enter Hourly wage rate :: ";
	cin >> hourlyWageRate;// takes input of hourly wage rate from user 

	for (int i = 0; i < 4; i++)
	{
		cout << "Enter number of hours worked for week "<<i+1<<" :: ";
		cin >> noOfHours[i];// takes input of number of hours from user
	}
	cout << "Gross Pay for the current period is :: "<<calculateGrossPay(hourlyWageRate,noOfHours)<<endl;// calling the function Calculate Gross Pay and output the result

	system("pause");
	return 0;
}
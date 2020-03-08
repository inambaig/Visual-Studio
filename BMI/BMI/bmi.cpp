// This program calculates the bmi according to the input entered by the user. 
// This program also states your current bmi stated. 
// This program also gives range of normal weignt according to entered height.
// The program also suggest gain or loose in weight to approach normal value.
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void main()
{
	cout << fixed;
	cout << setprecision(2);
	while (true)
	{
		double weightInPounds = 0.0;
		double heightInInches = 0.0;
		cout << "Enter weight in pounds : ";
		cin >> weightInPounds;
		cout << "Enter height in inches : ";
		cin >> heightInInches;

		double bmi = (weightInPounds * 703) / (heightInInches*heightInInches);
		cout << "Your body mass index is : " << bmi << endl;
		string status = "";
		if (bmi < 18.5)
			status = "Underweight";
		else if (bmi < 25.0)
			status = "Normal";
		else if (bmi < 30.0)
			status = "Overweight";
		else
			status = "Obese";

		cout << "Your curent status is : " << status << endl;

		double minRange = ((heightInInches*heightInInches)*18.5) / 703;
		double maxRange = ((heightInInches*heightInInches)*25.0) / 703;

		cout << "The normal weight range according to your height is : " << minRange << " - " << maxRange << endl;
		if (status != "Normal")
		{
			if (status == "Underweight")
			{
				cout << "You should gain atleast " << minRange - weightInPounds << " pounds to reach normal bmi status." << endl;
			}
			else
			{
				cout << "You should loose atleast " << weightInPounds - maxRange << " pounds to reach normal bmi status." << endl;
			}
		}
		cout << "Information from the Department of Health and Human Services/National Institutes of Health" << endl << endl << endl;
		cout << "BMI VALUES" << endl;

		cout << "Underweight : less than 18.5" << endl;

		cout << "Normal : in the interval[18.5, 25.0]" << endl;

		cout << "Overweight : in the interval(25.0, 30.0]" << endl;

		cout << "Obese: greater than 30" << endl;
		cout << "My name : Zhenghao Chen"<<endl;
	}
}
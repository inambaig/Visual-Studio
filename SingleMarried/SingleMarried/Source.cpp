//#include <iostream>
//using namespace std;
//
//double calculateTax()
//{
//	double income;
//	int choice = 0;
//	double standardDeduction = 0.0;
//	double deductionForDependants = 0.0;
//	double deduction_oopme = 0.0;
//	double collegeDeduction = 0.0;
//	int numDependents = 0;
//
//	cout << "Please enter income of year : ";
//	cin >> income;
//
//	cout << "Please select one of the following options : \n";
//	cout << "1. Single\n";
//	cout << "2. Married filing separately\n";
//	cout << "3. Married filing jointly\n";
//	cout << "4. Head of household\n\n";
//
//	cin >> choice;
//	cout << "Enter number of dependents : ";
//	cin >> numDependents;
//
//	if (numDependents >= 4)
//		numDependents = 4;
//
//	switch (choice)
//	{
//	case 1:
//		standardDeduction = 2000;
//		deductionForDependants = numDependents * 150;
//		break;
//	case 2:
//		standardDeduction = 1500;
//		deductionForDependants = numDependents * 125;
//		break;
//	case 3:
//		standardDeduction = 2500;
//		deductionForDependants = numDependents * 175;
//		break;
//	case 4:
//		standardDeduction = 3000;
//		deductionForDependants = numDependents * 175;
//		break;
//	default:
//		break;
//	}
//	char decision = ' ';
//	cout << "Did you have any uncovered medical expenses? [y/n]:"; cin >> decision;
//	if (decision == 'y')
//	{
//		cout << "Enter amount of out-of-pocket medical expenses : ";
//		cin >> deduction_oopme;
//		deduction_oopme = deduction_oopme*0.1;
//	}
//
//	cout << "Were you a full time student during the year? [y/n]:"; cin >> decision;
//	if (decision == 'y')
//	{
//		cout << "Enter amount of college expenses : ";
//		cin >> collegeDeduction;
//		collegeDeduction = collegeDeduction*0.1;
//	}
//	double saved = income - deductionForDependants - deduction_oopme - collegeDeduction - standardDeduction;
//	double tax = 0.0;
//	if (saved <= 10000)
//	{
//		tax = 0.0;
//		return tax;
//	}
//	else
//	{
//		if (saved - 20000 < 0)
//		{
//			tax = saved*0.1;
//			return tax;
//		}
//		else
//		{
//			tax = 20000 * 0.1;
//			saved = saved - 20000;
//			if (saved - 30000 < 0)
//			{
//				tax = tax + (saved * 0.15);
//			}
//			else
//			{
//				tax = tax + (30000 * 0.15);
//				saved = saved - 30000;
//				if (saved - 50000 < 0)
//				{
//					tax = tax + (saved * 0.2);
//				}
//				else
//				{
//					tax = tax + (50000 * 0.2);
//					saved = saved - 50000;
//					tax = tax + saved * 0.3;
//				}
//			}
//			return tax;
//		}
//	}
//}
//void main()
//{
//	cout << "The tax is : " << calculateTax() << endl;
//	system("pause");
//}

#include "bankAccount.h"
void main()
{
	bankAccount bankArray[10];
	string name;
	string accountType;
	double balance;
	double interest;
	int accounts = 0;
	while (true)
	{
		cout << endl;
		cout << "1. Add an account" << endl;
		cout << "2. Display an account Information" << endl;
		cout << "3. Deposit Funds" << endl;
		cout << "4. Withdraw Funds" << endl;
		cout << "Any other number to quit.";
		int choice = 0;
		cout << endl;
		cout << "Enter your choice.";
		cin >> choice;

		if (choice == 1)
		{
			cout << endl;
			cout << "Enter details for Account Number " << accounts + 1 << endl << endl;
			cout << "Enter Account Holder Name : ";
			cin >> name;
			cout << "Enter Account Type(checking/saving) : ";
			cin >> accountType;
			cout << "Enter Account balance : ";
			cin >> balance;
			cout << "Enter interest rate : ";
			cin >> interest;
			bankArray[accounts++].setData(name, accountType, balance, interest);
		}

		else if (choice == 2)
		{
			cout << endl;
			int accNum = 0;
			cout << "Enter account number ";
			cin >> accNum;
			bankArray[accNum - 1].print();
		}

		else if (choice == 3)
		{
			cout << endl;
			int accNum = 0;
			cout << "Enter account number ";
			cin >> accNum;
			double amount = 0;
			cout << "Enter amount to deposit : ";
			cin >> amount;
			cout << "Before deposit ";
			bankArray[accNum - 1].print();

			bankArray[accNum - 1].deposit(amount);
			cout << "After deposit ";
			bankArray[accNum - 1].print();
		}
		else if (choice == 4)
		{
			cout << endl;
			int accNum = 0;
			cout << "Enter account number ";
			cin >> accNum;
			double amount = 0;
			cout << "Enter amount to withdraw : ";
			cin >> amount;
			cout << "Before withdraw ";
			bankArray[accNum - 1].print();

			bankArray[accNum - 1].withdraw(amount);
			cout << "After withdraw ";
			bankArray[accNum - 1].print();
		}

		else
		{
			break;
		}


	}
}
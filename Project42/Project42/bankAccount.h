#pragma once

#include <iostream>
#include <string>
using namespace std;
class bankAccount
{
	static int accountNumberAssigner;
	string accountHolderName;
	int accountNumber;
	string accountType;
	double balance;
	double interestRate;
public:

	bankAccount();
	bankAccount(string, string, double, double);
	void setData(string, string, double, double);
	void deposit(double);
	void withdraw(double);
	double getInterestRate();
	double getBalance();
	string getAccountName();
	string getAccountType();
	int getAccountNumber();
	void print();
	~bankAccount();
};


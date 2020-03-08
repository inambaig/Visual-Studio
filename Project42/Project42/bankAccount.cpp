#include "bankAccount.h"


bankAccount::bankAccount()
{
	this->accountNumber = 0;
	this->accountHolderName = "";
	this->accountType = "";
	this->balance = 0.0;
	this->interestRate = 0.0;
}

int bankAccount::accountNumberAssigner = 1;
bankAccount::bankAccount(string accountHolderName, string accountType, double balance, double interestRate)
{
	setData(accountHolderName, accountType, balance, interestRate);
}
void bankAccount::setData(string accountHolderName, string accountType, double balance, double interestRate)
{
	this->accountNumber = accountNumberAssigner++;
	this->accountHolderName = accountHolderName;
	this->accountType = accountType;
	this->balance = balance;
	this->interestRate = interestRate;
}

void bankAccount::deposit(double amount)
{
	balance += amount;
}
void bankAccount::withdraw(double amount)
{
	balance -= amount;
}
double bankAccount::getInterestRate()
{
	return interestRate;
}
double bankAccount::getBalance()
{
	return balance;
}
string bankAccount::getAccountName()
{
	return accountHolderName;
}
string bankAccount::getAccountType()
{
	return accountType;
}
int bankAccount::getAccountNumber()
{
	return accountNumber;
}
void bankAccount::print()
{
	cout << "Account Number : " << accountNumber << endl;
	cout << "Account Holder Name : " << accountHolderName << endl;
	cout << "Account Type : " << accountType << endl;
	cout << "Account Balance : " << balance << endl;
	cout << "Interest Rate : " << interestRate << endl;
}
bankAccount::~bankAccount()
{
}

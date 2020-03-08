#include <iostream>
#include <string>
using namespace std;

struct Date {
private:
	int year;
	int month;
	int day;
	const int NMONTHS = 12;
	int numDays[12];
public:

	Date(){
		year = 1;
		month = 1;
		day = 1;
		numDays[0] = 31;
		numDays[1] = 28;
		numDays[2] = 31;
		numDays[3] = 30;
		numDays[4] = 31;
		numDays[5] = 30;
		numDays[6] = 31;
		numDays[7] = 31;
		numDays[8] = 30;
		numDays[9] = 31;
		numDays[10] = 30;
		numDays[11] = 31;

	}

	bool isLeapYear()
	{
		if (year % 400 == 0)
			return true;
		if (year % 100 == 0)
			return false;
		if (year % 4 == 0)
			return true;
		return false;
	}

	bool setDate(int month, int day, int year) {
		if (month <= 0 || month>NMONTHS){
			cout << "Error!!! Month is not valid" << endl;
		}
		else if (year<1900 || year>2025){
			cout << "Error!!! Year is not valid" << endl;
		}
		else{
			this->year = year;
			this->month = month;
			if (isLeapYear()){
				numDays[1] = 29;
				cout << year << " -> Leap Year!" << endl;
			}
			else
				cout << year << " -> NOT Leap Year!" << endl;

			if (day <= 0 || day>numDays[month - 1]){
				cout << day << " is not a valid day of " << nameOfMonth(month) << endl;
			}
			else{
				this->day = day;
				return true;
			}
		}
		return false;
	}
	string nameOfMonth(int month){
		string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		return months[month-1];
	}
	void USDateDisplay(){
		cout << "US date format : ";
		if (month<9){
			cout << "0" << month;
		}
		else{
			cout << month;
		}
		cout << "/";
		if (day<9){
			cout << "0" << day;
		}
		else{
			cout << day;
		}
		cout << "/";
		cout << year << endl;

	}

	void USDisplay(){
		if (month<9){
			cout << "0" << month;
		}
		else{
			cout << month;
		}
		cout << "/";
		if (day<9){
			cout << "0" << day;
		}
		else{
			cout << day;
		}
		cout << "/";
		cout << year << " (US)." << endl;

	}

	void USExpanded(){
		cout << nameOfMonth(month) << " " << day << "," << year << " (US Expanded)." << endl;
	}

	void International(){
		cout << year << "-" << month << "-" << day << " (International)." << endl;
	}
	void USMilitary(){
		cout << day << " " << nameOfMonth(month) << " " << year << " (US Military)." << endl;
	}
};


int main(){


	char tryAgain = 'y';
	while (tryAgain == 'y' || tryAgain == 'Y')
	{
		cout << "The program displays a valid date in three different formats." << endl;
		cout << "Note: All junk data will be rejected!" << endl;
		int month, day, year;
		string dateString = "";
		Date date;
		cout << "Enter a date (mm/dd/yyyy) or -1 to end : ";
		cin >> dateString;
		cout << endl;
		if (dateString == "-1")
		{
			break;
		}
		if (dateString.length() < 10)
		{
			cout << "Invalid date/ wrong format: For both month and day, use two digits.\nRe-";
			continue;
		}
		string subStr = "";
		subStr += dateString[0];
		subStr += dateString[1];
		month = stoi(subStr);
		subStr = "";
		subStr += dateString[3];
		subStr += dateString[4];
		day = stoi(subStr);
		subStr = "";
		subStr += dateString[6];
		subStr += dateString[7];
		subStr += dateString[8];
		subStr += dateString[9];
		year = stoi(subStr);
		if (date.setDate(month, day, year)){
			cout << "Date:" << month << "/" << day << "/" << year << " is valid." << endl << endl;
			date.USDisplay();
			date.USExpanded();
			date.USMilitary();
			date.International();
		}
		else{
			cout << "\nError!!! The entered date is invalid! Re-Enter, Please!" << endl << endl;
			continue;
		}
		cout << "Run again (y/n)?";
		cin >> tryAgain;
	}
	cout << "Programmer: Ziwei Liu – What's the Date" << endl;
	cout << "Press <enter> key to end" << endl;
	system("pause");
}
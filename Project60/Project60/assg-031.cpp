/**
* @author Jane Programmer
* @cwid   123 45 678
* @class  COSC 2336, Spring 2019
* @ide    Visual Studio Community 2017
* @date   January 12, 2019
* @assg   Assignment 03
*
* @description Assignment 03
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "LargeInteger.hpp"

using namespace std;


/** main
* The main entry point for this program.  Execution of this program
* will begin with this main function.
*
* @param argc The command line argument count which is the number of
*     command line arguments provided by user when they started
*     the program.
* @param argv The command line arguments, an array of character
*     arrays.
*
* @returns An int value indicating program exit status.  Usually 0
*     is returned to indicate normal exit and a non-zero value
*     is returned to indicate an error condition.
*/
int main(int argc, char** argv)
{
	// test constructors, destructors and tostring()
	cout << "Testing Constructors, tostring() and destructor:" << endl;
	cout << "-------------------------------------------------------------" << endl;
	LargeInteger li1(3483);
	cout << "li1 = " << li1.tostring() << endl;
	assert(li1.tostring() == "3483");

	int digits2[] = {8, 4, 6, 3, 8, 4, 7, 4, 1, 2};
	LargeInteger li2(10, digits2);
	cout << "li2 = " << li2.tostring() << endl;
	assert(li2.tostring() == "2147483648");

	LargeInteger* li3 = new LargeInteger(193839);
	cout << "li3 = " << li3->tostring() << endl;
	assert(li3->tostring() == "193839");
	delete li3; // should invoke the class destructor


	// test maxDigits() member function
	cout << endl;
	cout << "Testing maxDigits() member function" << endl;
	cout << "-------------------------------------------------------------" << endl;
	int maxDigits;
	maxDigits = li1.maxDigits(li2);
	cout << "The maximum digits between l1 and l2 is: " << maxDigits << endl;
	assert(maxDigits == 10);

	LargeInteger li4(398298312);
	int digits5[] = {3, 3, 1, 4, 2, 1, 5, 1, 2, 4, 7, 6, 9, 3, 9, 5, 6};
	LargeInteger li5(17, digits5);
	cout << "li4 = " << li4.tostring() << " and li5 = " << li5.tostring() << endl;
	maxDigits = li5.maxDigits(li4);
	cout << "The maximum digits between l5 and l4 is: " << maxDigits << endl;
	assert(maxDigits == 17);


	// test digitAtPlace() member function
	cout << endl;
	cout << "Testing digitAtPlace() member function" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "li5[0] == " << li5.digitAtPlace(0) << endl;
	assert(li5.digitAtPlace(0) == 3);
	cout << "li5[16] == " << li5.digitAtPlace(16) << endl;
	assert(li5.digitAtPlace(16) == 6);
	cout << "li5[17] == " << li5.digitAtPlace(17) << endl;
	assert(li5.digitAtPlace(17) == 0);
	cout << "li5[4] == " << li5.digitAtPlace(4) << endl;
	assert(li5.digitAtPlace(4) == 2);
	cout << "li5[10] == " << li5.digitAtPlace(10) << endl;
	assert(li5.digitAtPlace(10) == 7);
	cout << "li5[25] == " << li5.digitAtPlace(25) << endl;
	assert(li5.digitAtPlace(25) == 0);
	cout << "li5[-1] == " << li5.digitAtPlace(-1) << endl;
	assert(li5.digitAtPlace(-1) == 0);
	cout << endl;

	cout << "li4[0] == " << li4.digitAtPlace(0) << endl;
	assert(li4.digitAtPlace(0) == 2);
	cout << "li4[8] == " << li4.digitAtPlace(8) << endl;
	assert(li4.digitAtPlace(8) == 3);
	cout << "li4[9] == " << li4.digitAtPlace(9) << endl;
	assert(li4.digitAtPlace(9) == 0);
	cout << "li4[2] == " << li4.digitAtPlace(2) << endl;
	assert(li4.digitAtPlace(2) == 3);
	cout << "li4[33] == " << li4.digitAtPlace(33) << endl;
	assert(li4.digitAtPlace(33) == 0);
	cout << "li4[-5] == " << li4.digitAtPlace(-5) << endl;
	assert(li4.digitAtPlace(-5) == 0);


	// test append digit
	cout << endl;
	cout << "Testing appending digits appendDigit() member function" << endl;
	cout << "-------------------------------------------------------------" << endl;
	li5.appendDigit(1);
	cout << "li5 after appendDigit(1) = " << li5.tostring() << endl;
	assert(li5.tostring() == "165939674215124133");
	li5.appendDigit(0);
	cout << "li5 after appendDigit(0) = " << li5.tostring() << endl;
	assert(li5.tostring() == "165939674215124133");

	li4.appendDigit(7);
	cout << "li4 after appendDigit(7) = " << li4.tostring() << endl;
	assert(li4.tostring() == "7398298312");
	li4.appendDigit(0);
	cout << "li4 after appendDigit(0) = " << li4.tostring() << endl;
	assert(li4.tostring() == "7398298312");


	// test addition operator
	cout << endl;
	cout << "Testing LargeInteger addition add() member function" << endl;
	cout << "-------------------------------------------------------------" << endl;
	LargeInteger li6 = li4.add(li5);
	cout << "Addition of li4 + li5 = " << li6.tostring() << endl;
	assert(li6.tostring() == "165939681613422445");

	LargeInteger li7 = li5.add(li4);
	cout << "Addition of li5 + li4 = " << li7.tostring() << endl;
	assert(li7.tostring() == "165939681613422445");

	assert(li6.tostring() == li7.tostring());

	// test carry
	LargeInteger li8(999999999);
	int digits9[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};
	LargeInteger li9(9, digits9);

	cout << setw(12) << right << li8.tostring() << endl;
	cout << "+" << setw(11) << right << li9.tostring() << endl;
	cout << "------------" << endl;
	LargeInteger li10 = li8.add(li9);
	cout << setw(12) << right << li10.tostring() << endl;
	cout << endl;

	// return 0 to indicate successful completion

	return 0;
}
/**
* @author Jane Programmer
* @cwid   123 45 678
* @class  COSC 2336, Spring 2019
* @ide    Visual Studio Community 2017
* @date   January 12, 2019
* @assg   Assignment 03
*
* @description LargeInteger class.  Represent an arbitrarily large
*   (signed) integer.  This class keeps the digits of the integer in
*   an array of integers internally.  The array of integers is
*   dynamically resized as necessary during LargeInteger operations.
*   This abstract data type supports addition of large integers.
*/
#ifndef _LARGEINTEGER_H_
#define _LARGEINTEGER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;


/** LargeInteger class.
*
* @param id Private member integer variable, this is not strictly needed
*   for this class, but we assign a unique id to each instance of
*   LargeInteger that is created, so that you can more easily see how
*   the destructor works and is being called.  You should set the
*   id and increment it in any constructors you create for this class.
* @param numDigits Private member integer variable, contains the number
*   of digits currently in the LargeInteger, or equivalently, the size
*   of they digits array of integers.
* @param digits A dynamically allocated array of integers.  This array
*   holds the digits of the large integer this object represents.  The
*   digits in the array are orderd such that the 1's place (10^0) is in
*   index 0 of the array, the 10's place (10^1) is in the index 1, and so
*   on.
*/
class LargeInteger
{
private:
	int id;
	int numDigits;  // number of digits in LargeInt / size of alloc array
	int* digits;    // the digits of the LargeInt we are representing

public:
	LargeInteger(int value);
	string tostring();
	LargeInteger(int size, int *digits);
	int maxDigits(LargeInteger &other);
	int digitAtPlace(int index);
	void appendDigit(int digit);
	LargeInteger& add(LargeInteger &other);
	~LargeInteger();
};

#endif
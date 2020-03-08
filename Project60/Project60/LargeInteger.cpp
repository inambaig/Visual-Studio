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
#include "LargeInteger.hpp"
#include <conio.h>
using namespace std;


// integer to create unique id for new LargeInteger instances
// please set and use this in the same way in the constructor you
// create for this assignment
static int nextLargeIntegerId = 1;

/** LargeInteger constructor
* Constructor for LargeInteger class that takes a simple built-in
* integer to be used as the initial value of the large integer.
*
* @param value A regular (32-bit) integer that we will use as the
*    initial value of this LargeInteger data type.
*/
LargeInteger::LargeInteger(int value)
{
	// set this instance id
	id = nextLargeIntegerId++;

	// first determine number of digits, so we know what size of array
	// to construct dynamically
	// https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
	numDigits = (int)log10((double)value) + 1;

	// allocate an array of the right size
	digits = new int[numDigits];

	// iterate through the digits in value, putting them into our
	// array of digits.
	int digit;
	for (int digitIndex = 0; digitIndex < numDigits; digitIndex++)
	{
		// least significant digit
		digit = value % 10;
		digits[digitIndex] = digit;

		// integer division to chop of least significant digit
		value = value / 10;
	}
}

LargeInteger::LargeInteger(int size, int *digits)
{
	id = nextLargeIntegerId++;
	numDigits = size;
	this->digits = new int[size];
	for (int i = 0; i<size; i++)
		this->digits[i] = digits[i];

}

int LargeInteger::maxDigits(LargeInteger &other)
{
	if (numDigits > other.numDigits)
		return numDigits;
	else
		return other.numDigits;
}


int LargeInteger::digitAtPlace(int index)
{
	if (index >= 0 && index < numDigits)
		return digits[index];
	else
		return 0;
}


void LargeInteger::appendDigit(int digit)
{
	if (digit != 0)
	{
		int *temp = new int[numDigits + 1];
		for (int i = 0; i<numDigits; i++)
			temp[i] = digits[i];

		delete[] digits;
		temp[numDigits] = digit;
		numDigits++;
		digits = temp;
	}
}

LargeInteger& LargeInteger::add(LargeInteger &other)

{
	int partialSum = 0;
	int carry = 0;
	LargeInteger *addResult;
	int i = 0;
	if (numDigits > other.numDigits)
	{
		addResult = new LargeInteger(this->numDigits, this->digits);
		for (i = 0; i<other.numDigits; i++)
		{
			partialSum = addResult->digitAtPlace(i) + other.digits[i] + carry;
			if (partialSum > 9)
			{
				addResult->digits[i] = partialSum % 10;
				carry = partialSum / 10;
			}
			else
			{
				addResult->digits[i] = partialSum;
				carry = 0;
			}
		}
		while (carry > 0 && (i < numDigits))
		{
			partialSum = addResult->digitAtPlace(i) + carry;
			addResult->digits[i] = partialSum % 10;
			carry = partialSum / 10;
			i++;
		}
	}
	else
	{
		addResult = new LargeInteger(other.numDigits, other.digits);
		for (i = 0; i<numDigits; i++)
		{
			partialSum = addResult->digitAtPlace(i) + digits[i] + carry;
			if (partialSum > 9)
			{
				addResult->digits[i] = partialSum % 10;
				carry = partialSum / 10;
			}
			else
			{
				addResult->digits[i] = partialSum;
				carry = 0;
			}
		}
		while (carry > 0 && (i < other.numDigits))
		{
			partialSum = addResult->digitAtPlace(i) + carry;
			addResult->digits[i] = partialSum % 10;
			carry = partialSum / 10;
			i++;
		}
	}
	addResult->appendDigit(carry);
	return *addResult;
}

string LargeInteger::tostring()
{
	string resultString = "";
	for (int i = 0; i<numDigits; i++)
	{
		stringstream ss;
		ss << digits[i];
		resultString = ss.str() + resultString;
	}
	return resultString;
}
/** LargeInteger destructor
* Destructor for the LargeInteger class.  Make sure we are good
* managers of memory by freeing up our digits when this object
* goes out of scope.
*/
LargeInteger::~LargeInteger()
{
	// We display a log message to track destructor invocation.  In
	// a real application we might send this to a log file, and parameterize
	// whether to log these type of events or not.
	cout << "<LargeInteger::~LargeInteger> destructor entered, freeing my digits" << endl
		<< "     id = " << id << endl
		//<< "     value=" << tostring() // uncomment this after you implement tostring()
		<< endl;
	delete[] this->digits;
	_getch();
}

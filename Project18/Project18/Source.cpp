#include<iostream> 
#include <string>
using namespace std;
class LongInt 
{
private:
	struct digit { int d_val; digit *more, *less; };
	struct Ibase { digit *most, *least; };
	Ibase _base;
	void zeroStrip();
public: 
	LongInt(); 
	friend void printLongInt(LongInt); 
	friend LongInt inputLongInt(); 
	friend LongInt addLongInt(LongInt, LongInt);
};
void LongInt::zeroStrip()
{
	LongInt::digit * dptr = _base.most; 
	LongInt::digit * extra = 0;
	while ((!dptr->d_val) && dptr->less) 
	{
		extra = dptr; 
		_base.most = dptr->less; 
		dptr = dptr->less; 
		dptr->more = 0; 
	}
}
LongInt::LongInt()
{
	_base.most = _base.least = new digit; 
	_base.most->d_val = 0; 
	_base.most->more = _base.most->less = 0; 
};
void printLongInt(LongInt LIval)
{
	LongInt::digit * dptr = LIval._base.most;
	while (dptr) 
	{
		cout << dptr->d_val; 
		dptr = dptr->less; 
	}
}
LongInt inputLongInt()
{
	LongInt returnValue; 
	int inValue; 
	LongInt::digit * dptr = 0; 
	LongInt::digit * inputList = 0; 
	inputList = returnValue._base.least;
	inValue = cin.get();
	while ('0' <= inValue && inValue <= '9')
	{
		dptr = new LongInt::digit; 
		dptr->d_val = inValue - '0'; 
		dptr->less = 0; 
		dptr->more = inputList; 
		returnValue._base.least = dptr; 
		inputList->less = dptr; 
		inputList = dptr; 
		inValue = cin.get(); 
	}
	returnValue.zeroStrip();
		return returnValue;
}
LongInt addLongInt(LongInt s1, LongInt s2)
{
	LongInt returnValue;
	LongInt::digit * l1 = s1._base.most;
	LongInt::digit * l2 = s2._base.most;
	LongInt::digit * inputList;
	LongInt::digit * dptr = 0;
	inputList = returnValue._base.least;
	while (l1->less)
	{
		l1 = l1->less;
	}
	while (l2->less)
	{
		l2 = l2->less;
	}
	int carry = 0;
	while (l1 && l2)
	{
		int sum = l1->d_val + l2->d_val + carry;

		l1 = l1->more;
		l2 = l2->more;
		int sum1 = sum % 10;
		carry = sum / 10;

		dptr = new LongInt::digit;
		dptr->d_val = sum1;
		//dptr->more = 0;
		dptr->less = inputList;
		returnValue._base.most = dptr;
		inputList->more = dptr;
		inputList = dptr;
		//cout << sum1;
	}
	if (!l1 && l2)
	{
		while (l2)
		{
			int sum = l2->d_val + carry;
			l2 = l2->more;
			int sum1 = sum % 10;
			carry = sum / 10;
			//cout << sum1;
			dptr = new LongInt::digit;
			dptr->d_val = sum1;
			//dptr->more = 0;
			dptr->less = inputList;
			returnValue._base.most = dptr;
			inputList->more = dptr;
			inputList = dptr;
		}
	}
	if (l1 && !l2)
	{
		while (l1)
		{
			int sum = l1->d_val + carry;
			l1 = l1->more;
			int sum1 = sum % 10;
			carry = sum / 10;
			//cout << sum1;
			dptr = new LongInt::digit;
			dptr->d_val = sum1;
			//dptr->more = 0;
			dptr->less = inputList;
			returnValue._base.most = dptr;
			inputList->more = dptr;
			inputList = dptr;
		}
	}
	if (carry != 0)
	{
		dptr = new LongInt::digit;
		dptr->d_val = carry;
		//dptr->more = 0;
		dptr->less = inputList;
		returnValue._base.most = dptr;
		inputList->more = dptr;
		inputList = dptr;
	}
	returnValue._base.least->more->less = 0;
	returnValue.zeroStrip();
	return returnValue;
}
int main(){
	LongInt summand1, summand2, sum;
	cout << "-> " << flush;
	summand1 = inputLongInt();
	cout << "-> " << flush;
	summand2 = inputLongInt();
	cout << "\n-----\n";
	sum = addLongInt(summand1, summand2);
	printLongInt(sum);
	cout << endl;
	system("pause");
}
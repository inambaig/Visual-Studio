#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
	for (int i = 0; i < s.length()/2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}



void main()
{
	string input;
	cout << "Enter a string : ";
	cin >> input;
	if (isPalindrome(input))
		cout << "Entered string is a palindrome." << endl;
	else
		cout << "Entered string is not a palindrome." << endl;
	system("pause");
}
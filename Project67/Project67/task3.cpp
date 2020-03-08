#include <iostream>
#include <string>
using namespace std;

void reverse(string &s)
{
	for (int i = 0; i < s.length()/2; i++)
	{
		char s1 = s[s.length() - 1 - i];
		s[s.length() - 1 - i] = s[i];
		s[i] = s1;
	}
}



void main()
{
	string input;
	cout << "Enter a string : ";
	cin >> input;
	reverse(input);
	cout << "Reversed string = " << input << endl;
	system("pause");
}
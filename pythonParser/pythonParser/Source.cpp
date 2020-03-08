#include <iostream>
#include <list> 
#include <string>
using namespace std;

struct variable{
	string variableName;
	string variableType;
};

bool containsQuote(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '"')
			return true;
	}
	return false;
}

bool containsDecimal(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			return true;
	}
	return false;
}

bool containsEqual(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '=')
			return true;
	}
	return false;
}

bool isList(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
			if (s[i + 1] != ']')
				return true;
	}
	return false;
}

bool allNumbers(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!((s[i] >= 48 && s[i] <= 57)))
			return false;
	}
	return true;
}

void splitString(string s, string& before, string &after)
{
	bool check = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '=')
			check = true;
		else if (check == false)
			before += s[i];
		else if (check)
			after += s[i];
	}
}

string checkVariables(list<variable> variables, string element)
{
	list <variable> ::iterator it;
	for (it = variables.begin(); it != variables.end(); ++it)
	{
		if (it->variableName == element)
		{
			return it->variableType;
		}
	}
	return "";
}

void splitElement(string element, list<string> &ls)
{
	string x = "";
	for (int i = 0; i < element.length(); i++)
	{
		if (element[i] == '+' || element[i] == '-' || element[i] == '*' || element[i] == '/')
		{
			ls.push_back(x);
			x = "";
		}
		else
		{
			x = x + element[i];
		}
	}
	ls.push_back(x);
}

string getVariableType(list <string> ls)
{
	ls.sort();
	if (ls.front() == ls.back())
		return ls.front();
	else
		return "unknown";
}

bool contains(list<variable> variables, string element)
{
	list <variable> ::iterator it;
	for (it = variables.begin(); it != variables.end(); ++it)
	{
		if (it->variableName == element)
		{
			return true;
		}
	}
	return false;
}

string removeSpaces(string line)
{
	string xx = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] != ' ')
			xx += line[i];
	}
	return xx;
}

int main()
{
	string line = "";
	list<variable> variables;
	list <string> gqlist1;
	while (getline(std::cin, line))
	{

		gqlist1.push_back(removeSpaces(line));
	}

	list <string> ::iterator it;
	for (it = gqlist1.begin(); it != gqlist1.end(); ++it)
	{
		string s = *it;
		if (containsEqual(s))
		{
			string before;
			string after1;
			splitString(s, before, after1);
			list<string> elements;
			splitElement(after1, elements);
			list<string> types;
			list <string> ::iterator it1;
			for (it1 = elements.begin(); it1 != elements.end(); ++it1)
			{
				if (checkVariables(variables, *it1) != "")
				{
					types.push_back(checkVariables(variables, *it1));
				}
				else
				{
					string after = *it1;
					if (isList(after)){

						types.push_back("list");
					}
					else if (containsQuote(after))
					{
						types.push_back("string");
					}
					else if (allNumbers(after))
					{
						if (containsDecimal(after))
						{
							types.push_back("float");
						}
						else
						{
							types.push_back("int");
						}
					}
					else
					{
						types.push_back("unknown");
					}
				}
			}

			if (!contains(variables, before))
			{
				variable v;
				v.variableName = before;
				v.variableType = getVariableType(types);
				variables.push_back(v);
			}
		}
		

	}
	list <variable> ::iterator it1;

	for (it1 = variables.begin(); it1 != variables.end(); ++it1)
	{
		cout << it1->variableName << " : " << it1->variableType << endl;
	}
	system("pause");
	return 0;
}
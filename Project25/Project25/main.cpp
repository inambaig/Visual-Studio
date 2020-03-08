#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Stack.h"

using namespace std;

bool lowerPrec(string s1, string s2) {
	if (((s1 == "+") || (s1 == "-")) && ((s2 == "*") || (s2 == "/"))) return true;
	return false;
}

string convertToPostFix(string s) {
	stringstream ss;
	ss.str(s);
	ss.seekg(0);
	string item;
	string postFixExpr = "";
	Stack<string> stack1;
	while (getline(ss, item, ' ')) {
		if (item == "(") stack1.push(item);
		else if (item == "+" || item == "-") {
			string next;
			while (true) {
				stack1.peek(next);
				if (!(next == "+" || next == "-" || next == "*" || next == "/")) break;
				if (lowerPrec(next, item)) break;
				stack1.pop(next);
				postFixExpr = postFixExpr + " " + next;
			}
			stack1.push(item);
		}
		else if (item == "*" || item == "/") {
			string next;
			while (true) {
				stack1.peek(next);
				if (!(next == "+" || next == "-" || next == "*" || next == "/")) break;
				if (lowerPrec(next, item)) break;
				stack1.pop(next);
				postFixExpr = postFixExpr + " " + next;
			}
			stack1.push(item);
		}
		else if (item == ")") {
			string next;
			while (true) {
				stack1.pop(next);
				if (next == "(") break;
				postFixExpr = postFixExpr + " " + next;
			}
			if (stack1.isEmpty()) break;
		}
		else { // it is a number
			postFixExpr = postFixExpr + " " + item;
		}
	}
	return postFixExpr;
}
bool isInteger(string expr, int index)
{
	if (expr[index] >= 48 && expr[index] <= 57)
		return true;
	return false;
}
bool isSpace(string expr, int index)
{
	if (expr[index] == ' ')
		return true;
	return false;
}

bool isOperator(string expr, int index)
{
	if (expr[index] == '+' || expr[index] == '-' || expr[index] == '*' || expr[index] == '/')
		return true;
	return false;
}
int getInteger(string expr, int &index)
{
	int result = 0;
	for (int i = index; i < expr.length(); i++)
	{
		if (expr[i] >= 48 && expr[i] <= 57)
		{
			result = result * 10;
			result += expr[i] - 48;
			index = i;
		}
		else
			break;
	}
	return result;
}
int eval(string expr) {
	Stack<int> stack1;

	for (int i = 0; i < expr.length(); i++)
	{
		if (isInteger(expr, i))
		{
			stack1.push(getInteger(expr, i));
			continue;
		}
		else if (isSpace(expr, i))
		{
			continue;
		}
		else if (isOperator(expr, i))
		{
			if (expr[i] == '+')
			{
				int first = 0;
				stack1.pop(first);
				int second = 0;
				stack1.pop(second);
				stack1.push(first+second);
			}
			else if(expr[i] == '-')
			{
				int first = 0;
				stack1.pop(first);
				int second = 0;
				stack1.pop(second);
				stack1.push(first - second);
			}
			else if (expr[i] == '*')
			{
				int first = 0;
				stack1.pop(first);
				int second = 0;
				stack1.pop(second);
				stack1.push(first * second);
			}
			else if (expr[i] == '/')
			{
				int first = 0;
				stack1.pop(first);
				int second = 0;
				stack1.pop(second);
				stack1.push(first / second);
			}
		}
	}
	int result = 0;
	stack1.peek(result);
	return result;
}

int main()
{
	string s;
	getline(cin, s);
	string postFixExpr = convertToPostFix(s);
	cout << "Final postFixExpr = " << postFixExpr << endl;
	int res = eval(postFixExpr);
	cout << "result = " << res << endl;
	system("pause");
	return 0;
}

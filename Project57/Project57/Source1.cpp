//#include<stdio.h>
//#include<conio.h>
//#include<fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//
//struct automaton{
//
//	int numSymbols;
//	char symbol[10];
//	int numStates, numFinalStates;
//	int final[10];
//	int acptor[10][10];
//
//}aObj;
//struct state{
//	int state;
//}sObj;
//struct transition{
//	int start;
//	char symbol;
//	int destination;
//}tObj;
//
//
//string input1;
//
//
//void takeInput()
//{
//	printf("\nTotal Number of DFA states : ");
//	scanf_s("%d", &aObj.numStates);
//	printf("\nStates of DFA are as follows : ");
//
//	printf("%d", 0);
//	for (int i = 1; i < numStates; i++)
//		printf(", %d", i);
//
//	printf("\nTotal number of symbols : ");
//	scanf_s("%d", &numSymbols);
//	printf("\nEnter input symbols\n");
//	for (int i = 0; i < numSymbols; i++)
//	{
//		printf("Symbol # %d : ", i + 1);
//		cin >> symbol[i];
//	}
//	printf("Total number of final states : ");
//	scanf_s("%d", &numFinalStates);
//	for (int i = 0; i < numFinalStates; i++)
//	{
//		printf("Final state # %d : ", i + 1);
//		scanf_s("%d", &final[i]);
//	}
//	printf("\nInput Transition Rule\n");
//	for (int i = 0; i < numSymbols; i++)
//	{
//		for (int j = 0; j < numStates; j++)
//		{
//			printf("Enter destination state of starting state being %d with symbol %c \n", j, symbol[i]);
//			scanf_s("%d", &acptor[i][j]);
//		}
//	}
//}
//
//void readFromFile()
//{
//	std::ifstream in("input.txt");
//	in >> numStates;
//	in >> numSymbols;
//
//	printf("\nStates of DFA are as follows : ");
//	for (int i = 0; i < numStates; i++)
//		printf("%d", i);
//
//	for (int i = 0; i < numSymbols; i++)
//	{
//		in >> symbol[i];
//		printf("Symbol # %d : ", i + 1);
//		printf("%c", symbol[i]);
//	}
//	in >> numFinalStates;
//
//	for (int i = 0; i < numFinalStates; i++)
//	{
//		printf("Final state # %d : ", i + 1);
//		in >> final[i];
//		printf("%d", &final[i]);
//	}
//	printf("Transition Rule\n");
//	for (int i = 0; i < numSymbols; i++)
//	{
//		for (int j = 0; j < numStates; j++)
//		{
//			printf("Enter destination state of starting state being %d with symbol %c is %d \n", j, symbol[i], acptor[i][j]);
//		}
//	}
//}
//
//int checkInput(char m, int n)
//{
//	int j;
//	for (j = 0; j < numSymbols; j++)
//	if (m == symbol[j])
//		return(acptor[j][n]);
//	return -1;
//}
//
//int main()
//{
//	takeInput();
//	do
//	{
//		int s = 0;
//		int i = 0;
//		bool isFinal = false;
//		printf("\nEnter the string to check : ");
//		cin >> input1;
//		for (int j = 0; j < input1.length(); j++)
//		{
//			s = checkInput(input1[i++], s);
//		}
//		for (i = 0; i < numFinalStates; i++)
//		if (final[i] == s)
//			isFinal = true;
//		if (isFinal == true)
//			printf("\nEntered string is a valid string");
//		else
//			printf("\nEntered string is invalid");
//		printf("\nDo you want to try it again? (y/n) ");
//	} while (_getch() == 'y');
//	_getch();
//}

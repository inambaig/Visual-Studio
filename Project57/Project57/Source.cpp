//#include<stdio.h>
//#include<conio.h>
//#include<fstream>
//#include <iostream>
//#include <string>
//using namespace std;
//// struct for the state
//struct state{
//	int statee;
//}sObj;
////struct to store transition
//struct transition{
//	int start;
//	char symbol;
//	int destination;
//
//	// returns the destination of a transition
//	int getDestination(int start, char symbol)
//	{
//		return destination;
//	}
//	// set the source, destination and symbol of each transition
//	void setDestination(int start, char symbol, int destination)
//	{
//		this->start = start;
//		this->destination = destination;
//		this->symbol = symbol;
//	}
//}tObj;
//// struct to store automaton
//struct automaton{
//
//	int numSymbols;
//	char* symbol;
//	int numStates, numFinalStates;
//	state*states;
//	int *final;
//	transition *transitions;
//	// returns the destination of a transition given its source and symbol
//	// Big O = O(m*n), where m is number of symbols and n is number of states
//	int getDestination(int start, char symbol)
//	{
//		for (int i = 0; i < numStates*numSymbols; i++)
//		{
//			if (transitions[i].symbol == symbol && transitions[i].start == start)
//				return transitions[i].destination;
//		}
//	}
//
//}aObj;
//
//
//
//string input1;
//
//
//// this function is used to get input from user
//// Big O = O(m*n), where m is number of symbols and n is number of states
//void takeInput()
//{
//	// input number of states in dfa
//	printf("\nTotal Number of DFA states : ");
//	scanf("%d", &aObj.numStates);
//	// creates the states
//	aObj.states = new state[aObj.numStates];
//	printf("\nStates of DFA are as follows : ");
//	// displays the states
//	printf("%d", 0);
//	for (int i = 1; i < aObj.numStates; i++)
//		printf(", %d", i);
//		
//	// input number of symbols 
//	printf("\nTotal number of symbols : ");
//	scanf("%d", &aObj.numSymbols);
//	// creates the symbols
//	aObj.symbol = new char[aObj.numSymbols + 1];
//	// inputs the symbols
//	printf("\nEnter input symbols\n");
//	for (int i = 0; i < aObj.numSymbols; i++)
//	{
//		printf("Symbol # %d : ", i + 1);
//		cin >> aObj.symbol[i];
//	}
//	// input number of final states
//	printf("Total number of final states : ");
//	scanf("%d", &aObj.numFinalStates);
//	// input the final states
//	aObj.final = new int[aObj.numFinalStates];
//	for (int i = 0; i < aObj.numFinalStates; i++)
//	{
//		printf("Final state # %d : ", i + 1);
//		scanf("%d", &aObj.final[i]);
//	}
//	// initializes the transitions
//	aObj.transitions = new transition[aObj.numStates*aObj.numSymbols];
//	printf("\nInput Transition Rule\n");
//	// inputs transitions
//	for (int i = 0; i < aObj.numSymbols; i++)
//	{
//		for (int j = 0; j < aObj.numStates; j++)
//		{
//			printf("Enter destination state of starting state being %d with symbol %c\n", j, aObj.symbol[i]);
//			int xx;
//			cin >> xx;
//			transition t; t.setDestination(j, aObj.symbol[i], xx);
//			aObj.transitions[(i*aObj.numStates) + j] = t;
//		}
//	}
//}
//
//// function to read the data from file
//// Big O = O(m*n), where m is number of symbols and n is number of states
//
//void readFromFile()
//{
//	std::ifstream in("input.txt");
//	// reads number of states
//	in >> aObj.numStates;
//	aObj.states = new state[aObj.numStates];
//	// reads number of symbols
//	in >> aObj.numSymbols;
//	aObj.symbol = new char[aObj.numSymbols + 1];
//
//
//	printf("\nStates of DFA are as follows : ");
//	printf("%d", 0);
//	// displays the states
//	for (int i = 1; i < aObj.numStates; i++)
//		printf(", %d", i);
//
//	// reads and displays the symbols
//	for (int i = 0; i < aObj.numSymbols; i++)
//	{
//		in >> aObj.symbol[i];
//		printf("\nSymbol # %d : ", i + 1);
//		printf("%c", aObj.symbol[i]);
//	}
//	in >> aObj.numFinalStates;
//	aObj.final = new int[aObj.numFinalStates];
//
//	// reads and displays the final states
//	aObj.transitions = new transition[aObj.numStates*aObj.numSymbols];
//	for (int i = 0; i < aObj.numFinalStates; i++)
//	{
//		printf("\nFinal state # %d : ", i + 1);
//		in >> aObj.final[i];
//		cout << aObj.final[i];
//	}
//
//	// reads and displays the transitions
//
//	printf("\nTransition Rule\n");
//	for (int i = 0; i < aObj.numSymbols; i++)
//	{
//		for (int j = 0; j < aObj.numStates; j++)
//		{
//			int xx;
//			in >> xx;
//			transition t; t.setDestination(j, aObj.symbol[i], xx);
//			aObj.transitions[(i*aObj.numStates) + j] = t;
//
//			printf("Destination state of starting state being %d with symbol %c is %d \n", j, aObj.symbol[i], xx);
//		}
//	}
//}
//
//void checkInput()
//{
//	do
//	{
//		int s = 0;
//		int i = 0;
//		bool isFinal = false;
//		printf("\nEnter the string to check : ");
//		cin >> input1;
//		for (int j = 0; j < input1.length(); j++)
//		{
//			s = aObj.getDestination(s, input1[i++]);
//		}
//		for (i = 0; i < aObj.numFinalStates; i++)
//		if (aObj.final[i] == s)
//			isFinal = true;
//		if (isFinal == true)
//			printf("\nEntered string is a valid string");
//		else
//			printf("\nEntered string is invalid");
//		printf("\nDo you want to try it again? (y/n) ");
//	} while (getch() == 'y');
//}
//int main()
//{
//	cout << "Please select the input type : \n1. From File\n2. Self Entries\n";
//	int inp = 0;
//	// gets the choice from user
//	cin >> inp;
//	if (inp == 2)
//		// call the function which takes input from user
//		takeInput();
//	else
//		// call teh function which takes input from file
//		readFromFile();
//	checkInput();
//	
//	getch();
//}

#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
// struct for the state
struct state{
	int statee;
}sObj;
//struct to store transition


struct transition{
	int start;
	char symbol;
	int destination;
}tObj;
struct node{
	struct transition t;
	struct node*next;
};
// struct to store automaton
struct automaton{

	int numSymbols;
	char* symbol;
	int numStates, numFinalStates;
	struct state*states;
	int *final;
	struct node *head;
	// returns the destination of a transition given its source and symbol
	// Big O = O(m*n), where m is number of symbols and n is number of states


}aObj;

void addElement(struct transition t)
{
	if (aObj.head == NULL)
	{
		aObj.head = (struct node*)malloc(sizeof(struct node));
		aObj.head->t = t;
		aObj.head->next = NULL;
	}
	else
	{
		struct node*curr = aObj.head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->t = t;
		curr->next = NULL;
	}
}
int getDestination(int start, char symbol)
{
	struct node*curr = aObj.head;
	while (curr->next != NULL)
	{
		if (curr->t.symbol == symbol && curr->t.start == start)
			return curr->t.destination;
		curr = curr->next;
	}
	return 0;
}

// this function is used to get input from user
// Big O = O(m*n), where m is number of symbols and n is number of states
void takeInput()
{
	// input number of states in dfa
	printf("\nTotal Number of DFA states : ");

	scanf_s("%d", &aObj.numStates);
	// creates the states
	aObj.states = (struct state*)malloc(aObj.numStates * sizeof(struct state));
	printf("\nStates of DFA are as follows : ");
	// displays the states
	printf("%d", 0);
	int i = 1;
	for (i = 1; i < aObj.numStates; i++)
		printf(", %d", i);

	// input number of symbols 
	printf("\nTotal number of symbols : ");
	scanf_s("%d", &aObj.numSymbols);
	// creates the symbols
	aObj.symbol = (char*)malloc(aObj.numSymbols * sizeof(char));
	// inputs the symbols
	printf("\nEnter input symbols\n");
	for (i = 0; i < aObj.numSymbols; i++)
	{
		printf("Symbol # %d : ", i + 1);
		scanf_s("%c", aObj.symbol[i]);
	}
	// input number of final states
	printf("Total number of final states : ");
	scanf_s("%d", &aObj.numFinalStates);
	// input the final states
	aObj.final = (int*)malloc(aObj.numFinalStates * sizeof(int));
	for (i = 0; i < aObj.numFinalStates; i++)
	{
		printf("Final state # %d : ", i + 1);
		scanf_s("%d", &aObj.final[i]);
	}
	// initializes the transitions
	printf("\nInput Transition Rule\n");
	int j = 0;
	// inputs transitions
	for (i = 0; i < aObj.numSymbols; i++)
	{
		for (j = 0; j < aObj.numStates; j++)
		{
			printf("Enter destination state of starting state being %d with symbol %c\n", j, aObj.symbol[i]);
			int xx=0;
			scanf_s("%d", xx);
			struct transition t;
			t.start = j;
			t.symbol = aObj.symbol[i];
			t.destination = xx;
			addElement(t);
		}
	}
}

// function to read the data from file
// Big O = O(m*n), where m is number of symbols and n is number of states

//void readFromFile()
//{
//	FILE* file = fopen_s("input.txt", "r");
//	// reads number of states
//
//	fscanf_s(file, "%d", &aObj.numStates);
//
//	aObj.states = (struct state*)malloc(aObj.numFinalStates * sizeof(struct state));
//	// reads number of symbols
//	fscanf_s(file, "%d", &aObj.numSymbols);
//
//	aObj.symbol = (char*)malloc(aObj.numFinalStates * sizeof(char));
//
//	int i = 0;
//	printf("\nStates of DFA are as follows : ");
//	printf("%d", 0);
//	// displays the states
//	for (i = 1; i < aObj.numStates; i++)
//		printf(", %d", i);
//
//	// reads and displays the symbols
//	for (i = 0; i < aObj.numSymbols; i++)
//	{
//		fscanf_s(file, "%c", &aObj.symbol[i]);
//
//		printf("\nSymbol # %d : ", i + 1);
//		printf("%c", aObj.symbol[i]);
//	}
//	fscanf_s(file, "%d", &aObj.numFinalStates);
//
//	aObj.final = (int*)malloc(aObj.numFinalStates * sizeof(int));
//
//	// reads and displays the final states
//	aObj.transitions = (struct transition*)malloc(aObj.numFinalStates * sizeof(struct transition));
//	for (i = 0; i < aObj.numFinalStates; i++)
//	{
//		printf("\nFinal state # %d : ", i + 1);
//		fscanf_s(file, "%d", &aObj.final[i]);
//		printf("%d", aObj.final[i]);
//	}
//
//	// reads and displays the transitions
//	int j = 0;
//	printf("\nTransition Rule\n");
//	for (i = 0; i < aObj.numSymbols; i++)
//	{
//		for (j = 0; j < aObj.numStates; j++)
//		{
//			int xx;
//			fscanf_s(file, "%d", xx);
//
//			struct transition t;
//			t.start = j;
//			t.symbol = aObj.symbol[i];
//			t.destination = xx;
//			aObj.transitions[(i*aObj.numStates) + j] = t;
//
//			printf("Destination state of starting state being %d with symbol %c is %d \n", j, aObj.symbol[i], xx);
//		}
//	}
//}

void checkInput()
{
	do
	{
		int s = 0;
		int i = 0;
		int j = 0;
		int isFinal = 0;
		char input1[100];
		int size = 0;
		printf("\nEnter the string to check : ");
		for (j = 0; j < 100; j++)
		{
			input1[j] = _getch();
			if (input1[j] == 13)
			{
				size = j;
				break;
			}
		}
		scanf_s("%d", input1);
		for (j = 0; j < 100; j++)
		{
			s = getDestination(s, input1[i++]);
		}
		for (i = 0; i < aObj.numFinalStates; i++)
		if (aObj.final[i] == s)
			isFinal = 1;
		if (isFinal == 1)
			printf("\nEntered string is a valid string");
		else
			printf("\nEntered string is invalid");
		printf("\nDo you want to try it again? (y/n) ");
	} while (_getch() == 'y');
}
int main()
{
	aObj.head = NULL;
	printf("Please select the input type : \n1. From File\n2. Self Entries\n");
	int inp = 0;
	// gets the choice from user
	scanf_s("%d", &inp);
	if (inp == 2)
		// call the function which takes input from user
		takeInput();
	else
		// call teh function which takes input from file
		takeInput();
	checkInput();

	_getch();
}

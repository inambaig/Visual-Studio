#include <iostream>
#include <string>
#include <time.h>
using namespace std;
const int SIZE = 10;
enum colony{A=0, B=1, C, D, E, F, G, H, I, J};

void initialize(int arr[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = (rand() % 20) + 1;
		}
	}
}
string colonyValue(int index)
{
	switch (index)
	{
	case 1: return "B";
	case 2: return "C";
	case 3: return "D";
	case 4: return "E";
	case 5: return "F";
	case 6: return "G";
	case 7: return "H";
	case 8: return "I";
	case 9: return "J";
	case 0: return "A";
	}
	return "";
}
void printContent(int arr[SIZE][SIZE])
{
	cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n";
	cout << "------------------------------------------------------------------------------------\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << static_cast<char>(65 + i)<<" |\t";
		for (int j = 0; j < SIZE; j++)
		{
			if (arr[i][j] < 10)
				cout << "0";
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isVisited(int visitedArray[], int colony)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (visitedArray[i] == colony)
			return true;
	}
	return false;
}

int indexOfLowerst(int arr[][SIZE], int visitedArr[], int index)
{
	int minIndex = 0;
	int min = 21;
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (arr[index][i] <= min && !isVisited(visitedArr, i))
		{
			min = arr[index][i];
			minIndex = i;
		}
	}
	return minIndex;
}

void print1DArray(int  arr[])
{
	enum colony obj;
	cout << "The path followed by Anthony is:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << colonyValue(arr[i]);
		if (i != SIZE - 1)
		{
			cout << "----->";
		}
		else
			cout << endl;
	}
}

void printStudentInfo()
{
	cout << "\t\t+----------------------------------------------+"<<endl;
	cout << "\t\t|\tComputer Science and Engineering\t|\t" << endl;
	cout << "\t\t|\tCSCE 1030 - Computer Science I\t\t|\t" << endl;
	cout << "\t\t| Nischal Tiwari  nt0250  nt0250@my.unt.edu\t|\t" << endl;
	cout << "\t\t+----------------------------------------------+\t" << endl;


}
void description()
{
	cout << "\t\t\tWelcome to Anthony's hunch" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "This program will set up a matrix that represents the pheromone levels " << endl;
	cout << "between ant colonies. Anthony's objective is to the find a path least" << endl;
	cout << "taken by the other ants in the hopes of finding food to last through the" << endl;
	cout << "winter" << endl; 
	cout << "------------------------------------------------------------------------" << endl;
}
void main()
{
	int map[SIZE][SIZE];
	int visited[SIZE] = {-1};
	// Print Student Info
	// Brief Description
	srand(time(NULL));
	printStudentInfo();
	description();
	initialize(map);
	printContent(map);
	visited[0] = 0; 
	int lowest = 0;
	for (int i = 1; i < SIZE; i++)
	{
		lowest = indexOfLowerst(map, visited, lowest);
		visited[i] = lowest;
	}
	print1DArray(visited);
	system("pause");
}
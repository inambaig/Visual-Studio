#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void reduce(int **& graph, int V)
{
	for (int i = 0; i < V; ++i)
	{
		for (int j = 0; j < V; ++j)
		{
			for (int k = 0; k < V; ++k)
			{
				if (graph[i][k] == 1 && graph[k][j] == 1 && i != j && j != k && i != k)
					graph[i][j] = 0;
			}
		}
	}
}

void displayGraph(int ** graph, int V)
{
	cout << V << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (graph[i][j] == 1)
				cout << j << " ";
		}
		cout << V << endl;
	}
	cout << V;
}

void writeGraph(int ** graph, int V, string outName)
{
	ofstream out;
	out.open(outName);
	out << V << endl;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (graph[i][j] == 1)
				out << j << " ";
		}
		out << V << endl;
	}
	out << V;
	out.close();
}
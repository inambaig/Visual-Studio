#include "Floyd.h"

void allPairsShortestPaths(int **&graph, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				graph[r][c] = minWithInfinity(graph[r][c], addWithInfinity(graph[r][i], graph[i][c]));
			}
		}
	}
}

int addWithInfinity(int a, int b)
{
	if (a == INT_MAX)
		return INT_MAX;
	if (b == INT_MAX)
		return INT_MAX;
	return a + b;
}

int isLessWithInfinity(int a, int b)
{
	if (a < b)
		return -1;
	else if (a == b)
		return 0;
	else
		return 1;
}

int minWithInfinity(int a, int b)
{
	if (a < b)
		return a;
	if (b < a)
		return b;
	else if (a == INT_MAX)
		return INT_MAX;
	else
		return a;
}
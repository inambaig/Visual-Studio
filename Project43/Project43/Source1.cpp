#include "Floyd.cpp"

void main()
{
	int n = 7;
	int **graph = new int *[n];
	for (int i = 0; i < 7; i++)
		graph[i] = new int[n];

	graph[0][0] = 0;
	graph[0][1] = 80;
	graph[0][2] = INT_MAX;
	graph[0][3] = INT_MAX;
	graph[0][4] = INT_MAX;
	graph[0][5] = INT_MAX;
	graph[0][6] = INT_MAX;

	graph[1][0] = 80;
	graph[1][1] = 0;
	graph[1][2] = 79;
	graph[1][3] = INT_MAX;
	graph[1][4] = 153;
	graph[1][5] = INT_MAX;
	graph[1][6] = INT_MAX;

	graph[2][0] = INT_MAX;
	graph[2][1] = 79;
	graph[2][2] = 0;
	graph[2][3] = 78;
	graph[2][4] = INT_MAX;
	graph[2][5] = 74;
	graph[2][6] = INT_MAX;

	graph[3][0] = INT_MAX;
	graph[3][1] = INT_MAX;
	graph[3][2] = 78;
	graph[3][3] = 0;
	graph[3][4] = 98;
	graph[3][5] = 89;
	graph[3][6] = INT_MAX;

	graph[4][0] = INT_MAX;
	graph[4][1] = 153;
	graph[4][2] = INT_MAX;
	graph[4][3] = 98;
	graph[4][4] = 0;
	graph[4][5] = 67;
	graph[4][6] = INT_MAX;

	graph[5][0] = INT_MAX;
	graph[5][1] = INT_MAX;
	graph[5][2] = 74;
	graph[5][3] = 89;
	graph[5][4] = 67;
	graph[5][5] = 0;
	graph[5][6] = 67;

	graph[6][0] = INT_MAX;
	graph[6][1] = INT_MAX;
	graph[6][2] = INT_MAX;
	graph[6][3] = INT_MAX;
	graph[6][4] = INT_MAX;
	graph[6][5] = 67;
	graph[6][6] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == INT_MAX)
			{
				cout << "-";
				continue;
			}
			cout << graph[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl; cout << endl; cout << endl;
	allPairsShortestPaths(graph, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (graph[i][j] == INT_MAX)
			{
				cout << "-";
				continue;
			}
			cout << graph[i][j]<<"\t";
		}
		cout << endl;
	}


	system("pause");
}
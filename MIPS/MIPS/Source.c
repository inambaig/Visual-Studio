//#include<iostream> 
//#include <fstream>
//using namespace std;
//#define V 6
//
//int main(int **args, int argv)
//{
//	int **graph;
//
//	for (int i = 0; i < V; ++i)
//	{
//		for (int j = 0; j < V; ++j)
//		{
//			for (int k = 0; k < V; ++k)
//			{
//				if (graph[i][k] == 1 && graph[k][j] == 1 && i != j && j != k && i != k)
//					graph[i][j] = 0;
//			}
//		}
//	}
//	for (int i = 0; i < V; i++)
//	{
//		for (int j = 0; j < V; j++)
//		{
//			printf("%d\t", graph[i][j]);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
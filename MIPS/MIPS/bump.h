
#include <stack>

#include<iostream>
#include <queue>
#include <fstream>
using namespace std;
void topologicalSortUtil(int v, bool visited[], stack<int> &Stack, int V, int **graph);
void topologicalSort(int V, int **graph)
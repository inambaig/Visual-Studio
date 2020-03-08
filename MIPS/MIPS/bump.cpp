
#include <list>
#include "bump.h"
; using namespace std;
struct node{
	int index;
	int priority;
};
; void linearExtensionUtil(int v, bool visited[], stack<node> &Stack, int V, int **graph, node*nodes)
{
	visited[v] = true;
	for (int i = 0; i != V; ++i)
	{
		if (graph[v][i] == 1)
		{
			if (!visited[i])
				linearExtensionUtil(i, visited, Stack, V, graph, nodes);
		}
	}
	Stack.push(nodes[v]);
}

void linearExtension(int V, int **graph)
{
	stack<node> Stack;
	bool *visited = new bool[V];
	node *nodes = new node[V];
	for (int i = 0; i < V; i++)
	{
		nodes[i].priority = rand() % 100;
		nodes[i].index = i;
		visited[i] = false;
	}
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
			linearExtensionUtil(i, visited, Stack, V, graph, nodes);
	}
	stack<node> Stack2;
	stack<node> Stack3;
	while (Stack.empty() == false)
	{
		cout << Stack.top().index << " ";
		Stack2.push(Stack.top());
		Stack.pop();
	}
	while (Stack2.empty() == false)
	{
		Stack3.push(Stack2.top());
		Stack2.pop();
	}
	cout << "Priorities:" << endl;

	while (Stack3.empty() == false)
	{
		cout << Stack3.top().priority << " ";
		Stack3.pop();
	}
}

int main(int argc, char **argv)
{

	int **graph;
	int V = 0;
	ifstream in;
	in.open(argv[1]);
	in >> V;
	int read = 0;
	graph = new int *[V];

	for (int i = 0; i < V; i++)
	{
		graph[i] = new int[V];
		for (int j = 0; j < V; j++)
		{
			graph[i][j] = 0;
		}
		in >> read;
		while (read != V)
		{
			graph[i][read] = 1;
			in >> read;
		}
	}
	linearExtension(V, graph);
	in.close();
	system("pause");
}
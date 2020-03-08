#include "poset.h"
#include "bump.h"
;
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
	in.close();
	ofstream out;
	string outName = argv[1];
	outName = outName + ".treduc";
	out.open(outName);
	cout << "Input Graph : ";
	displayGraph(graph, V);
	cout << endl;
	reduce(graph, V);
	cout << "Output Graph (also written in the output file (" + outName + ")) : " << endl;
	displayGraph(graph, V);
	writeGraph(graph, V, outName);
	cout << endl;
	topologicalSort(V, graph);

	system("pause");
	return 0;
}
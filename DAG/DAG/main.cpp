/*
* A main function for you to build and run your
* own tests with.
* This file is not part of the marking, so you
* can do anything you want here.
*/
#include <iostream>
using namespace std;
#include "directed_graph_algorithms.cpp"

int main() {
	directed_graph<int> g;
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_edge(1, 1);
	g.add_edge(2, 1);
	cout << is_dag(g);
	system("pause");
}
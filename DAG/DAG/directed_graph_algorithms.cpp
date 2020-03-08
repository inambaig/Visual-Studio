/*
* Notice that the list of included headers has
* expanded a little. As before, you are not allowed
* to add to this.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <exception>
#include <stdexcept>

#include "directed_graph.hpp"


template <typename vertex>
bool isCyclicUtil(int v, bool visited[], bool *recStack, const directed_graph<vertex> & d)
{
	if (visited[v] == false)
	{
		// Mark the current node as visited and part of recursion stack 
		visited[v] = true;
		recStack[v] = true;
		std::unordered_set<vertex>::iterator i;
		unordered_set<vertex> ::iterator vertixIter;

		for (vertixIter = d.vertices.begin(); vertixIter != d.vertices.end(); vertixIter++)
		{
			for (i = d.nbegin(*vertixIter); i != d.nend(*vertixIter); ++i)
			{
				if (!visited[*vertixIter] && isCyclicUtil(*vertixIter, visited, recStack, d))
					return true;
				else if (recStack[*vertixIter])
					return true;
			}
		}
	}
	recStack[v] = false;  // remove the vertex from recursion stack 
	return false;
}
/*
* Computes whether the input is a Directed Acyclic Graph (DAG).
* A digraph is a DAG if there is no vertex that has a cycle.
* A cycle is a non-empty set of [out-]edges that starts at one
* vertex, and returns to it.
*/
template <typename vertex>
bool is_dag(const directed_graph<vertex> & d) {
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	int V = d.num_vertices();
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for (int i = 0; i < V; i++)
	if (isCyclicUtil(i, visited, recStack, d))
		return true;

	return false;
}

/*
* Computes a topological ordering of the vertices.
* For every vertex u in the order, and any of its
* neighbours v, v appears later in the order than u.
*/
template <typename vertex>
std::list<vertex> topological_sort(const directed_graph<vertex> & d) {
	return std::list<vertex>();
}

/*
* Given a DAG, computes whether there is a Hamiltonian path.
* a Hamiltonian path is a path that visits every vertex
* exactly once.
*/
template <typename vertex>
bool is_hamiltonian_dag(const directed_graph<vertex> & d) {
	return false;
}

/*
* Computes the weakly connected components of the graph.
* A [weak] component is the smallest subset of the vertices
* such that the in and out neighbourhood of each vertex in
* the set is also contained in the set.
*/
template <typename vertex>
std::vector<std::vector<vertex>> components(const directed_graph<vertex> & d) {
	return std::vector<std::vector<vertex>>();
}

/*
* Computes the strongly connected components of the graph.
* A strongly connected component is a subset of the vertices
* such that for every pair u, v of vertices in the subset,
* v is reachable from u and u is reachable from v.
*/

template <typename vertex>
std::vector<std::vector<vertex>> strongly_connected_components(const directed_graph<vertex> & d) {
	return std::vector<std::vector<vertex>>();
}

/*
* Computes the shortest distance from u to every other vertex
* in the graph d. The shortest distance is the smallest number
* of edges in any path from u to the other vertex.
* If there is no path from u to a vertex, set the distance to
* be the number of vertices in d plus 1.
*/
template <typename vertex>
std::unordered_map<vertex, std::size_t> shortest_distances(const directed_graph<vertex> & d, const vertex & u) {
	return std::unordered_map<vertex, std::size_t>();
}


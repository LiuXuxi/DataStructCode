#include"adjacencylist.h"
#include<vector>
#include<string>


int main() {
	int n = 5;
	std::vector<std::string> names = { "A", "B", "C", "D", "E" };
	ArcList<std::string>graph(names, 1);
	graph.addAGraph(0, 4, 1);
	graph.addAGraph(0, 3, 1);
	graph.addAGraph(0, 1, 1);
	graph.addAGraph(1, 4, 1);
	graph.addAGraph(1, 2, 1);
	graph.addAGraph(2, 0, 1);
	graph.addAGraph(3, 2, 1);
	printf("DFS: ");
	graph.DFSAGraphTravel(0);
	
	printf("BFS: ");
	graph.BFSAGraphTravel(0);
	return 0;
}
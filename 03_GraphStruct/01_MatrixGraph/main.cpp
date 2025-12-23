#include"matrixGraph.h"
#include<iostream>
#include<string>
#include<vector>

void init(MatrixGraph<std::string>&graph) {
	graph.addMGraphEdge( 0, 1, 1);
	graph.addMGraphEdge( 0, 2, 1);
	graph.addMGraphEdge( 1, 3, 1);
	graph.addMGraphEdge( 1, 4, 1);
	graph.addMGraphEdge( 2, 5, 1);
	graph.addMGraphEdge( 2, 6, 1);
	graph.addMGraphEdge( 3, 7, 1);
	graph.addMGraphEdge( 4, 7, 1);
	graph.addMGraphEdge( 5, 6, 1);
}

void test() {
	std::vector<std::string> data{ "V1", "V2", "V3", "V4","V5", "V6", "V7", "V8" };
	MatrixGraph<std::string>graph(data,0,0);

	init(graph);

	printf("edge num = %d\n", data.size());

	graph.initMGraphVisit();
	printf("DFS: ");
	graph.DFSMGraphTravel(0);

	graph.initMGraphVisit();
	printf("\nBFS: ");
	graph.BFSMGraphTravel(0);
}

int main() {
	test();
	return 0;
}
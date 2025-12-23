#include"adjacencyMultiList.h"
#include<string>

int main() {
	std::vector<std::string>targets{ "V1","V2","V3","V4","V5" };
	AdjacencyMultiList<std::string>graph(targets);
	graph.addEdge(0, 1, 1);
	graph.addEdge(0, 3, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(1, 4, 1);
	graph.addEdge(2, 3, 1);
	graph.addEdge(2, 4, 1);
	graph.show();
	std::cout << "=================" << std::endl;
	graph.deleteEdge(2, 4);
	graph.show();
	std::cout << "==================" << std::endl;
	graph.deleteEdge(9, 3);
	graph.show();
	return 0;
}
#include"crossLinkGraph.h"
#include<string>
#include<conio.h>

int main() {
	std::vector<std::string>targets{"V0","V1","v2","V3"};
	CrossLinkGraph<std::string>graph(targets);
	graph.addEdge(0, 3, 1);
	graph.addEdge(1, 0, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(2, 0, 1);
	graph.addEdge(2, 1, 1);
	std::cout << "0 indegree cnt is " << graph.InDegreeCount(0) << std::endl;
	std::cout << "0 outdegree cnt is " << graph.OutDegreeCount(0) << std::endl;
	return 0;
}
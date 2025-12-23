#include"topologicalsort.h"
#include<string>
#include<vector>


int main() {
	std::vector<std::string>names = {
		"0", "1", "2", "3",
		"4", "5", "6",
	};
	ArcList<std::string>graph(names, 1);
	graph.addAGraph(0, 1, 1);
	graph.addAGraph(0, 2, 1);
	graph.addAGraph(0, 3, 1);
	graph.addAGraph(1, 2, 1);
	graph.addAGraph(1, 4, 1);
	graph.addAGraph(2, 4, 1);
	graph.addAGraph(2, 5, 1);
	graph.addAGraph(3, 5, 1);
	graph.addAGraph(4, 6, 1);
	graph.addAGraph(5, 4, 1);
	graph.addAGraph(5, 6, 1);
	TopologicalSort<std::string>sort(graph);
	sort.calculate(graph);
	return 0;
}
#include"keypath.h"
#include<string>
#include<vector>

int main() {
	std::vector<std::string> names = {
		"V0", "V1", "V2", "V3",
		"V4", "V5", "V6", "V7", "V8"
	};
	ArcList<std::string>graph(names,1);
	graph.addAGraph(0, 1, 6);
	graph.addAGraph(0, 2, 4);
	graph.addAGraph(0, 3, 5);
	graph.addAGraph(1, 4, 1);
	graph.addAGraph(2, 4, 1);
	graph.addAGraph(3, 5, 2);
	graph.addAGraph(4, 6, 9);
	graph.addAGraph(4, 7, 7);
	graph.addAGraph(5, 7, 4);
	graph.addAGraph(6, 8, 2);
	graph.addAGraph(7, 8, 4);

	KeyPath<std::string>keypath(graph);
	keypath.calculate(graph);
	return 0;
}
#include"Dijkstra.h"
#include<string>

MatrixGraph<std::string> setupMGraphDijkstra() {
    std::vector<std::string> names = { "0", "1", "2", "3", "4", "5", "6" };
    MatrixGraph<std::string> graph(names, false, INF); // false 表示无向图

    graph.addMGraphEdge(0, 1, 4);
    graph.addMGraphEdge(0, 2, 6);
    graph.addMGraphEdge(0, 3, 6);
    graph.addMGraphEdge(1, 4, 7);
    graph.addMGraphEdge(1, 2, 1);
    graph.addMGraphEdge(2, 4, 6);
    graph.addMGraphEdge(2, 5, 4);
    graph.addMGraphEdge(3, 2, 2);
    graph.addMGraphEdge(3, 5, 5);
    graph.addMGraphEdge(4, 6, 6);
    graph.addMGraphEdge(5, 4, 1);
    graph.addMGraphEdge(5, 6, 8);

    return graph;
}

int main() {
    MatrixGraph<std::string>graph = setupMGraphDijkstra();
    Dijkstra<std::string>dijkstra(graph);
    dijkstra.calculate(graph,0);
    std::cout << "0 ~ 4 node info: ";
    dijkstra.showPath(graph,6);
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include "Kruskal.h"
#include"Prim.h"

MatrixGraph<std::string> setupMGraphKruskal() {
    std::vector<std::string> names = { "A", "B", "C", "D", "E", "F", "G" };
    MatrixGraph<std::string> graph(names, false, 0); // false 表示无向图

    graph.addMGraphEdge(0, 1, 12);
    graph.addMGraphEdge(0, 5, 16);
    graph.addMGraphEdge(0, 6, 14);
    graph.addMGraphEdge(1, 2, 10);
    graph.addMGraphEdge(1, 5, 7);
    graph.addMGraphEdge(2, 3, 3);
    graph.addMGraphEdge(2, 4, 5);
    graph.addMGraphEdge(2, 5, 6);
    graph.addMGraphEdge(3, 4, 4);
    graph.addMGraphEdge(4, 5, 2);
    graph.addMGraphEdge(4, 6, 8);
    graph.addMGraphEdge(5, 6, 9);

    return graph;
}



void testKruskal() {
    // 1. 创建图
    MatrixGraph<std::string> graph = setupMGraphKruskal();

    // 2. 创建 Kruskal 对象，构造函数会自动执行算法
    Kruskal<std::string> kruskal_algo(graph);

    // 3. 获取并打印结果
    int sum = kruskal_algo.getTotalWeight();
    const auto& result_edges = kruskal_algo.getMstEdges();

    std::cout << "Kruskal sum of weight: " << sum << std::endl;
    int i = 1;
    for (const auto& edge : result_edges) {
        std::cout << "edge " << i++ << ": [" << graph.getNodeShow(edge.begin)
            << "] --- <" << edge.weight << "> --- [" << graph.getNodeShow(edge.end)<<"]" << std::endl;
    }
}

MatrixGraph<std::string> setupMGraphPrim() {
    std::vector<std::string> names = { "A", "B", "C", "D", "E", "F", "G" };
    MatrixGraph<std::string> graph(names, false, INT_MAX); // false 表示无向图

    graph.addMGraphEdge(0, 1, 12);
    graph.addMGraphEdge(0, 5, 16);
    graph.addMGraphEdge(0, 6, 14);
    graph.addMGraphEdge(1, 2, 10);
    graph.addMGraphEdge(1, 5, 7);
    graph.addMGraphEdge(2, 3, 3);
    graph.addMGraphEdge(2, 4, 5);
    graph.addMGraphEdge(2, 5, 6);
    graph.addMGraphEdge(3, 4, 4);
    graph.addMGraphEdge(4, 5, 2);
    graph.addMGraphEdge(4, 6, 8);
    graph.addMGraphEdge(5, 6, 9);

    return graph;
}


void testPrim() {
    MatrixGraph<std::string>graph = setupMGraphPrim();
    Prim<std::string>prim(graph);
    prim.calculate(graph,0);
    int sum = prim.getTotalWeight();
    const auto& result_edges = prim.getMstEdges();
    std::cout << "Prim sum of wieght: " << sum << std::endl;
    for (int i = 0; i < graph.getNodeNum()-1; i++) {
        std::cout << "edge " << i++ << ": [" << graph.getNodeShow(result_edges[i].begin)
            << "] --- <" << result_edges[i].weight << "> --- [" << graph.getNodeShow(result_edges[i].end) << "]" << std::endl;
    }
}

int main() {
    //testKruskal();
    testPrim();

    return 0;
}
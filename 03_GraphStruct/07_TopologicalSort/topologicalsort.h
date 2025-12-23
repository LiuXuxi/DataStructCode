#pragma once
#include<iostream>
#include"../02_AdjacencyList/adjacencylist.h"
#include<string> 

template<class T>
class TopologicalSort {
private:
	int* indgree;
	int n;
public:
	TopologicalSort(ArcList<T>& graph)
	:n(graph.getNodeNum()){
		indgree = new int[n];
		std::memset(indgree,0,n*sizeof(int));
		for (int i = 0; i < n; i++) {
			ArcNode<T>* nodes = graph.getNodes();
			ArcEdge* edge = nodes[i].firstEdge;
			while (edge) {
				++indgree[edge->no];
				edge = edge->next;
			}
		}
	}

	void calculate(ArcList<T>&graph) {
		ArcNode<T>*nodes = graph.getNodes();
		int* stack = new int[n];
		int top = -1;
		for (int i = 0; i < n; i++) {
			if (indgree[i] == 0) {
				stack[++top] = i;
			}
		}
		int cnt = 0;
		while (top != -1) {
			int cur = stack[top--];
			++cnt;
			std::cout << nodes[cur].show << " ";
			ArcEdge* edge = nodes[cur].firstEdge;
			while (edge) {
				if (--indgree[edge->no] == 0) {
					stack[++top] = edge->no;
				}
				edge = edge->next;
			}
		}
		std::cout << std::endl;
	}

	~TopologicalSort() {
		delete[]indgree;
	}
};

#pragma once
#include"../02_AdjacencyList/adjacencylist.h"
#include<iostream>

template<class T>
class KeyPath {
private:
	int* ETV;
	int* LTV;

	void topologicSort(ArcList<T>& _graph) {
		int n = _graph.getNodeNum();
		int* inDegree = new int[n];
		memset(inDegree, 0, sizeof(int) *n);
		ArcNode<T>* nodes = _graph.getNodes();
		for (int i = 0; i < n; i++) {
			ArcEdge* edge = nodes[i].firstEdge;
			while (edge) {
				++inDegree[edge->no];
				edge = edge->next;
			}
		}
		int* stack = new int[n];
		int top = -1;
		memset(stack, 0, sizeof(int) * n);
		for (int i = 0; i < n; i++) {
			if (inDegree[i] == 0)stack[++top] = i;
		}
		int* topOut = new int[n];
		int temp, index = 0;
		while (top != -1) {
			temp = stack[top--];
			topOut[index++] = temp;
			ArcEdge*edge = nodes[temp].firstEdge;
			while (edge) {
				if (--inDegree[edge->no] == 0)stack[++top] = edge->no;
				if (ETV[temp] + edge->weight > ETV[edge->no])ETV[edge->no] = ETV[temp] + edge->weight;
				edge = edge->next;
			}
		}

		temp = topOut[--index];
		for (int i = 0; i < n; i++)LTV[i] = ETV[temp];
		while (index) {
			temp = topOut[--index];
			ArcEdge* edge = nodes[temp].firstEdge;
			while (edge) {
				if (LTV[edge->no] - edge->weight < LTV[temp])LTV[temp] = LTV[edge->no] - edge->weight;
				edge = edge->next;
			}
		}

		std::cout << "ETV:";
		for (int i = 0; i < n; i++)std::cout << ETV[i] << " ";
		std::cout << std::endl;
		std::cout << "LTV:";
		for (int i = 0; i < n; i++)std::cout << LTV[i] << " ";
		std::cout << std::endl;

		delete[]inDegree;
		delete[]stack;
		delete[]topOut;
	}

public:
	KeyPath(ArcList<T>&graph){
		ETV = new int[graph.getNodeNum()];
		memset(ETV, 0, sizeof(int) * graph.getNodeNum());
		LTV = new int[graph.getNodeNum()];
		memset(LTV, 0, sizeof(int) * graph.getNodeNum());
	}

	~KeyPath() {
		delete[]ETV;
		delete[]LTV;
	}

	void calculate(ArcList<T>& graph) {
		topologicSort(graph);
		ArcNode<T>* nodes = graph.getNodes();
		for (int i = 0; i < graph.getNodeNum(); i++) {
			ArcEdge* edge = nodes[i].firstEdge;
			while (edge) {
				if (ETV[i] == LTV[edge->no] - edge->weight)std::cout << i << "-" << edge->weight << "-" << edge->no << std::endl;
				edge = edge->next;
			}
		}
	}
};

#pragma once
#include<iostream>
#include"../01_MatrixGraph/matrixGraph.h"
#include<iostream>

template<class T>
class Dijkstra {
private:
	int* dist;
	int* path;
	int* mark;
	int n;

public:
	Dijkstra(MatrixGraph<T>& graph) 
	:n(graph.getNodeNum()){
		dist = new int[n];
		path = new int[n];
		mark = new int[n];
		for (int i = 0; i < n; i++) {
			dist[i] = INF;
			path[i] = -1;
			mark[i] = 0;
		}
	}
	~Dijkstra() {
		delete[]dist;
		delete[]path;
		delete[]mark;
	}

	void calculate(MatrixGraph<T>& graph, int startV) {
		for (int i = 0; i < n; i++) {
			if (dist[i] > graph.getEdgeWeight(startV, i)) {
				dist[i] = graph.getEdgeWeight(startV, i);
				path[i] = startV;
			}
		}
		mark[startV] = 1;
		dist[startV] = 0;
		path[startV] = -1;

		for (int i = 1; i < n; i++) {
			int min = INF;
			int tempIndex = 0;
			for (int j = 0; j < n; j++) {
				if (mark[j] == 0 && min > dist[j]) {
					min = dist[j];
					tempIndex = j;
				}
			}
			mark[tempIndex] = 1;
			for (int j = 0; j < n; j++) {
				int w = graph.getEdgeWeight(tempIndex, j);
				if (mark[j] == 0 && dist[tempIndex] + w < dist[j]) {
					dist[j] = dist[tempIndex] + w;
					path[j] = tempIndex;
				}
			}
		}
		
	}

	void showPath(MatrixGraph<T>&graph, int endV) {
		int* stack = new int[n];
		int top = -1;

		while (path[endV] != -1) {
			stack[++top] = endV;
			endV = path[endV];
		}
		stack[++top] = endV;

		while (top != -1) {
			int cur = stack[top--];
			std::cout << graph.getNodeShow(cur) << " ";
		}
		std::cout << std::endl;

		delete[]stack;
	}
};
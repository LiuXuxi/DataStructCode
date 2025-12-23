#pragma once
#include"common.h"
#include"../01_MatrixGraph/matrixGraph.h"

template<class T>
class Prim {
private:
	int* cost;
	int* mark;
	int* visit;
	Edge* mstEdges;
	int totalWeight = 0;

public:
	Prim(const MatrixGraph<T>& graph) {
		int n = graph.getNodeNum();
		cost = new int[n];
		mark = new int[n];
		visit = new int[n];
		mstEdges = new Edge[n-1];
		for (int i = 0; i < n; i++) {
			mark[i] = 0;
			visit[i] = -1;
		}
	}
	~Prim() {
		delete[]cost;
		delete[]mark;
		delete[]visit;
		delete[]mstEdges;
	}

public:
	void calculate(const MatrixGraph<T>& graph,int startV) {
		int n = graph.getNodeNum();
		for (int i = 0; i < n; i++) {
			cost[i] = graph.getEdgeWeight(startV, i);
			if (cost[i]<INT_MAX) {
				visit[i] = startV;
			}
		}
		mark[startV] = 1;
		for (int i = 0; i < n - 1; i++) {
			int min = INT_MAX;
			int no = 0;
			for (int j = 0; j < n; j++) {
				if (cost[j] < min&&mark[j]==0) {
					min = cost[j];
					no = j;
				}
			}
			mark[no] = 1;
			mstEdges[i].begin = no;
			mstEdges[i].end = visit[no];
			mstEdges[i].weight = min;
			totalWeight += min;

			for (int j = 0; j < n; j++) {
				if (cost[j] > graph.getEdgeWeight(no, j)) {
					cost[j] = graph.getEdgeWeight(no, j);
					visit[j] = no;
				}
			}
		}
	}

	Edge* getMstEdges()const {
		return mstEdges;
	}

	int getTotalWeight() const{ return totalWeight; }
};
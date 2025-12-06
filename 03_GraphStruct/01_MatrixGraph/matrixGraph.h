#pragma once

#include<vector>
#include<iostream>

typedef int MatrixEdge;

#define MaxNodeNum		20
#define INF				1E4

template<class T>
class MatrixGraph {
private:
	//节点结构
	typedef struct {
		int no;
		T show;
	}MatrixVertex;

	//图结构
	MatrixVertex vexs[MaxNodeNum];
	int nodeNum;
	MatrixEdge edges[MaxNodeNum][MaxNodeNum];
	int edgeNum;
	int directed;//0为无向图，1为有向图

	int MGraphVisited[MaxNodeNum];

private:
	bool isEdge(int weight) {
		if (weight > 0 && weight < INF)return true;
		return false;
	}

	void visitMGraphNode(const MatrixVertex* node) { std::cout << node->show << " "; }

public:
	MatrixGraph(std::vector<T>& nums, int direct, int edgeWeight) 
		:directed(direct),nodeNum(nums.size()),edgeNum(0) {
		for (int i = 0; i < nums.size(); i++) {
			vexs[i].no = i;
			vexs[i].show = nums[i];
			for (int j = 0; j < nums.size(); j++) {
				edges[i][j] = edgeWeight;
			}
		}
	}

	void addMGraphEdge(int x, int y, int weight) {
		if (x<0 || x>nodeNum || y<0 || y>nodeNum)return;
		if (!isEdge(edges[x][y])) {
			edges[x][y] = weight;
			++edgeNum;
			if (!directed)edges[y][x] = weight;
		}
	}

	void initMGraphVisit() { memset(MGraphVisited, 0, MaxNodeNum * sizeof(int)); }

	void DFSMGraphTravel(int startV) {
		visitMGraphNode(&vexs[startV]);
		MGraphVisited[startV] = 1;
		for (int i = 0; i < nodeNum; i++) {
			if (isEdge(edges[startV][i]) && !MGraphVisited[i])DFSMGraphTravel(i);
		}
	}

	void BFSMGraphTravel(int startV) {
		int rear = 0, front = 0, cur = 0;
		int deque[MaxNodeNum];

		rear = (rear + 1) % MaxNodeNum;
		deque[rear] = startV;
		MGraphVisited[startV] = 1;

		while (rear != front) {
			front = (front + 1) % MaxNodeNum;
			cur = deque[front];
			visitMGraphNode(&vexs[cur]);
			for (int i = 0; i < nodeNum; i++) {
				if (isEdge(edges[cur][i]) && !MGraphVisited[i]) {
					rear = (rear + 1) % MaxNodeNum;
					deque[rear] = i;
					MGraphVisited[i] = 1;
				}
			}
		}
	}
};
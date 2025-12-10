#pragma once
#include<vector>
#include<iostream>

template<class T>
class ArcList {
private:
	typedef struct node {
		int no;
		int weight;
		struct node* next;
	}ArcEdge;

	typedef struct {
		int no;
		T show;
		ArcEdge* firstEdge;
	}ArcNode;

	ArcNode* nodes;
	int nodeNum;
	int edgeNum;
	int directed;
	int* visited;

private:

	ArcEdge* creatArcEdge(int v,int w) {
		ArcEdge* edge = new ArcEdge;
		edge->no = v;
		edge->weight = w;
		edge->next = nullptr;
		return edge;
	}

	void resetAGraphVisited() { memset(visited, 0, sizeof(int) * nodeNum); }

	void visitArcNode(int x) { std::cout << nodes[x].show << " "; }

	void DFS_helper(int v) {
		visited[v] = 1;
		visitArcNode(v);
		ArcEdge* p = nodes[v].firstEdge;
		while (p) {
			int cur = p->no;
			if (visited[cur] == 0) {
				DFS_helper(cur); // 递归调用辅助函数自身
			}
			p = p->next;
		}
	}

public:
	ArcList(std::vector<T>nums, int direct) :
		nodeNum(nums.size()), edgeNum(0), directed(direct) {
		visited = new int[nodeNum];
		memset(visited, 0, sizeof(int) * nodeNum);
		nodes = new ArcNode[nodeNum];
		for (int i = 0; i < nums.size(); i++) {
			nodes[i].no = i;
			nodes[i].show = nums[i];
			nodes[i].firstEdge = nullptr;
		}
	}

	~ArcList() {
		for (int i = 0; i < nodeNum; ++i) {
			ArcEdge* p = nodes[i].firstEdge;
			while (p) {
				ArcEdge* temp = p;
				p = p->next;
				delete temp;
			}
		}
		delete[] nodes;
		delete[] visited;
	}

	void addAGraph(int x, int y, int w) {
		if (x < 0 || x >= nodeNum || y < 0 || y >= nodeNum || x == y)return;
		ArcEdge* edge = creatArcEdge(y, w);
		edge->next = nodes[x].firstEdge;
		nodes[x].firstEdge = edge;
		++edgeNum;
		if (directed == 0) {
			edge = creatArcEdge(x, w);
			edge->next = nodes[y].firstEdge;
			nodes[y].firstEdge = edge;
			++edgeNum;
		}
	}

	void DFSAGraphTravel(int v) {
		if (v < 0 || v >= nodeNum) return; // 边界检查
		resetAGraphVisited(); // 1. 在遍历开始前，重置visited数组
		DFS_helper(v);        // 2. 调用私有辅助函数开始递归
		std::cout << std::endl;
	}

	void BFSAGraphTravel(int v) {
		resetAGraphVisited();
		int rear = 0, front = 0;
		int* queue = new int[nodeNum];

		rear = (rear + 1) % nodeNum;
		queue[rear] = v;
		visited[v] = 1;

		while (front != rear) {
			front = (front + 1) % nodeNum;
			int cur = queue[front];
			visitArcNode(cur);
			ArcEdge* p = nodes[cur].firstEdge;
			while (p) {
				if (visited[p->no] == 0) {
					rear = (rear + 1) % nodeNum;
					queue[rear] = p->no;
					visited[p->no] = 1;
				}
				p = p->next;
			}
		}
		delete(queue);
		std::cout << std::endl;
	}
};

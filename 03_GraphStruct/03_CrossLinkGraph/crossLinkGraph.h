#pragma once
#include<vector>
#include<iostream>

template<class T>
class CrossLinkGraph {
private:
	typedef struct edge {
		int tail;
		edge* tNext;
		int head;
		edge* hNext;
		int weight;
	}Edge;

	typedef struct {
		int no;
		T show;
		Edge* firstIn;
		Edge* firstOut;
	}Vertex;

	Vertex* vertexs;
	int vertexNum;
	int edgeNum;

public:
	CrossLinkGraph(std::vector<T>targets) :edgeNum(0),vertexNum(targets.size()) {
		int n = targets.size();
		vertexs = new Vertex[n];
		for (int i = 0; i < n; i++) {
			vertexs[i].no = i;
			vertexs[i].show = targets[i];
			vertexs[i].firstIn = vertexs[i].firstOut = nullptr;
		}
	}

	~CrossLinkGraph() {
		if (vertexs) {
			int cnt = 0;
			for (int i = 0; i < vertexNum; i++) {
				Edge* cur = vertexs[i].firstOut;
				while (cur) {
					Edge* temp = cur;
					cur = cur->tNext;
					delete(temp);
					++cnt;
				}
			}
			delete[](vertexs);
			std::cout << "Graph has released " << cnt << " edges" << std::endl;
		}
	}

	void addEdge(int tail, int head, int w) {
		if (tail < 0 || tail >= vertexNum || head < 0 || head >= vertexNum)return;
		Edge* edge = new Edge;

		edge->tail = tail;
		edge->tNext = vertexs[tail].firstOut;
		vertexs[tail].firstOut = edge;

		edge->head = head;
		edge->hNext = vertexs[head].firstIn;
		vertexs[head].firstIn = edge;

		++edgeNum;
		edge->weight = w;
	}

	int InDegreeCount(int no) {
		int cnt = 0;
		Edge* cur = vertexs[no].firstIn;
		while (cur) {
			++cnt;
			cur = cur->hNext;
		}
		return cnt;
	}

	int OutDegreeCount(int no) {
		int cnt = 0;
		Edge* cur = vertexs[no].firstOut;
		while (cur) {
			++cnt;
			cur = cur->tNext;
		}
		return cnt;
	}
};
#pragma once
#include<vector>
#include<iostream>

template<class T>
class AdjacencyMultiList {
private:
	typedef struct node {
		int weight;
		int mark;
		int iVex;
		struct node* iLink;
		int jVex;
		struct node* jLink;
	}Edge;

	typedef struct {
		int no;
		T show;
		Edge* firstEdge;
	}Vertex;

	Vertex* vertexs;
	int vertexNum;
	int edgeNum;
	
private:
	void initMark() {
		for (int i = 0; i < vertexNum; i++) {
			Edge* cur = vertexs[i].firstEdge;
			while (cur) {
				cur->mark = 0;
				if (cur->iVex == i)cur = cur->iLink;
				else cur = cur->jLink;
			}
		}
	}

public:
	AdjacencyMultiList(std::vector<T>targets) :
		vertexNum(targets.size()), edgeNum(0) {
		vertexs = new Vertex[targets.size()];
		for (int i = 0; i < vertexNum; i++) {
			vertexs[i].no = i;
			vertexs[i].show = targets[i];
			vertexs[i].firstEdge = nullptr;
		}
	}

	~AdjacencyMultiList() {
		if (!vertexs) return;

		// 1. 为指针数组分配内存
		Edge** edges = new Edge * [edgeNum];
		int cnt = 0;

		initMark();

		for (int i = 0; i < vertexNum; i++) {
			Edge* cur = vertexs[i].firstEdge;
			while (cur) {
				// 先处理当前节点，再移动到下一个节点
				Edge* temp = cur;
				if (cur->iVex == i) {
					cur = cur->iLink;
				}
				else {
					cur = cur->jLink;
				}

				if (temp->mark == 0) {
					temp->mark = 1;
					// 确保不会越界
					if (cnt < edgeNum) {
						edges[cnt] = temp;
						++cnt;
					}
				}
			}
		}
		// 2. 释放所有收集到的边
		for (int i = 0; i < cnt; i++) {
			delete edges[i];
		}

		// 3. 释放指针数组本身
		delete[] edges;

		// 4. 释放顶点数组
		delete[] vertexs;

		std::cout << "graph has released " << cnt << " edges" << std::endl;
	}

	void addEdge(int a, int b, int w) {
		if (a < 0 || a >= vertexNum || b < 0 || b >= vertexNum)return;
		Edge* edge = new Edge;
		edge->weight = w;
		++edgeNum;

		edge->iVex = a;
		edge->iLink = vertexs[a].firstEdge;
		vertexs[a].firstEdge = edge;

		edge->jVex = b;
		edge->jLink = vertexs[b].firstEdge;
		vertexs[b].firstEdge = edge;
	}

	void show(){
		initMark();
		for (int i = 0; i < vertexNum; i++) {
			Edge* cur = vertexs[i].firstEdge;
			while (cur) {
				if (cur->mark==0) {
					cur->mark = 1;
					std::cout << vertexs[cur->iVex].show << "--" << cur->weight << "--" << vertexs[cur->jVex].show << std::endl;
				}
				if (cur->iVex == i)cur = cur->iLink;
				else cur = cur->jLink;
			}
		}
	}

	void deleteEdge(int a, int b) {
		if (a < 0 || a >= vertexNum || b < 0 || b >= vertexNum)return;

		Edge* aPre = nullptr;
		Edge* aCur = vertexs[a].firstEdge;
		while (aCur &&
			!((aCur->iVex == a && aCur->jVex == b) || (aCur->jVex == a || aCur->iVex == b))) {
			aPre = aCur;
			if (aCur->iVex == a)aCur = aCur->iLink;
			else aCur = aCur->jLink;
		}
		if (!aCur)return;

		Edge* bPre = nullptr;
		Edge* bCur = vertexs[b].firstEdge;
		while (bCur &&
			!((bCur->iVex == a && bCur->jVex == b) || (bCur->iVex == b && bCur->jVex == a))) {
			bPre = bCur;
			if (bCur->iVex)bCur = bCur->iLink;
			else bCur = bCur->jLink;
		}
		if (!bCur)return;

		if (!aPre) {
			if (aCur->iVex == a)vertexs[a].firstEdge = aCur->iLink;
			else vertexs[a].firstEdge = aCur->jLink;
		}
		else {
			if (aPre->iVex == a && aCur->iVex == a)aPre->iLink = aCur->iLink;
			else if (aPre->iVex == a && aCur->jVex == a)aPre->iLink = aCur->jLink;
			else if (aPre->jVex == a && aCur->iVex == a)aPre->jLink = aCur->iLink;
			else aPre->jLink = aCur->jLink;
		}

		if (!bPre) {
			if (bCur->iVex == b)vertexs[b].firstEdge = bCur->iLink;
			else vertexs[b].firstEdge = bCur->jLink;
		}
		else {
			if (bPre->iVex == b && bCur->iVex == b)bPre->iLink = bCur->iLink;
			else if (bPre->iVex == b && bCur->jVex == b)bPre->iLink = bCur->jLink;
			else if (bPre->jVex == b && bCur->iVex == b)bPre->jLink = bCur->iLink;
			else bPre->jLink = bCur->jLink;
		}

		delete(aCur);
		--edgeNum;
	}
};

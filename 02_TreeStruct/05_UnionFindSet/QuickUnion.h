#pragma once
#include<vector>

template<class T>
class QUSet {
private:
	T* data;
	int* parent;
	int* size;
	int n;
	int capacity;

	//路径压缩时保存路径的结点
	typedef struct node {
		int index;
		node* next;
	}Node;

	int findIndex(T v) {
		for (int i = 0; i < n; i++) {
			if (data[i] == v) {
				return i;
			}
		}
		return -1;
	}

	int findRootIndex(T v) {
		int index = findIndex(v);
		if (index == -1)return -1;
		while (parent[index] != index)index = parent[index];
		return index;
	}

	int findRootIndexWithPathCompress(T v) {
		int index = findIndex(v);
		if (index == -1)return -1;
		Node* stacktop = nullptr;
		while (parent[index] != index) {
			Node* node = new Node;
			node->index = index;
			node->next = stacktop;
			stacktop = node;
			index = parent[index];
		}
		while (stacktop) {
			Node* temp = stacktop;
			parent[temp->index] = index;
			stacktop = stacktop->next;
			delete(temp);
		}
		return index;
	}

public:

	QUSet(int c) {
		capacity = c;
		n = 0;
		data = new T[c];
		parent = new int[c];
		size = new int[c];
	}

	QUSet(std::vector<T>data) {
		int len = data.size();
		this->data = new T[len];
		parent = new int[len];
		size = new int[len];
		for (int i = 0; i < len; i++) {
			this->data[i] = data[i];
			this->parent[i] = i;
			this->size[i] = 1;
		}
		n = len;
		capacity = len;
	}

	~QUSet() {
		if (n) {
			delete(data);
			delete(parent);
			delete(size);
			n = capacity = 0;
		}
	}

	int isSame(T a, T b) {
		//int rootA = findRootIndex(a);
		//int rootB = findRootIndex(b);
		int rootA = findRootIndexWithPathCompress(a);
		int rootB = findRootIndexWithPathCompress(b);
		if (rootA == -1 || rootB == -1)return 0;
		return rootA == rootB;
	}

	void QuickUnion(T a,T b) {
		//int rootA = findRootIndex(a);
		//int rootB = findRootIndex(b);
		int rootA = findRootIndexWithPathCompress(a);
		int rootB = findRootIndexWithPathCompress(b);
		if (rootA == -1 || rootB == -1)return;
		if (rootA == rootB)return;
		if (size[rootA] < size[rootB]) {
			parent[rootA] = rootB;
			size[rootB] += size[rootA];
		}
		else {
			parent[rootB] = rootA;
			size[rootA] += size[rootB];
		}
	}
};
#pragma once
#include<iostream>
#include<string>

typedef char* Huffmancode;

class HuffmanTree {
private:
	typedef struct {
		int parent;
		int weight;
		int lchild;
		int rchild;
	}Node;
	Node* tree;
	void GetTwoMinWeight(int n,int& s1, int& s2) {
		for (int i = 1; i <= n; i++) {
			if (!tree[i].parent) {
				if (!s1)s1 = i;
				else if (!s2) {
					s2 = i;
					if (tree[s1].weight > tree[s2].weight) std::swap(s1, s2);
				}
				else {
					if (tree[i].weight < tree[s1].weight) {
						s2 = s1;
						s1 = i;
					}
					else if (tree[i].weight < tree[s2].weight)s2 = i;
				}
			}
		}
	}
public:
	HuffmanTree(const int* w, int n) {
		int m = 2 * n - 1;
		tree = new Node[m+1];
		for (int i = 1; i <= m; i++) {
			tree[i].parent = tree[i].lchild = tree[i].rchild = 0;
			if (i <= n)tree[i].weight = w[i - 1];
			else tree[i].weight = 0;
		}
		
		for (int i = n + 1; i <= m; i++) {
			int s1 = 0, s2 = 0;
			GetTwoMinWeight(i-1,s1, s2);
			tree[i].lchild = s1, tree[i].rchild = s2;
			tree[i].weight = tree[s1].weight + tree[s2].weight;
			tree[s1].parent = tree[s2].parent = i;
		}
	}

	~HuffmanTree() {
		if (tree)delete(tree);
	}

public:
	
	Huffmancode* creatHuffmanCodes(int n) {
		Huffmancode* codes = new Huffmancode[n];
		memset(codes, 0, sizeof(Huffmancode)*n);
		char* temp = new char[n + 1];
		for (int i = 1; i <= n; i++) {
			int p = tree[i].parent;
			int pos = i;
			int start = n - 1;
			temp[start] = '\0';
			while (p) {
				temp[--start] = tree[p].lchild == pos ? '0' : '1';
				pos = p;
				p = tree[p].parent;
			}
			codes[i - 1] = new char[n - start];
			std::strcpy(codes[i - 1], &temp[start]);
		}
		delete(temp);
		return codes;
	}

	void releaseHuffmanCodes(Huffmancode* codes, int n) {
		if (codes) {
			for (int i = 0; i < n; i++)delete codes[i];
			delete codes;
		}
		std::cout << "Huffmancodes has released" << std::endl;
	}
};
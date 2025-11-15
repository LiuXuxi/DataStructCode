#pragma once
#include<iostream>
template<class T>
class BSTree {
private:
	typedef struct node {
		struct node* left;
		struct node* right;
		T data;
	}BSNode;
	BSNode* root;
	int cnt;
	void visitBSNode(BSNode* node) {
		if (node)std::cout << node->data << " ";
		else std::cout << "node is nullptr" << std::endl;
	}
	BSNode* creatBSNode(T v) {
		BSNode* node = new BSNode;
		node->data = v;
		node->left = node->right = nullptr;
		return node;
	}
	BSNode* insert(BSNode* node, T v) {
		if (!node) {
			++cnt;
			return creatBSNode(v);
		}
		if (v<node->data)node->left = insert(node->left, v);
		else if (v>node->data)node->right = insert(node->right, v);
		return node;
	}
	void inOrder(BSNode* node) {
		if (!node)return;
		inOrder(node->left);
		visitBSNode(node);
		inOrder(node->right);
	}
	void freeBSNode(BSNode* node) {
		if (!node)return;
		freeBSNode(node->left);
		freeBSNode(node->right);
		delete node;
		--cnt;
	}
	int getHeight(BSNode* node) {
		if (!node)return 0;
		int lcnt = getHeight(node->left);
		int rcnt = getHeight(node->right);
		return (lcnt > rcnt) ? lcnt + 1 : rcnt + 1;
	}
public:
	BSTree() {
		root = nullptr;
		cnt = 0;
	}
	BSTree(T v) {
		root = creatBSNode(v);
		cnt = 1;
	}
	~BSTree() {
		if (root) {
			freeBSNode(root);
		}
		std::cout << "the tree has been destroyed, remaining " << cnt << " node" << std::endl;
	}
	void insertBSNode(T v) {
		root = insert(root, v);
	}
	void searchBSNode(T v) {
		if (root) {
			BSNode* node = root;
			while (node) {
				if (v == node->data) {
					std::cout << "find v succeed" << std::endl;
					return;
				}
				if (v > node->data)node = node->right;
				else node = node->left;
			}
			std::cout << "find failed" << std::endl;
		}
	}
	void inOrderBSTree() {
		if (root) {
			inOrder(root);
		}
		std::cout << std::endl;
	}
	int getCnt() {
		return cnt;
	}
	int getHightBSTree() {
		if (root)return getHeight(root);
		else return 0;
	}
};
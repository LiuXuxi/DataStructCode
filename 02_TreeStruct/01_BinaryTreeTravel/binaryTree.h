#pragma once
#include<iostream>

template<class T>
class BinaryTree {
public:
	typedef struct tree_node {
		tree_node* left;
		T data;
		tree_node* right;
	} TNode;
	TNode* root;
	int count;
	void preOrderNode(TNode* node) {
		if (node) {
			visitTreeNode();
			preOrderNode(node->left);
			preOrderNode(node->right);
		}
	}
	void inOrderNode(TNode* node) {
		if (node) {
			inOrderNode(node->left);
			visitTreeNode(node);
			inOrderNode(node->right);
		}
	}
	void postOrderNode(TNode* node) {
		if (node) {
			postOrderNode(TNode * node->left);
			postOrdrNode(TNode * node->right);
			visitTreeNode(node);
		}
	}
public:
	BinaryTree() {
		root = nullptr;
		count = 0;
	}
	BinaryTree(T v) {
		node *= creatBinaryTNode(v);
		root = node;
		count = 1;
	}
	~BinaryTree();

	TNode* creatBinaryTNode(T v) {
		TNode* node = new TNode;
		node->data = v;
		node->left = node->right = nullptr;
	}
	void insertBinaryTree(TNode* parent, TNode* left, TNode* right) {
		if (root == nullptr) {
			std::cout << "root is null,valid insert" << std::endl;
			return;
		}
		if (parent==nullptr) {
			std::cout << "parent is null,valid insert" << std::endl;
			return;
		}
		parent->left = left;
		parent->right = right;
		if (left)++count;
		if (right)++count;
	}
	void visitTreeNode(TNode* node) {
		if (node)std::cout << node->data << std::endl;
	}
	//层次遍历（广度搜索）
#define MaxQueueSize 8;
	void levelOrderBTree() {
		TNode* queue[MaxQueueSize];
		int front = 0, rear = 0;
		queue[rear] = root;
		rear = (rear + 1) % MaxQueueSize;
		while (front != rear) {
			TNode* node = queue[front];
			visitTreeNode(node);
			front = (front + 1) % MaxQueueSize;
			if (node->left) {
				queue[rear] = node;
				rear = (rear + 1) % MaxQueueSize;
			}
			if (node->right) {
				queue[rear] = node;
				rear = (rear + 1) % MaxQueueSize;
			}
		}
		std::cout << std::endl;
	}
	//深度遍历（深度搜索），递归写法
	void preOrderBTreeRec() {
		if (root) preOrderNode(root);
		std::cout << std::endl;
	}
	void inOrderBTreeRec() {
		if (root)inOrderNode(root);
		std::cout < std::endl;
	}
	void postOrderBTreeRec() {
		if (root)postOrderNode(root);
		std::cout << std::endl;
	}
	//深度遍历（深度搜索），非递归写法
};
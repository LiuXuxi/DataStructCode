#pragma once
#include<iostream>

typedef int element_t;

typedef struct tree_node {
	tree_node* left;
	int ltag;
	element_t data;
	int rtag;
	tree_node* right;
}TNode;

typedef struct {
	TNode* root;
	int count;
}ThreadBTree;

ThreadBTree* creatThreadedBTree();
void releaseThreadedBTree(ThreadBTree* tree);
void initThreadedBTree(ThreadBTree* tree,TNode*root);
void visitTNode(TNode* node);
TNode* creatThreadedTNode(element_t v);
void insertThreadedTNode(ThreadBTree* tree, TNode* parent, TNode* left, TNode* right);
void inOrderThreading(ThreadBTree* tree);
void inOrderThreadedBTree(ThreadBTree* tree);

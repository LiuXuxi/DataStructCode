#include"ThreadedBTree.h"
#include<iostream>

ThreadBTree* creatThreadedBTree()
{
	ThreadBTree* tree = new ThreadBTree;
	tree->count = 0;
	tree->root = nullptr;
	return tree;
}

static void freeTNode(ThreadBTree* tree,TNode* node) {
	if (!node)return;
	if(!node->ltag)freeTNode(tree,node->left);
	if(!node->right)freeTNode(tree,node->right);
	delete(node);
	--tree->count;
}

void releaseThreadedBTree(ThreadBTree* tree)
{
	TNode* node = tree->root;
	freeTNode(tree,node);
	std::cout << "the tree remains " << tree->count << " nodes" << std::endl;
	delete(tree);
}

void initThreadedBTree(ThreadBTree* tree, TNode* root)
{
	if (tree && !tree->root) {
		tree->root = root;
		tree->count = 1;
	}
}

void visitTNode(TNode* node)
{
	if (node) {
		std::cout << node->data << " ";
	}
}

TNode* creatThreadedTNode(element_t v)
{
	TNode* node = new TNode;
	node->data = v;
	node->left = node->right = nullptr;
	node->ltag = node->rtag = 0;
	return node;
}

void insertThreadedTNode(ThreadBTree* tree, TNode* parent, TNode* left, TNode* right)
{
	if (tree && parent) {
		parent->left = left;
		parent->right = right;
		tree->count += (left ? 1 : 0) + (right ? 1 : 0);
	}
}

static TNode* prev = nullptr;

static void inThreading(TNode* node) {
	if (node==nullptr)return;
	inThreading(node->left);
	if (!node->left) {
		node->ltag = 1;
		node->left = prev;
	}
	if (prev && !prev->right) {
		prev->rtag= 1;
		prev->right = node;
	}
	prev = node;
	inThreading(node->right);
}

void inOrderThreading(ThreadBTree* tree)
{
	TNode* node = tree->root;
	prev = nullptr;
	inThreading(node);
	if (prev) {
		prev->right = nullptr;
		prev->rtag = 1;
	}
}

void inOrderThreadedBTree(ThreadBTree* tree)
{
	TNode* node = tree->root;
	while (!node->ltag) {
		node = node->left;
	}
	while (node) {
		visitTNode(node);
		if (node->rtag)node = node->right;
		else {
			node = node->right;
			while (!node->ltag&&node) {
				node = node->left;
			}
		}
	}
}





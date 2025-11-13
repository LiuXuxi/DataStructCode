#include"ThreadedBTree.h"
#include<iostream>

void ThreadedBTree() {
	ThreadBTree* tree = creatThreadedBTree();
	TNode* node[7];
	for (int i = 0; i < 5; i++)node[i] = creatThreadedTNode(i + 1);
	initThreadedBTree(tree, node[0]);
	insertThreadedTNode(tree, node[0], node[1], node[2]);
	insertThreadedTNode(tree, node[1], node[3], node[4]);
	insertThreadedTNode(tree, node[2], node[5], node[6]);
	insertThreadedTNode(tree, node[3], nullptr, nullptr);
	insertThreadedTNode(tree, node[4], nullptr, nullptr);
	insertThreadedTNode(tree, node[5], nullptr, nullptr);
	insertThreadedTNode(tree, node[6], nullptr, nullptr);
	inOrderThreading(tree);
	std::cout << "the tree remain " << tree->count << " nodes:";
	inOrderThreadedBTree(tree);
	std::cout << std::endl;
	releaseThreadedBTree(tree);
}

static ThreadBTree* initTestTree() {
	ThreadBTree* tree = creatThreadedBTree();

	TNode* nodeA = creatThreadedTNode('A');
	TNode* nodeB = creatThreadedTNode('B');
	TNode* nodeC = creatThreadedTNode('C');
	TNode* nodeD = creatThreadedTNode('D');
	TNode* nodeE = creatThreadedTNode('E');
	TNode* nodeF = creatThreadedTNode('F');
	TNode* nodeG = creatThreadedTNode('G');
	TNode* nodeH = creatThreadedTNode('H');
	TNode* nodeK = creatThreadedTNode('K');

	initThreadedBTree(tree, nodeA);
	insertThreadedTNode(tree, nodeA, nodeB, nodeE);
	insertThreadedTNode(tree, nodeB, NULL, nodeC);
	insertThreadedTNode(tree, nodeC, nodeD, NULL);
	insertThreadedTNode(tree, nodeE, NULL, nodeF);
	insertThreadedTNode(tree, nodeF, nodeG, NULL);
	insertThreadedTNode(tree, nodeG, nodeH, nodeK);
	return tree;
}

int main() {
	ThreadedBTree();
	/*ThreadBTree* tree = initTestTree();
	printf("tree node: %d\n", tree->count);
	inOrderThreading(tree);
	inOrderThreadedBTree(tree);
	printf("\n");
	releaseThreadedBTree(tree);*/
	return 0;
}
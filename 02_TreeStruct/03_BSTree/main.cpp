#include"BSTree.h"
#include<iostream>

void BSTreeTest() {
	int data[8] = { 1,34,5,35,63,86,45,453 };
	BSTree<int>a(10);
	std::cout << a.getHightBSTree() << std::endl;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)a.insertBSNode(data[i]);
	std::cout << a.getHightBSTree() << std::endl;
	a.inOrderBSTree();
	a.searchBSNode(10);
	a.searchBSNode(1000);
	std::cout << a.getCnt() << std::endl;
}

int main() {
	BSTreeTest();
	return 0;
}
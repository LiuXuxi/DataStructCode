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
	std::cout << "==================" << std::endl;
	a.deleteBSTree(86);
	a.inOrderBSTree();
	a.deleteBSTree(60);
	a.inOrderBSTree();
}

void BSTreeTest2() {
	int data[8] = { 1,34,5,35,63,86,45,453 };
	BSTree<int>a(10);
	std::cout << a.getHightBSTree() << std::endl;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)a.insertBSNodeV2(data[i]);
	std::cout << a.getHightBSTree() << std::endl;
	a.inOrderBSTree();
	a.searchBSNode(10);
	a.searchBSNode(1000);
	std::cout << a.getCnt() << std::endl;
	std::cout << "==================" << std::endl;
	a.deleteBSTreeV2(86);
	a.inOrderBSTree();
	a.deleteBSTreeV2(60);
	a.inOrderBSTree();
}

void BSTreeTest3() {
	int data[8] = { 1,34,5,35,63,86,45,453 };
	BSTree<int>a;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)a.insertBSNodeV2(data[i]);
	a.preOrderCur();
	a.preOrderNoCur();
	std::cout << "===============" << std::endl;
	a.inOrderBSTree();
	a.inOrderBSTreeNoCur();
	std::cout << "====================" << std::endl;
	a.postOrderCur();
	a.postOrderNoCur();

}

int main() {
	BSTreeTest3();
	return 0;
}
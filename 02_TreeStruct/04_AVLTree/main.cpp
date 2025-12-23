#include"AVLTree.h"
#include<vector>

void test01() {
	std::vector<int>a{ 30,20,40,10,25,35,50,5 };
	AVLTree<int>tree;
	std::cout << "the height of tree is " << tree.getHeight() << std::endl;
	std::cout << "the count of tree is " << tree.getCount() << std::endl;
	for (auto i : a)tree.insertAVLNode(i);
	std::cout << "the height of tree is " << tree.getHeight() << std::endl;
	std::cout << "the count of tree is " << tree.getCount() << std::endl;
	tree.inOrderAVLTree();
	tree.deleteAVLNode(20);
	tree.inOrderAVLTree();
	std::cout << "the height of tree is " << tree.getHeight() << std::endl;
	std::cout << "the count of tree is " << tree.getCount() << std::endl;
	tree.deleteAVLNode(9);
	tree.inOrderAVLTree();
	std::cout << "the height of tree is " << tree.getHeight() << std::endl;
	std::cout << "the count of tree is " << tree.getCount() << std::endl;
}

int main() {
	test01();
	return 0;
}
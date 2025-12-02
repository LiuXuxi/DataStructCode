#include"huffmantree.h"

void test() {
	int w[]{ 5,29,7,8,14,23,3,11 };
	char show[]{ 'A','B','C','D','E','F','G','H' };
	HuffmanTree tree(w, sizeof(w) / sizeof(w[0]));
	Huffmancode* codes = tree.creatHuffmanCodes(sizeof(w) / sizeof(w[0]));
	for (int i = 0; i < sizeof(w) / sizeof(w[0]); i++)std::cout << show[i] << " " << codes[i] << std::endl;
	tree.releaseHuffmanCodes(codes, sizeof(w) / sizeof(w[0]));
}

int main() {
	test();
	return 0;
}

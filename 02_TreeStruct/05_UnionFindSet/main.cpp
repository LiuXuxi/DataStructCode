#include"QuickFindSet.h"
#include"QuickUnion.h"
#include<iostream>

void test01() {
	QFSet<int>qfset(9);
	std::vector<int>nums;
	for (int i = 0; i < 9; i++)nums.push_back(i);
	qfset.initQFSet(nums);
	qfset.UnionQF(3, 4);
	qfset.UnionQF(8, 0);
	qfset.UnionQF(2, 3);
	qfset.UnionQF(5, 6);
	qfset.isSameQF(0, 2) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	qfset.isSameQF(2, 4) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	qfset.UnionQF(5, 1);
	qfset.UnionQF(7, 3);
	qfset.UnionQF(1, 6);
	qfset.UnionQF(4, 8);
	qfset.isSameQF(0, 2) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	qfset.isSameQF(2, 4) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
}

void test02() {
	std::vector<int>nums;
	for (int i = 0; i < 9; i++)nums.push_back(i);
	QUSet<int>quset(nums);
	quset.QuickUnion(3, 4);
	quset.QuickUnion(8, 0);
	quset.QuickUnion(2, 3);
	quset.QuickUnion(5, 6);
	quset.isSame(0, 2) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	quset.isSame(2, 4) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	quset.QuickUnion(5, 1);
	quset.QuickUnion(7, 3);
	quset.QuickUnion(1, 6);
	quset.QuickUnion(4, 8);
	quset.isSame(0, 2) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
	quset.isSame(2, 4) ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
}

int main() {
	test01();
	std::cout << "========================" << std::endl;
	test02();
	return 0;
}
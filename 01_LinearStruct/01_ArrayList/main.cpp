#include<iostream>
#include"arraylist.h"

void test01() {
	vector a(10);
	if (a.isEmpty()) {
		for (int i = 0; i < 10; i++) {
			a.push_back(i + 10);
		}
	}
	a.show();
	a.push_back(100);
	a.show();
	a.delValue(20);
	a.show();
	a.delValue(140);
	a.show();
	a.insertValue(4, 55);
	a.show();
	std::cout << a.findValue(55) << std::endl;
	std::cout << a.findValue(409) << std::endl;
	std::cout << a.getLen() << " " << a.getCapacity() << std::endl;
}

int main() {
	test01();
	return 0;
}

#include<iostream>
#include"doublelinkloop.h"

void doubleloopTest() {
	DoubleLoop<int>loop;
	for (int i = 0; i < 5; i++) {
		loop.push_back(i * 10);
	}
	loop.show();
	loop.delValue(10);
	loop.show();
	loop.delValue(5);
	for (int i = 0; i < 5; i++) {
		loop.push_front(i + 10);
	}
	loop.show();
	std::cout << loop.getNum() << std::endl;
}

int main() {
	doubleloopTest();
	return 0;
}
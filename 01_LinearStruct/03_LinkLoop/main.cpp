#include"linkloop.h"
#include<iostream>

void LinkLoopTest() {
	LinkLoop<int>loop;
	for (int i = 0; i < 5; i++) loop.push_back(i * 10);
	loop.show();
	loop.delValue(40);
	loop.show();
	loop.delValue(60);
	loop.show();
	for (int i = 0; i < 5; i++) loop.Push_front(i + 10);
	loop.show();
	loop.push_pos(4, 100);
	loop.show();
}

int main() {
	LinkLoopTest();
	return 0;
}
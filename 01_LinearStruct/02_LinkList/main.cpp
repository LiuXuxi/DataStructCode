#include"linklist.h"
#include<iostream>

void linkTableTest() {
	LinkTable table;
	for (int i = 0; i < 5; i++) {
		table.push_back(i * 10);
	}
	table.show();
	table.delValue(30);
	table.show();
	table.delValue(60);
	table.show();
	for (int i = 0; i < 5; i++) {
		table.push_front(i + 10);
	}
	table.show();
	table.push_pos(500, 1);
	table.show();
}

void linklistTest() {
	LinkList list;
	for (int i = 0; i < 5; i++) {
		list.push_back(i * 10);
	}
	list.show();
	list.delValue(30);
	list.show();
	list.delValue(60);
	list.show();
	for (int i = 0; i < 5; i++) {
		list.push_front(i + 10);
	}
	list.show();
	list.push_pos(500, 1);
	list.show();
}

int main() {
	//linkTableTest();
	linklistTest();
	return 0;
}
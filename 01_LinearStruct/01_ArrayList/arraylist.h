#pragma once

#include<iostream>

typedef int element_t;

class vector {
private:
	int len;
	int capacity;
	element_t* data;
	void enlarge();
public:
	vector(int num);
	~vector();
	int isEmpty();
	void push_back(element_t v);
	void insertValue(int pos, element_t v);
	int findValue(element_t v);
	void delValue(element_t v);
	void show();
	int getLen();
	int getCapacity();
};
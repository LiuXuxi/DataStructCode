#include"arraylist.h"
#include<iostream>

void vector::enlarge()
{
	if (len >= capacity) {
		element_t* temp = new element_t[capacity * 2];
		for (int i = 0; i < len; i++) {
			temp[i] = data[i];
		}
		delete(data);
		data = temp;
		capacity *= 2;
	}
}

vector::vector(int num):data(new element_t[num]),len(0),capacity(num) {}

vector::~vector()
{
	if (data != nullptr) {
		delete(data);
	}
	capacity = 0;
	len = 0;
	std::cout << "clear" << std::endl;
}

int vector::isEmpty()
{
	return len == 0;
}

void vector::push_back(element_t v)
{
	if (len >= capacity)enlarge();
	data[len++] = v;
}

void vector::insertValue(int pos,element_t v) {
	if (len >= capacity)enlarge();
	for (int i = len - 1; i >= pos; i--) data[i + 1] = data[i];
	data[pos] = v;
}

int vector::findValue(element_t v) {
	for (int i = 0; i < len; i++) {
		if (data[i] == v)return i;
	}
	return -1;
}

void vector::delValue(element_t v) {
	int pos = findValue(v);
	if (pos == -1) {
		std::cout << "no find value" << std::endl;
		return;
	}
	for (int i = pos; i < len; i++) {
		data[i] = data[i + 1];
	}
	--len;
}

void vector::show() {
	if (!len) {
		std::cout << "the vector is null" << std::endl;
		return;
	}
	for (int i = 0; i < len; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

int vector::getLen() { return len; }

int vector::getCapacity() { return capacity; }
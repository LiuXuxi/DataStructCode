#pragma once
#include"../sortHelper.h"
#include<iostream>


class miniHeap {
private:
	keyType* data;
	int len;
	int capacity;

	void shiftup(int index);

	void shiftdown(int index);

public:
	miniHeap(int n);

	~miniHeap();

	void insert(keyType v);

	bool isEmpty() const;

	int size() const;

	keyType extract();
};

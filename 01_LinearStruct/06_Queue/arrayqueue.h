#pragma once
#define MaxQueSize 5
typedef int element_t;

class queue {
private:
	element_t data[MaxQueSize];
	int front;
	int rear;
public:
	queue();
	int isEmpty();
	int isFull();
	void push_rear(element_t v);
	void pop_front();
	element_t getFront();
};
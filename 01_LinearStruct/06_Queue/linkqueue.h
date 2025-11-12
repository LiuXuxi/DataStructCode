#pragma once

typedef int element_t;

class LinkQueue {
private:
	typedef struct link_node {
		element_t data;
		link_node* next;
	}QNode;
	QNode* rear;
	QNode* front;
	int count;
public:
	LinkQueue();
	~LinkQueue();
	void push_rear(element_t v);
	void pop_front();
	element_t getFront();
	int getCount();
};

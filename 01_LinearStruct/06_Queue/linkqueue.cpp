#include"linkqueue.h"
#include<iostream>

LinkQueue::LinkQueue() {
	rear = front = nullptr;
	count = 0;
}

LinkQueue::~LinkQueue()
{
	QNode* p = front;
	while (p) {
		QNode* temp = p;
		p = p->next;
		delete(temp);
		count--;
	}
}

void LinkQueue::push_rear(element_t v)
{
	QNode* node = new QNode;
	node->data = v;
	if (rear == nullptr) {
		rear = front = node;
	}
	else {
		node->next = nullptr;
		rear->next = node;
		rear = node;
	}
	count++;
}

void LinkQueue::pop_front() {
	if (rear == nullptr) {
		std::cout << "queue is empty" << std::endl;
		return;
	}
	QNode* temp = front;
	front = front->next;
	if (front == nullptr)rear = nullptr;
	delete(temp);
	count--;
}

element_t LinkQueue::getFront() {
	return front->data;
}

int LinkQueue::getCount() {
	return count;
}
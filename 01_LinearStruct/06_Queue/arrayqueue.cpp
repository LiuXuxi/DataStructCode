#include"arrayqueue.h"
#include<iostream>

queue::queue()
{
	front = rear = 0;
}

int queue::isEmpty() {
	return front == rear;
}

int queue::isFull()
{
	return (rear + 1) % MaxQueSize == front;
}

void queue::push_rear(element_t v)
{
	if (isFull()) {
		std::cout << "queue is full" << std::endl;
		return;
	}
	data[rear] = v;
	rear = (rear + 1) % MaxQueSize;
	return;
}

void queue::pop_front()
{
	if (isEmpty()) {
		std::cout << "queue is empty" << std::endl;
		return;
	}
	front = (front + 1) % MaxQueSize;
}

element_t queue::getFront()
{
	return data[front];
}





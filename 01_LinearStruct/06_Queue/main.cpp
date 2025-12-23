#include<iostream>
#include"arrayqueue.h"
#include"linkqueue.h"

void arrayqueueTest() {
	queue q;
	if (q.isEmpty()) {
		for (int i = 0; i < MaxQueSize-1; i++) {
			q.push_rear(i * 10);
		}
	}
	q.push_rear(80);
	q.pop_front();
	q.push_rear(80);
	while (!q.isEmpty()) {
		std::cout << q.getFront() << " ";
		q.pop_front();
	}
	std::cout << std::endl;
}

void linkqueueTest() {
	LinkQueue q;
	for (int i = 0; i < 5; i++) {
		q.push_rear(i * 10);
	}
	std::cout << q.getCount() << std::endl;
	std::cout << q.getFront() << std::endl;
	q.pop_front();
	std::cout << q.getFront() << std::endl;
	std::cout << q.getCount() << std::endl;
	while (q.getCount() != 0) {
		std::cout << q.getFront() << " ";
		q.pop_front();
	}
	std::cout << std::endl;
	std::cout << q.getCount() << std::endl;

}
int main() {
	//arrayqueueTest();
	linkqueueTest();
	return 0;
}
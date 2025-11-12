#pragma once

template<class T>
class LinkLoop {
private:
	typedef struct link_loop {
		T data;
		link_loop* next;
	}LNode;
	int num;
	LNode header;
	LNode* rear;
	void push(LNode*pre,T v);
	void del(LNode*pre);
public:
	LinkLoop();
	~LinkLoop();
	void push_back(T v);
	void Push_front(T v);
	void push_pos(int pos, T v);
	void delValue(T v);
	void show();

};

#include<iostream>

template<class T>
void LinkLoop<T>::push(LNode* pre, T v) {
	LNode* node = new LNode;
	node->data = v;
	node->next = pre->next;
	pre->next = node;
	if (node->next == &header) rear = node;
}

template<class T>
void LinkLoop<T>::del(LNode* pre) {
	LNode* temp = pre->next;
	pre->next = temp->next;
	if (pre->next == &header)rear = pre;
}

template<class T>
LinkLoop<T>::LinkLoop() {
	num = 0;
	rear = header.next = &header;
}

template<class T>
LinkLoop<T>::~LinkLoop() {
	LNode* pre = &header;
	while (pre->next != &header) {
		del(pre);
		num--;
	}
	std::cout << "Num:" << num << std::endl;
}

template<class T>
void LinkLoop<T>::push_back(T v) {
	LNode* pre = rear;
	push(pre, v);
	++num;
}

template<class T>
void LinkLoop<T>::Push_front(T v) {
	LNode* pre = &header;
	push(pre, v);
	++num;
}

template<class T>
void LinkLoop<T>::push_pos(int pos, T v) {
	if (pos<0 || pos>num) {
		std::cout << "invalid pos" << std::endl;
		return;
	}
	LNode* pre = &header;
	while (pos) {
		if (pre->next->data == v)break;
		pre = pre->next;
		--pos;
	}
	push(pre, v);
	++num;
}

template<class T>
void LinkLoop<T>::delValue(T v) {
	LNode* pre = &header;
	while (pre->next != &header) {
		if (pre->next->data == v) break;
		pre = pre->next;
	}
	if (pre->next == &header) {
		std::cout << "no find value" << std::endl;
		return;
	}
	del(pre);
	--num;
}

template<class T>
void LinkLoop<T>::show() {
	std::cout << "Num:" << num << "->";
	LNode* pre = header.next;
	while (pre != &header) {
		std::cout << pre->data<< " ";
		pre = pre->next;
	}
	std::cout << std::endl;
}
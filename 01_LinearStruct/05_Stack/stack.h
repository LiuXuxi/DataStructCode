#pragma once
#include<iostream>

//À≥–Ú’ª
template<class T>
class arrayStack {
private:
	int top;
	T* data;
	int capacity;
public:
	arrayStack(int n);
	~arrayStack();
	int isEmpty();
	int isFull();
	void push(T v);
	void pop(T&e);
};

template<class T>
arrayStack<T>::arrayStack(int n) {
	top = -1;
	capacity = n;
	data = new T[capacity];
}

template<class T>
arrayStack<T>::~arrayStack() {
	while (!isEmpty()) {
		int e;
		pop(e);
	}
	delete(data);
}

template<class T>
int arrayStack<T>::isEmpty() {
	return top == -1;
}

template<class T>
int arrayStack<T>::isFull() {
	return top == capacity - 1;
}

template<class T>
void arrayStack<T>::push(T v) {
	if (isFull()) {
		std::cout << "stack is full" << std::endl;
		return;
	}
	++top;
	data[top] = v;
}

template<class T>
void arrayStack<T>::pop(T&e) {
	if (isEmpty()) {
		std::cout << "stack is empty" << std::endl;
	}
	e = data[top--];
}

//¡¥ Ω’ª
template<class T>
class linkStack {
private:
	typedef struct link_node {
		T data;
		link_node* next;
	}SNode;
	int num;
	SNode* top;
public:
	linkStack();
	~linkStack();
	int isEmpty();
	void push(T v);
	int getNum();
	void getTop(T&e);
	void pop();
};

template<class T>
linkStack<T>::linkStack() {
	num = 0;
	top = nullptr;
}

template<class T>
linkStack<T>::~linkStack() {
	while (!isEmpty())pop();
	num = 0;
}

template<class T>
int linkStack<T>::isEmpty() {
	return top == nullptr;
}

template<class T>
void linkStack<T>::push(T v) {
	SNode* node = new SNode;
	node->data = v;
	node->next = top;
	top = node;
	++num;
}

template<class T>
int linkStack<T>::getNum() {
	return num;
}

template<class T>
void linkStack<T>::getTop(T&e) {
	if (isEmpty()) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	e = top->data;
}

template<class T>
void linkStack<T>::pop() {
	if (isEmpty()) {
		std::cout << "stack is empty" << std::endl;
		return;
	}
	SNode* temp = top;
	top = top->next;
	delete(temp);
	--num;
}
#include<iostream>

template<class T>
class DoubleLoop {
private:
	typedef struct doubleloop {
		doubleloop* pre;
		T data;
		doubleloop* next;
	}DNode;
	DNode header;
	int num;
	void push(DNode*node,DNode* pre, DNode* next) {
		next->pre = node;
		node->next = next;
		node->pre = pre;
		pre->next = node;
	}
	void del(DNode* pre, DNode* next) {
		pre->next = next;
		next->pre = pre;
	}
public:
	DoubleLoop() {
		header.next = header.pre = &header;
		num = 0;
	}
	~DoubleLoop() {
		DNode* node = header.next;
		while (node != &header) {
			del(node->pre, node->next);
			delete(node);
			node = header.next;
			--num;
		}
		std::cout << "Num:" << num << std::endl;
	}
	void push_front(T v) {
		DNode* node = new DNode;
		node->data = v;
		push(node, &header, header.next);
		++num;
	}
	void push_back(T v) {
		DNode* node = new DNode;
		node->data = v;
		push(node, header.pre, &header);
		++num;
	}
	void delValue(T v) {
		DNode* pos = header.next;
		while (pos != &header) {
			if (pos->data == v) {
				del(pos->pre, pos->next);
				--num;
				return;
			}
			pos = pos->next;
		}
		if (pos == &header) {
			std::cout << "no find value" << std::endl;
			return;
		}
	}
	void show() {
		std::cout << "Num:" << num << "->";
		DNode* pos = header.next;
		while (pos != &header) {
			std::cout << pos->data << " ";
			pos = pos->next;
		}
		std::cout << std::endl;
	}
	int getNum() { 
		return num;
	}
};
#include"linklist.h"
#include<iostream>

//带头结点的单向链表接口实现
void LinkTable::push(LNode* pre, element_t v) {
	LNode* node = new LNode;
	node->data = v;
	node->next = pre->next;
	pre->next = node;
}

void LinkTable::del(LNode* pre) {
	LNode* temp = pre->next;
	pre->next = temp->next;
	delete(temp);
}

LinkTable::LinkTable() {
	num = 0;
	header.next = nullptr;
}

LinkTable::~LinkTable()
{
	LNode* pre = &header;
	while (pre->next == nullptr) {
		del(pre);
	}
	num = 0;
}

void LinkTable::push_back(element_t v) {
	LNode* pre = &header;
	while (pre->next != nullptr) {
		pre = pre->next;
	}
	push(pre, v);
	num++;
}

void LinkTable:: push_front(element_t v) {
	LNode* pre = &header;
	push(pre, v);
	num++;
}

void LinkTable::push_pos(element_t v, int pos) {
	LNode* pre = &header;
	if (pos<0 || pos>num) {
		std::cout << "invalid pos" << std::endl;
		return;
	}
	while (pos) {
		pos--;
		pre = pre->next;
	}
	push(pre, v);
	num++;
}

void LinkTable::delValue(element_t v) {
	LNode* pre = &header;
	while (pre->next != nullptr) {
		if (pre->next->data == v) {
			break;
		}
		pre = pre->next;
	}
	if (pre->next == nullptr) {
		std::cout << "invalid del" << std::endl;
		return;
	}
	del(pre);
	num--;
}

void LinkTable::show() {
	std::cout << "Num:" << num << "->";
	LNode* start = header.next;
	while (start!=nullptr) {
		std::cout << start->data << " ";
		start = start->next;
	}
	std::cout << std::endl;
}

//带头指针的单向链表接口实现

void LinkList::push(LNode* pre, element_t v) {
	LNode* node = new LNode;
	node->data = v;
	node->next = pre->next;
	pre->next = node;
}

void LinkList::del(LNode* pre) {
	LNode* temp = pre->next;
	pre->next = temp->next;
	delete(temp);
}

LinkList::LinkList()
{
	header = nullptr;
	num = 0;
}

LinkList::~LinkList()
{
	LNode head;
	head.next = header;
	LNode* pre = &head;
	while (pre->next == nullptr) {
		del(pre);
	}
	num = 0;
	header = head.next;
}

void LinkList::push_back(element_t v) {
	LNode head;
	head.next = header;
	LNode* pre = &head;
	while (pre->next != nullptr) {
		pre = pre->next;
	}
	push(pre, v);
	num++;
	header = head.next;
}

void LinkList::push_front(element_t v) {
	LNode head;
	head.next = header;
	LNode* pre = &head;
	push(pre, v);
	num++;
	header = head.next;
}

void LinkList::push_pos(element_t v, int pos) {
	LNode head;
	head.next = header;
	LNode* pre = &head;
	if (pos<0 || pos>num) {
		std::cout << "invalid pos" << std::endl;
		return;
	}
	while (pos) {
		pos--;
		pre = pre->next;
	}
	push(pre, v);
	num++;
	header = head.next;
}

void LinkList::delValue(element_t v) {
	LNode head;
	head.next = header;
	LNode* pre = &head;
	while (pre->next != nullptr) {
		if (pre->next->data == v) {
			break;
		}
		pre = pre->next;
	}
	if (pre->next == nullptr) {
		std::cout << "invalid del" << std::endl;
		return;
	}
	del(pre);
	num--;
	header = head.next;
}

void LinkList::show() {
	std::cout << "Num:" << num << "->";
	LNode* start = header;
	while (start != nullptr) {
		std::cout << start->data << " ";
		start = start->next;
	}
	std::cout << std::endl;
}

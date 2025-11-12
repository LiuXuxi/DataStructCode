#pragma once

typedef int element_t;

typedef struct link_node {
	link_node* next;
	element_t data;
}LNode;

//带头结点的单向链表
class LinkTable {
private:
	LNode header;
	int num;
	void push(LNode* pre, element_t v);
	void del(LNode* pre);
public:
	LinkTable();
	~LinkTable();
	void push_back(element_t v);
	void push_front(element_t v);
	void push_pos(element_t v, int pos);
	void delValue(element_t v);
	void show();
};

//带头指针的单向链表
class LinkList {
private:
	LNode* header;
	int num;
	void push(LNode* pre, element_t v);
	void del(LNode* pre);
public:
	LinkList();
	~LinkList();
	void push_back(element_t v);
	void push_front(element_t v);
	void push_pos(element_t v, int pos);
	void delValue(element_t v);
	void show();
};

#pragma once
#include<iostream>

template<class T>
class RBTree {
private:

private:
	enum Color { RED, BLACK };

	typedef struct node {
		T data;
		node* parent;
		node* left;
		node* right;
		Color color;
	}Node;

	Node* root;
	int cnt;

private:

	// 析构辅助函数：通过后序遍历递归删除节点
	void destroy(Node* node) {
		if (node == nullptr) {
			return;
		}
		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	Node* creatNode(T v) {
		Node* node = new Node;
		node->data = v;
		node->left = node->right = node->parent = nullptr;
		node->color = RED;
		return node;
	}

/* 将x进行左旋，将左、右、父节点进行更新
*      px                              px
 *     /                               /
 *    x                               y
 *   /  \      --(左旋)-->           / \
 *  lx   y                          x  ry
 *     /   \                       /  \
 *    ly   ry                     lx  ly
*/
	void leftRotate(Node* x) {
		Node* y = x->right;
		x->right = y->left;
		if (y->left)y->left->parent = x;
		y->parent = x->parent;
		if (x->parent) {
			if (x->parent->left == x)x->parent->left = y;
			else x->parent->right = y;
		}
		else {
			root = y;
		}
		y->left = x;
		x->parent = y;
	}

/* 将y进行左旋，将左、右、父节点进行更新
*           py                               py
*           /                                /
*          y                                x
*         /  \      --(右旋)-->            /  \
*        x   ry                           lx   y
*       / \                                   / \
*      lx  rx                                rx  ry
* */
	void rightRotate(Node* y) {
		Node* x = y->left;
		y->left = x->right;
		if (x->right)x->right->parent = y;
		x->parent = y->parent;
		if (y->parent) {
			if (y->parent->left == y)y->parent->left = x;
			else y->parent->right = x;
		}
		else root = x;
		x->right = y;
		y->parent = x;
	}

/* 1. 插入节点，如果父节点是黑色，不用调整
 * 2. 如果父节点是红色，就是红红节点，需要调整
 * 2.1 叔叔节点是红色
 *		重新调整颜色（g->红色，p->黑色，u->黑色） g节点作为新节点重新判断
 * 2.2 叔叔节点是黑色
 *		2.2.1 cur左孩子，par是左孩子	LL
 *			g右旋 g->红色，p->黑色
 *		2.2.2 cur右孩子，par是右孩子	RR
 *			g左旋 g->红色，p->黑色
 *		2.2.3 cur右孩子，par是左孩子	LR
 *			p左旋，cur和par交换，重复2.2.1
 *		2.2.4 cur左孩子，par是右孩子
 *			p右旋，cur和par交换，重复2.2.2
 */
	void insertFixUp(Node* node) {
		Node* grandparent = nullptr, * uncle = nullptr;
		Node* parent = node->parent;
		while (parent && parent->color == RED) {
			grandparent = parent->parent;
			if (parent == grandparent->left)uncle = grandparent->right;
			else uncle = grandparent->left;
			if (uncle && uncle->color == RED) {
				parent->color = uncle->color = BLACK;
				grandparent->color = RED;
				node = grandparent;
				parent = node->parent;
				continue;
			}
			if (parent == grandparent->left) {
				if (node == parent->right) {
					leftRotate(parent);
					Node* temp = parent;
					parent = node;
					node = temp;
				}
				rightRotate(grandparent);
				grandparent->color = RED;
				parent->color = BLACK;
			}
			else {
				if (node == parent->left) {
					rightRotate(parent);
					Node* temp = parent;
					parent = node;
					node = temp;
				}
				leftRotate(grandparent);
				grandparent->color = RED;
				parent->color = BLACK;
			}
		}
		root->color = BLACK;
	}

	void print(const Node* node, int key, int dir) {
		if (node) {
			if (dir == 0) {
				printf("%2d[B] is root\n", node->data);
			}
			else {
				printf("%2d[%c] is %2d's %s\n", node->data,
					node->color == RED ? 'R' : 'B', key,
					(dir == 1) ? "right child" : "left child");
			}
			print(node->left, node->data, -1);
			print(node->right, node->data, 1);
		}
	}

	Node* search(int key) {
		Node* node = root;
		while (node) {
			if (key < node->data)node = node->left;
			else if (key > node->data)node = node->right;
			else return node;
		}
		return node;
	}

	void deleteFixUp(Node* x, Node* parent) {
		while (root != x && (!x || x->color == BLACK)) {
			if (x == parent->left) {
				Node* w = parent->right;
				if (w->color == RED) {
					w->color = BLACK;
					parent->color = RED;
					leftRotate(w);
					w = parent->right;
				}
				if ((!w->left || w->left->color == BLACK) &&
					(!w->right || w->right->color == BLACK)) {
					w->color = RED;
					x = parent;
					parent = x->parent;
				}
				else {
					if (!w->right || w->right->color == BLACK) {
						w->left->color = BLACK;
						w->color = RED;
						rightRotate(w);
						w = parent->right;
					}
					w->color = parent->color;
					parent->color = BLACK;
					w->right->color = BLACK;
					leftRotate(parent);
					x = root;
					break;
				}
			}
			else {
				Node* w = parent->left;
				if (w->color == RED) {
					w->color = BLACK;
					parent->color = RED;
					rightRotate(w);
					w = parent->left;
				}
				if ((!w->left || w->left->color == BLACK) &&
					(!w->right || w->right->color == BLACK)) {
					w->color = RED;
					x = parent;
					parent = x->parent;
				}
				else {
					if (!w->left || w->left->color == BLACK) {
						w->color = RED;
						w->right->color = BLACK;
						leftRotate(w);
						w = parent->left;
					}
					w->color = parent->color;
					parent->color = BLACK;
					w->left->color = BLACK;
					rightRotate(parent);
					x = root;
					break;
				}
			}
		}
	}

	void deleteHelper(Node* node) {
		Node* y, *x;
		if (!node->left || !node->right)y = node;
		else {
			y = node->left;
			while (y->right)y = y->right;
		}
		Node* parent = y->parent;
		if (!y->left)x = y->right;
		else x = y->left;
		if (x)x->parent = y->parent;
		if (!y->parent)root = x;
		else if (parent->left == y)parent->left = x;
		else parent->right = x;
		if (node != y)node->data = y->data;
		if (y->color == BLACK)deleteFixUp(x, parent);
		delete(y);
	}
		

public:
	RBTree() {
		root = nullptr;
		cnt = 0;
	}

	~RBTree() {
		destroy(root);
	}

	void insert(T v) {
		Node* node = creatNode(v);
		Node* pre = nullptr, * cur = root;
		while (cur) {
			pre = cur;
			if (v < cur->data)cur = cur->left;
			else if (v > cur->data)cur = cur->right;
			else {
				std::cout << "the v has exited!" << std::endl;
				return;
			}
		}
		node->parent = pre;
		if (pre) {
			if (v < pre->data)pre->left = node;
			else pre->right = node;
		}
		else {
			root = node;
		}
		insertFixUp(node);
	}

	void travel() {
		if (root) {
			print(root, root->data, 0);
		}
		else {
			std::cout << "the tree is blank!" << std::endl;
		}
	}

	void deleteValue(int key) {
		Node* node = search(key);
		if (node == nullptr) {
			std::cout << "the value not exited!" << std::endl;
			return;
		}
		deleteHelper(node);
	}

};
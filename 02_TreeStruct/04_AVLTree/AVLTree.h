#pragma once
#include<iostream>

template<class T>
class AVLTree {
private:
	typedef struct node {
		node* left;
		T data;
		node* right;
		int height;
	}AVLNode;
	AVLNode* root;
	int count;
	AVLNode* creatAVLNode(T v) {
		AVLNode* node = new AVLNode;
		node->data = v;
		node->left = node->right = nullptr;
		node->height = 1;
		return node;
	}
	void visitAVLNode(AVLNode* node) { std::cout << node->data << " "; }

	/* ×óÐý²Ù×÷
 *     px
 *     |
 *     x
 *   /  \
 * lx    y
 *      / \
 *     ly ry
 * */
	AVLNode* leftRotate(AVLNode* x) {
		AVLNode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = std::max(h(x->left), h(x->right)) + 1;
		y->height = std::max(h(y->left), h(y->right)) + 1;
		return y;
	}
	/* ÓÒÐý²Ù×÷
 *       py
 *       |
 *       y
 *     /  \
 *    x   ry
 *   / \
 * lx  rx
 * */
	AVLNode* rightRotate(AVLNode* y) {
		AVLNode* x = y->left;
		y->left = x->right;
		x->right = y;
		y->height = std::max(h(y->left), h(y->right)) + 1;
		x->height = std::max(h(x->left), h(x->right)) + 1;
		return x;
	}

	int h(const AVLNode* node) {
		if (!node) return 0;
		return node->height;
	}

	int getBalance(const AVLNode* node) { return h(node->left) - h(node->right); }
	
	AVLNode* insert(AVLNode* node,T v) {
		if (!node) {
			AVLNode* new_node = creatAVLNode(v);
			++count;
			return new_node;
		}
		if (v > node->data)node->right = insert(node->right, v);
		else if (v < node->data)node->left = insert(node->left, v);
		else return node;
		node->height = std::max(h(node->left), h(node->right)) + 1;
		int balance = getBalance(node);
		if (balance > 1) {
			if (v > node->left->data) node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (balance < -1) {
			if (v < node->right->data)node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
	void inOrder(AVLNode* node) {
		if (!node)return;
		inOrder(node->left);
		visitAVLNode(node);
		inOrder(node->right);
	}
	void free(AVLNode* node) {
		if (!node)return;
		free(node->left);
		free(node->right);
		delete(node);
		--count;
	}
	AVLNode* search(T v) {
		AVLNode* current = root;
		while (current) {
			if (v == current->data)return current;
			else if (v > current->data)current = current->right;
			else current = current->left;
		}
		return nullptr;
	}
	AVLNode* delAVLNode(AVLNode* node,T v) {
		if (!node)return nullptr;
		if (v > node->data)node->right = delAVLNode(node->right, v);
		else if (v < node->data)node->left = delAVLNode(node->left, v);
		else {
			AVLNode* temp;
			if (!node->left || !node->right) {
				temp = node->left ? node->left : node->right;
				if (!temp) {
					--count;
					delete(temp);
					return nullptr;
				}
				node->data = temp->data;
				node->left = temp->left;
				node->right = temp->right;
				delete(temp);
				--count;
			}
			else {
				temp = node->left;
				while (temp->right)temp = temp->right;
				node->data = temp->data;
				node->left=delAVLNode(node->left, temp->data);
			}
		}
		node->height = std::max(h(node->left), h(node->right)) + 1;
		int balance = getBalance(node);
		if (balance > 1) {
			if (getBalance(node->left) < 0)node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		else if (balance < -1) {
			if (getBalance(node->right) > 0)node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
public:
	AVLTree() {
		root = nullptr;
		count = 0;
	}
	~AVLTree() {
		if (root)free(root);
		std::cout << "the tree remains " << count << " node" << std::endl;
	}
	void insertAVLNode(T v){
		root = insert(root, v);
	}
	void inOrderAVLTree() {
		if (root)inOrder(root);
		std::cout << std::endl;
	}
	int getCount() { return count; }

	int getHeight() { return h(root); }

	void deleteAVLNode(T v) {
		if (root)root = delAVLNode(root, v);
	}
};
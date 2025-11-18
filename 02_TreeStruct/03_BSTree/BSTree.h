#pragma once
#include<iostream>
template<class T>
class BSTree {
private:
	typedef struct node {
		struct node* left;
		struct node* right;
		T data;
	}BSNode;
	BSNode* root;
	int cnt;
	void visitBSNode(BSNode* node) {
		if (node)std::cout << node->data << " ";
		else std::cout << "node is nullptr" << std::endl;
	}
	BSNode* creatBSNode(T v) {
		BSNode* node = new BSNode;
		node->data = v;
		node->left = node->right = nullptr;
		return node;
	}
	BSNode* insert(BSNode* node, T v) {
		if (!node) {
			++cnt;
			return creatBSNode(v);
		}
		if (v<node->data)node->left = insert(node->left, v);
		else if (v>node->data)node->right = insert(node->right, v);
		return node;
	}
	void inOrder(BSNode* node) {
		if (!node)return;
		inOrder(node->left);
		visitBSNode(node);
		inOrder(node->right);
	}
	void freeBSNode(BSNode* node) {
		if (!node)return;
		freeBSNode(node->left);
		freeBSNode(node->right);
		delete node;
		--cnt;
	}
	int getHeight(BSNode* node) {
		if (!node)return 0;
		int lcnt = getHeight(node->left);
		int rcnt = getHeight(node->right);
		return (lcnt > rcnt) ? lcnt + 1 : rcnt + 1;
	}
	BSNode* deleteSearch(BSNode* node) {
		if (!node->left)node = node->left;
		return node;
	}
	BSNode* deleteBSNode(BSNode*node,T v) {
		if (!node)return node;
		if (v < node->data)node->left = deleteBSNode(node->left, v);
		else if (v > node->data)node->right = deleteBSNode(node->right, v);
		else {
			BSNode* temp;
			if (!node->left) {
				temp = node->right;
				delete(node);
				--cnt;
				return temp;
			}
			if (!node->right) {
				temp = node->left;
				delete(node);
				--cnt;
				return temp;
			}
			temp = deleteSearch(node->right);
			node->data = temp->data;
			node->right = deleteBSNode(node->right, node->data);
		}
		return node;
	}
public:
	BSTree() {
		root = nullptr;
		cnt = 0;
	}
	BSTree(T v) {
		root = creatBSNode(v);
		cnt = 1;
	}
	~BSTree() {
		if (root) {
			freeBSNode(root);
		}
		std::cout << "the tree has been destroyed, remaining " << cnt << " node" << std::endl;
	}
	//µÝ¹é²åÈë
	void insertBSNode(T v) {
		root = insert(root, v);
	}
	//·ÇµÝ¹é²åÈë
	void insertBSNodeV2(T v) {
		BSNode* pre = nullptr;
		BSNode* cur = root;
		while (cur) {
			pre = cur;
			if (v < cur->data)cur = cur->left;
			else if (v > cur->data)cur = cur->right;
			else return;
		}
		cur = creatBSNode(v);
		if (!pre)root = cur;
		else if (v < pre->data)pre->left = cur;
		else pre->right = cur;
		++cnt;
	}
	void searchBSNode(T v) {
		if (root) {
			BSNode* node = root;
			while (node) {
				if (v == node->data) {
					std::cout << "find v succeed" << std::endl;
					return;
				}
				if (v > node->data)node = node->right;
				else node = node->left;
			}
			std::cout << "find failed" << std::endl;
		}
	}
	void inOrderBSTree() {
		if (root) {
			inOrder(root);
		}
		std::cout << std::endl;
	}
	int getCnt() {
		return cnt;
	}
	int getHightBSTree() {
		if (root)return getHeight(root);
		else return 0;
	}
	//µÝ¹éÉ¾³ý
	void deleteBSTree(T v) {
		root= deleteBSNode(root, v);
	}
	//·ÇµÝ¹éÉ¾³ý
	void deleteBSTreeV2(T v) {
		BSNode* pre = nullptr;
		BSNode* cur = root;
		while (cur && cur->data != v) {
			pre = cur;
			if (v < cur->data)cur = cur->left;
			else cur = cur->right;
		}
		if (!cur)return;
		if (!cur->left || !cur->right) {
			BSNode* temp;
			if (cur->left)temp = cur->left;
			else temp = cur->right;
			if (pre->left == cur)pre->left = temp;
			else pre->right = temp;
			delete(cur);
			--cnt;
		}
		else {
			BSNode* pretemp = cur;
			BSNode* curtemp = cur->left;
			while (curtemp->left) {
				pretemp = curtemp;
				curtemp = curtemp->left;
			}
			cur->data = curtemp->data;
			if (pretemp->left == curtemp)pretemp->left = curtemp->right;
			else pretemp->right = curtemp->right;
			delete(curtemp);
			--cnt;
		}
	}
};
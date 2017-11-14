/**
* David Kelly C00193216
* Date: 24/02/2017
* DSA/Advanced Programming Assignment: Binary Search Tree (BST) implementation.
**/
#include <iostream>
#include <vector>
#include <algorithm>    
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>   
#include <random>

using namespace std;

/* Node Class */
class BSTNode {
public:
	int value;
	BSTNode *left;
	BSTNode *right;

	BSTNode(int value) {
		this->value = value;
		left = NULL;
		right = NULL;
	}

	~BSTNode() {}

	int minValue();
	bool search(int value);
	bool add(int value);
	BSTNode *remove(int value, BSTNode *parent);
};

/* BST Class */
class BinarySearchTree {
private:
	BSTNode *root;
public:
	BinarySearchTree() {
		root = NULL;
	}

	bool search(int value);
	int getRoot();
	bool add(int value);
	BSTNode *remove(int root_val);
	void printTree();
	void printTree(BSTNode*& node);
	void getTree();
	void getTree(BSTNode *& node);
	void postorder();
	void postorder(BSTNode* p, int indent);
	vector<int> toVector();
};
/**
* David Kelly C00193216 
* Date: 24/02/2017
* DSA/Advanced Programming Assignment: Binary Search Tree (BST) implementation.
**/
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>    
#include <string>
#include <stdlib.h>   
#include "BST.h"

using namespace std;

vector<int> treeNodes; 

/* Add Node*/
bool BinarySearchTree::add(int value) {
	if (root == NULL) { // Empty BST
		root = new BSTNode(value);
		return true;
	} 
	else { // Non-empty BST...
		return root->add(value);
	}
}

bool BSTNode::add(int value) {
	if (value <= this->value) { // Duplicates go left
		if (left == NULL) {
			left = new BSTNode(value);
			return true;
		}
		else {
			return left->add(value);
		}
	}
	else if (value > this->value) {
		if (right == NULL) {
			right = new BSTNode(value);
			return true;
		}
		else {
			return right->add(value);
		}
	}
	return false;
}

/* Search Node */
bool BinarySearchTree::search(int value) {
	if (root == NULL)
		return false; //Empty BST
	else
		return root->search(value);
}

bool BSTNode::search(int value) {
	if (value == this->value)
		return true; // Value found
	else if (value < this->value) {
		if (left == NULL)
			return false;
		else
			return left->search(value);
	}
	else if (value > this->value) {
		if (right == NULL)
			return false;
		else
			return right->search(value);
	}
	return false;
}

/* Return Root->Value */
int BinarySearchTree::getRoot() { return root->value;  }

/* Remove Node */
BSTNode * BinarySearchTree::remove(int root_val){
	return root->remove(root_val, root);
}

BSTNode* BSTNode::remove(int value, BSTNode *parent) {
	if (value < this->value) {
		if (left != NULL)
			return left->remove(value, this);
		else
			return NULL;
	}
	else if (value > this->value) {
		if (right != NULL)
			return right->remove(value, this);
		else
			return NULL;
	}
	else {
		if (left != NULL && right != NULL) {
			this->value = right->minValue(); //replace with smallest from right sub tree
			return right->remove(this->value, this); //remove the duplicate from right subtree
		}
		else if (parent->left == this) {
			parent->left = (left != NULL) ? left : right;
			return this;
		}
		else if (parent->right == this) {
			parent->right = (left != NULL) ? left : right;
			return this;
		}
	}
}

/* Return minimum value */
int BSTNode::minValue() {
	if (left == NULL)
		return value;
	else
		return left->minValue();
}

/* InOrder Traversal */
void BinarySearchTree::printTree() {
	return printTree(root);
	cout << endl;
}
/* InOrder Traversal - node values print to screen */
void BinarySearchTree::printTree(BSTNode*& node) {
	if (root == NULL) {
		return;
	}
	if (node->left != NULL) {
		printTree(node->left);
	}
	if (node != NULL) {
		cout << node->value << " ";
	}
	if (node->right != NULL) {
		printTree(node->right);
	}
}

/* Returns a vector containing all nodes in inorder traversal */
vector<int> BinarySearchTree::toVector() {
	return treeNodes;
}
/*Inorder traversal*/
void BinarySearchTree::getTree() {
	return getTree(root);
}
/*Inorder traversal, node values pushed to vector*/
void BinarySearchTree::getTree(BSTNode*& node) {
	if (root == NULL) {
		return;
	}
	if (node->left != NULL) {
		getTree(node->left);
	}
	if (node != NULL) {
		treeNodes.push_back(node->value); // Push node to vector
	}
	if (node->right != NULL) {
		getTree(node->right);
	}
}

/*Tree visualisation:
	Postorder traversal build tree from bottom up
	The root is displayed far left, right children above, left children below
	eg: 
	      33
	     /
	   30
	  /  \
	20    25
	  \
	   10
	     \
		  8

	(FYI: 20 is root)
	*/
void BinarySearchTree::postorder() {
	return postorder(this->root, 0);
}

void BinarySearchTree::postorder(BSTNode* p, int indent){
	if (p != NULL) {
		if (p->right) {
			postorder(p->right, indent + 4);
		}
		if (indent > 0) {
			cout << std::setw(indent) << ' ';
		}
		if (p->right) {
			cout << " /\n" << std::setw(indent) << ' ';
		}
		cout << p->value << "\n ";
		if (p->left) {
			cout << std::setw(indent) << ' ' << " \\\n";
			postorder(p->left, indent + 4);
		}
	}
}
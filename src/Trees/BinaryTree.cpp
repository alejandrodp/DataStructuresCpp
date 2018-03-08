#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(){
	this->root = nullptr;
}

bool BinaryTree::insertElm(int element){
	struct Node* adding = new struct Node;
	adding->value = element;
	adding->right = nullptr;
	adding->left = nullptr;
	return this->insertElm(adding);
}

bool BinaryTree::insertElm(struct Node* adding){

	struct Node* child = root;

	if (root == nullptr) {

	root = adding;
	return true;

	}

	while(true){
		if (adding->value > child->value) {
			if(child->right == nullptr){
				child->right = adding;
				adding->father = child;
				break;
			}else{
				child = child->right;
			}
		}else if (adding->value < child->value) {
			if(child->left == nullptr){
				child->left = adding;
				adding->father = child;
				break;
			}else{
				child = child->left;
			}
		}else{
			return false;
		}
	}
	return true;
}


bool BinaryTree::deleteElm (int element) {
	
	if (this->root == nullptr) return false;

	if (element == this->root->value) {
		this->deleteRoot(); 
		return true;
	}

	return this->deleteElm(root, element);
}


bool BinaryTree::deleteElm(struct Node* start, int element) {
	struct Node* child = start;
	while(true){
		if (element > child->value) {
			if(child->right == nullptr){
				return false;
			}else{
				child = child->right;
			}
		}else if (element < child->value) {
			if(child->left == nullptr){
				return false;
			}else{
				child = child->left;
			}
		}else{
			selectToDel(child);
			return true;
		}
	}	
}


void BinaryTree::deleteRoot() {

	struct Node* sustitute = root->right;

	while (sustitute->left != nullptr) {

		sustitute = sustitute->left;
	}

	this->root->value = sustitute->value;

	this->selectToDel(sustitute);

}


void BinaryTree::selectToDel(struct Node* node){

	bool nodeToDelIsRight = node->father->right->value == node->value;

	if(node->right == nullptr and node->left == nullptr){
		this->delLeaf(node, nodeToDelIsRight);
	}else if (node->right != nullptr and node->left != nullptr){
		this->delWithTwoChild(node, nodeToDelIsRight);
	}else{
		this->delWithOneChild(node, nodeToDelIsRight);
	}
}

void BinaryTree::delLeaf(struct Node* node, bool nodeToDelIsRight){

	if (nodeToDelIsRight) {

		node->father->right = nullptr;

	} else {

		node->father->left = nullptr;		

	}
	delete node;
}

void BinaryTree::delWithOneChild(struct Node* node, bool nodeToDelIsRight){
	if (nodeToDelIsRight and node->right != nullptr) {

		node->father->right = node->right;

	} else if (nodeToDelIsRight and node->left != nullptr) {

		node->father->right = node->left;

	} else if (node->right != nullptr) {


		node->father->left = node->right;
	
	} else {

		node->father->left = node->left;

	}

	delete node;
}

void BinaryTree::delWithTwoChild(struct Node* node, bool nodeToDelIsRight){
	
	struct Node* sustitute = node->right;

	while (sustitute->left != nullptr) {

		sustitute = sustitute->left;

	}

	node->value = sustitute->value;

	this->selectToDel(sustitute);
}

void BinaryTree::printInOrder () {

	if (this->root != nullptr) {

		this->printInOrder(root);
	}

}

void BinaryTree::printInOrder(struct Node *node) {

	if (node == nullptr) return;

	this->printInOrder(node->left);
	
	cout << node->value << endl;

	this->printInOrder(node->right);

}
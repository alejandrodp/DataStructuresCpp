#include "Trees/BinaryTree.h"
#include <iostream>

using namespace std;
int main(){

	BinaryTree tree;

	tree.insertElm(45);
	tree.insertElm(5);
	tree.insertElm(4);
	tree.insertElm(12);
	tree.insertElm(98);

	tree.deleteElm(45);

	tree.printInOrder();

}
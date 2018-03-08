#ifndef BIN_TREE_H
#define BIN_TREE_H


class BinaryTree {
private:

	struct Node{
		int value;
		struct Node* left;
		struct Node* right;
		struct Node* father;
	} *root;

	bool deleteElm(struct Node* start, int element);
	void selectToDel(struct Node* node);
	void delLeaf(struct Node* node, bool nodeToDelIsRight);
	void delWithOneChild(struct Node* node, bool nodeToDelIsRight);
	void delWithTwoChild(struct Node* node, bool nodeToDelIsRight);
	bool insertElm(struct Node* adding);
	void printInOrder(struct Node* node);
	void deleteRoot();

public:

	BinaryTree();
    bool insertElm(int element);
    bool deleteElm(int element);
    void printInOrder();

};

#endif
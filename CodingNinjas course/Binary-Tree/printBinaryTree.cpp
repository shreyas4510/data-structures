#include <iostream>
using namespace std;

class BinaryTreeNode {
	public :
		int data;
		BinaryTreeNode *leftNode;
		BinaryTreeNode *rightNode;

		BinaryTreeNode(int data) {
			this -> data = data;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}
};

printBinaryTree( BinaryTreeNode *root ) {
	if (!root) 
		return 0;

	cout << root -> data << endl;
	printBinaryTree(root -> leftNode);
	printBinaryTree(root -> rightNode);	
}

int main() {
	BinaryTreeNode *root = new BinaryTreeNode(1);

	BinaryTreeNode *leftNode = new BinaryTreeNode(2);
	BinaryTreeNode *rightNode = new BinaryTreeNode(3);
	
	BinaryTreeNode *leftChild1 = new BinaryTreeNode(4);
	BinaryTreeNode *leftChild2 = new BinaryTreeNode(5);
	
	BinaryTreeNode *rightChild1 = new BinaryTreeNode(6);
	BinaryTreeNode *rightChild2 = new BinaryTreeNode(7);

	leftNode -> leftNode = leftChild1;
	leftNode -> rightNode = leftChild2;

	rightNode -> leftNode = rightChild1;
	rightNode -> rightNode = rightChild2;

	root -> leftNode = leftNode;
	root -> rightNode = rightNode;

	printBinaryTree(root);
}
#include <iostream>
using namespace std;

class BinaryTreeNode {
	public :
		int data;
		BinaryTreeNode *leftNode;
		BinaryTreeNode *rightNode;

		BinaryTreeNode( int data ) {
			this -> data = data;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~BinaryTreeNode() {
			delete leftNode;
			delete rightNode;
		}
};

int main() {

	BinaryTreeNode *root = new BinaryTreeNode(1);
	BinaryTreeNode *leftNode = new BinaryTreeNode(2);
	BinaryTreeNode *rightNode = new BinaryTreeNode(3);
	
	root -> leftNode = leftNode;
	root -> rightNode = rightNode;

	delete root;
}
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
};

BinaryTreeNode* takeInput() {
	int input;
	cin >> input;
	
	if (input == -1)
		return NULL;

	BinaryTreeNode *root = new BinaryTreeNode(input);

	BinaryTreeNode *leftNode = takeInput();
	BinaryTreeNode *rightNode = takeInput();

	root -> leftNode = leftNode;
	root -> rightNode = rightNode;

	return root;
}

printBinaryTree( BinaryTreeNode *root ) {

	if (!root) 
		return 0;

	cout << root -> data << " : ";
	
	if( root -> leftNode ) 
		cout << " LN : " << root -> leftNode -> data << "  ";

	if( root -> rightNode ) 
		cout << " RN : "<< root -> rightNode -> data << "  ";
	cout << endl;
	
	printBinaryTree( root -> leftNode );
	printBinaryTree( root -> rightNode );
}

int main()
{
	BinaryTreeNode *root = takeInput();
	printBinaryTree( root );
	return 0;
}
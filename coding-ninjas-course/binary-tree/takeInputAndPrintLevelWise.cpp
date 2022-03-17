#include <iostream>
#include <queue>
using namespace std;

class binaryTreeNode {
	public :
		int data;
		binaryTreeNode* leftNode;
		binaryTreeNode* rightNode;

		binaryTreeNode( int data ) {
			this -> data = data; 
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~binaryTreeNode() {
			delete leftNode;
			delete rightNode;
		}
};

binaryTreeNode* takeInput() {
	int input;
	cin >> input;
	if (input == -1)
		return NULL;

	binaryTreeNode* root = new binaryTreeNode(input);
	queue<binaryTreeNode*> q;
	q.push(root);

	while ( !q.empty() ) {
		binaryTreeNode* front = q.front();
		q.pop();

		int leftData, rightData;
		cin >> leftData >> rightData;

		if (leftData != -1){
			binaryTreeNode* leftNode = new binaryTreeNode(leftData);
			q.push(leftNode);
			front -> leftNode = leftNode;
		}

		if (rightData != -1) {
			binaryTreeNode* rightNode = new binaryTreeNode(rightData);
			front -> rightNode = rightNode;
			q.push(rightNode);
		}
	}
	return root;
}

printBinaryTree( binaryTreeNode *root ) {

	queue<binaryTreeNode*> q;
	q.push(root);

	while( !q.empty() ) {

		binaryTreeNode* front = q.front();
		q.pop();
	
		cout << front -> data << " : ";
		if( front -> leftNode ) {
			cout << " LN : " << front -> leftNode -> data << "  ";
			q.push( front -> leftNode );
		}

		if( front -> rightNode ) {
			cout << " RN : "<< front -> rightNode -> data << "  ";
			q.push( front -> rightNode );
		}
		cout << endl;

	}
}

int main() {
	printBinaryTree( takeInput() );
}
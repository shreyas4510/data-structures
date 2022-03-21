#include <iostream>
#include <vector>
using namespace std;

class Node {
	public :
		int data;
		Node *leftNode;
		Node *rightNode;

		Node(int data) {
			this -> data = data;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~Node() {
			delete this -> leftNode;
			delete this -> rightNode;
		}
};

Node* constructTree( vector<int> sortedArr, int start, int end ) {
	if ( start > end )
		return NULL;

	int mid = (start + end) / 2;
	Node *root = new Node(sortedArr.at(mid));
	if (start == end)
		return root;

	Node *leftNode = constructTree( sortedArr, start, mid - 1 );
	Node *rightNode = constructTree( sortedArr, mid + 1, end );

	root -> leftNode = leftNode;
	root -> rightNode = rightNode;

	return root;
}

void printTree( Node* root ) {

	if (!root)
		return;

	cout << root -> data << " ";
	printTree( root -> leftNode );
	printTree( root -> rightNode );
}

int main() {
	int size;
	cin >> size;
	vector<int> sortedArr;
	for (int i = 0; i < size; ++i) {
		int input;
		cin >> input;
		sortedArr.push_back(input);
	}

	Node *root = constructTree( sortedArr, 0, size-1 );
	printTree( root );
	cout << endl;
	delete root;
	return 0;
}
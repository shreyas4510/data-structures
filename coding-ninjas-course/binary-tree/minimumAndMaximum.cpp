#include <iostream>
#include <climits>
#include "binaryTree.h"
using namespace std;

class Store {
	public :
		int maximum = INT_MIN;
		int minimum = INT_MAX;

		Store( int max = INT_MIN, int min = INT_MAX) {
			this -> maximum = max;
			this -> minimum = min;
		}

};

Store findMaxAndMin( binaryTreeNode<int>* root ) {
	if (!root) {
		Store s;
		return s;
	}

	Store finalMaxMin(root -> data, root -> data);
	Store leftMaxMin = findMaxAndMin(root -> leftNode);
	Store RightMaxMin = findMaxAndMin(root -> rightNode);	
	
	if ( leftMaxMin.maximum > finalMaxMin.maximum )
		finalMaxMin.maximum = leftMaxMin.maximum;

	if ( RightMaxMin.maximum > finalMaxMin.maximum )
		finalMaxMin.maximum = RightMaxMin.maximum;

	if ( leftMaxMin.minimum < finalMaxMin.minimum )
		finalMaxMin.minimum = leftMaxMin.minimum;

	if ( RightMaxMin.minimum < finalMaxMin.minimum )
		finalMaxMin.minimum = RightMaxMin.minimum;

	return finalMaxMin;
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();

	Store maxMin = findMaxAndMin(root);
	cout << maxMin.minimum << "  " << maxMin.maximum << endl;
	return 0;
}
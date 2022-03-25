#include <iostream>
#include <vector>
#include "binaryTree.h"
#include <bits/stdc++.h>
using namespace std;

// Approach 1
// void printPairSum( binaryTreeNode<int> *root, int target, vector<int> *temp ) {
// 	if (!root)
// 		return;

// 	bool flag = false;
// 	for (int i = 0; i<( *temp ).size(); i++) {
// 		if (( *temp )[i] == INT_MIN)
// 			continue;

// 		if (( *temp )[i] == target - (root -> data)) {
// 			cout << target - (root -> data) << "  " << root -> data << endl;
// 			( *temp )[i] = INT_MIN;
// 			flag = true;
// 			break;
// 		}
// 	}

// 	if (!flag)
// 		( *temp ).push_back( root -> data );

// 	printPairSum( root -> leftNode, target, temp );
// 	printPairSum( root -> rightNode, target, temp );
// }

// int main() {
// 	operations<int> op;
// 	binaryTreeNode<int> *root = op.takeInput();
// 	vector<int> *temp = new vector<int>();
// 	int target;
// 	cin >> target;
// 	printPairSum( root, target, temp );
// 	return 0;
// }

// -----------------------------------------------------------------------------------------------------

void converToVector( binaryTreeNode<int> *root, vector<int> *nums ) {
	if (!root)
		return;

	(*nums).push_back( root -> data );
	converToVector(root -> leftNode, nums);
	converToVector(root -> rightNode, nums);
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	vector<int> *nums = new vector<int>();
	converToVector(root, nums);
	sort( (*nums).begin(), (*nums).end() );
	

	int target;
	cin >> target;
	int i=0, j=(*nums).size() - 1;
	while( i < j ) {
		if( ((*nums).at( i ) + (*nums).at( j )) > target )
			j--;
		else if( ((*nums).at( i ) + (*nums).at( j )) < target )
			i++;
		else {
			cout << (*nums).at( i ) << " " << (*nums).at( j ) << endl;
			i++;
			j--;
		}
	}

	delete nums;
	return 0;
}
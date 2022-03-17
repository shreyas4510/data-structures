#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "binarySearchTree.h"
using namespace std;

printElementsBetweenPoints( TreeNode<int> *root, int p1, int p2, vector<int> *v ) {
	if (!root)
		return 0;

	if( root -> data >= p1 && root -> data <= p2 )
		(*v).push_back(root -> data);

	if ( root -> leftNode && root -> data > p1 )
		printElementsBetweenPoints( root -> leftNode, p1, p2, v );

	if ( root -> rightNode && root -> data < p2 )
		printElementsBetweenPoints( root -> rightNode, p1, p2, v );
}

int main() {
	operations<int> op;
	TreeNode<int> *root = op.takeInput();
	int k1, k2;
	cin >> k1 >> k2;
	vector<int> v;
	printElementsBetweenPoints( root, k1, k2, &v );
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << " ";
	delete root;
	return 0;
}
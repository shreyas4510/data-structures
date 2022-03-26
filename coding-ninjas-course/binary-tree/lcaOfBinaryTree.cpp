#include <iostream>
#include "binaryTree.h"
#include <vector>
using namespace std;

void findLca( binaryTreeNode<int> *root, int node, vector<int> *path ) {
	if (!root)
		return;
	
	if (root -> data == node) {
		path -> push_back( root -> data );
		return;
	}

	if ( path -> empty() )
		findLca( root -> leftNode, node, path );

	if ( path -> empty() )
		findLca( root -> rightNode, node, path );

	if (!path -> empty())
		path -> push_back(root -> data);
}

int main() {
	operations<int> op;
	binaryTreeNode<int> *root = op.takeInput();
	int node1, node2;
	cin >> node1 >> node2;  

	vector<int> *node1Path = new vector<int>();
	findLca( root, node1, node1Path );

	vector<int> *node2Path = new vector<int>();
	findLca( root, node2, node2Path );

	int i = node1Path -> size() > node2Path -> size() ? node1Path -> size() - node2Path -> size() : 0, 
	j=node1Path -> size() < node2Path -> size() ? node2Path -> size() - node1Path -> size(): 0;
	bool flag = false;

	while( (i < node1Path -> size()) && (j < node2Path -> size()) ) {
		if ( node1Path -> at(i) == node2Path -> at(j) ) {
			cout << node1Path -> at(i) << endl;
			flag = true;
			break;
		}
		i++;
		j++;
	}	
	if( !flag )
		cout << -1 << endl;
}
#include <iostream>
#include <queue>
#include "treeNode.h"
using namespace std;

treeNode<int>* takeInput() {
	int input;
	cin >> input;
	treeNode<int> *root = new treeNode<int>(input);

	queue<treeNode<int>*> q;
	q.push(root);

	while( !q.empty() ) {
		int childCount;
		cin >> childCount;

		treeNode<int> *front = q.front();
		q.pop();

		for (int i = 0; i < childCount; ++i) {
			int childData;
			cin >> childData;
			treeNode<int> *child = new treeNode<int>(childData);			
			front -> childrens.push_back(child);
			q.push(child);
		}
	}
	return root;
}

void depthOfNode( treeNode<int> *root, int height ) {
	if (root == NULL)
		return;

	if (height == 0) {
		cout << root -> data << " ";
		return;
	}

	for( int i=0; i<root -> childrens.size(); i++ ) {
		depthOfNode( root -> childrens.at(i), height-1 );
	}
}

int main() {
	depthOfNode(takeInput(), 2);
	return 0;
}
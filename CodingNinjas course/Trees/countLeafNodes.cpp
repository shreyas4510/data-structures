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

int countLeafNodes( treeNode<int> *root ) {
	if( root -> childrens.size() == 0 ) {
		return 1;
	}

	int count = 0;
	for( int i=0; i<root -> childrens.size(); i++ ) {
		count += countLeafNodes(root -> childrens[i]);
	}
	return count;
}

int main() {
	cout << countLeafNodes( takeInput() );
}
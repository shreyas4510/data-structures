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

replaceWithDepth( treeNode<int> *root, int count ) {
	root -> data = count;
	for (int i = 0; i < root -> childrens.size(); i++) {
		replaceWithDepth(root -> childrens.at(i), count+1);
	}
}

void printTree( treeNode<int> *root ) {
	queue<treeNode<int>*> q;
	q.push(root);

	while ( !q.empty() ) {
		treeNode<int> *front = q.front();
		q.pop();

		cout << front -> data << " ";
		for( int i=0; i<front -> childrens.size(); i++ ) {
			q.push(front -> childrens.at(i));
		}
	}
}

int main() {
	treeNode<int> *root = takeInput();
	replaceWithDepth(root, 0);
	printTree(root);
}
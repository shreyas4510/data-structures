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

void preOrder( treeNode<int> *root ) {
	if (root == NULL)
		return;
	cout << root -> data << " ";
	for (int i = 0; i < root -> childrens.size(); ++i) {
		preOrder(root -> childrens.at(i));
	}
}

deleteTree( treeNode<int> *root ){
	for (int i = 0; i < root -> childrens.size(); ++i) {
		deleteTree( root -> childrens.at(i) );
	}
	cout << root -> data << " deleted" << endl;
	delete root;
}

int main() {
	treeNode<int> *root = takeInput();
	preOrder( root );
	cout << endl;
	// deleteTree(root);
	delete root;
}
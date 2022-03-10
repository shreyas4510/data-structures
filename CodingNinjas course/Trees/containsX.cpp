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

bool checkIfPresent( treeNode<int> *root, int target ) {
	if ( root -> data == target ) {
		return true;
	}

	bool flag = false;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		flag = checkIfPresent(root -> childrens.at(i), target);
	}
	return flag;
}

int main() {
	treeNode<int> *root = takeInput();
	int target;
	cin >> target;
	cout << ( checkIfPresent( root, target ) ? "true" : "false" );
	delete root;
	return 0;
}
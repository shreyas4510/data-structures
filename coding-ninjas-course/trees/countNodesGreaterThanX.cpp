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

int countNodesGreaterThanX( treeNode<int> *root, int target ) {
	int count = 0;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		count += countNodesGreaterThanX( root -> childrens.at(i), target );
	}
	if (root -> data > target)
		count++;
	return count;
}

int main() {
	treeNode<int> *root = takeInput();
	int target;
	cin >> target;
	cout << countNodesGreaterThanX(root, target);
}
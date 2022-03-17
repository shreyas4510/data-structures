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

void printTree( treeNode<int> *root ) {
	queue<treeNode<int>*> q;
	q.push(root);

	while ( !q.empty() ) {
		treeNode<int> *front = q.front();
		q.pop();

		cout << front -> data << " : ";
		for( int i=0; i<front -> childrens.size(); i++ ) {
			cout << front -> childrens.at(i) -> data << ", ";
			q.push(front -> childrens.at(i));
		}
		cout << endl;
	}
}

int heightOfTree( treeNode<int> *root, int height ) {
	int tempHeight = height;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		int m1 = heightOfTree(root -> childrens.at(i), height+1);
		if (tempHeight < m1) {
			tempHeight = m1;
		}
	}
	return tempHeight;
}

int main() {
	treeNode<int> *root = takeInput();
	printTree(root);
	cout << heightOfTree(root, 1);
	return 0;
}
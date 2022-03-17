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

bool checkTreesIdentical( treeNode<int> *root1, treeNode<int> *root2 ) {
	if ( root1 -> data != root2 -> data )
		return false;

	if ( root1 -> childrens.size() != root2 -> childrens.size() ) 
		return false;

	bool flag = true;
	for (int i = 0; i < root1 -> childrens.size(); ++i) {
		flag = checkTreesIdentical(root1 -> childrens.at(i), root2 -> childrens.at(i));
		if (!flag)
			break;
	}

	return flag;
}

int main(int argc, char const *argv[]) {

	treeNode<int> *root1 = takeInput();
	treeNode<int> *root2 = takeInput();
	cout << ( checkTreesIdentical(root1, root2) ? "true" : "false" );
	return 0;
}
#include <iostream>
#include <queue>
#include "treeNode.h"
#include <climits>
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

int getNextLargest( treeNode<int> *root, int target ) {
	int nextLargest = root -> data;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		int tempMax = getNextLargest( root -> childrens.at(i), target );
		if ( tempMax > target ) {
			if ( nextLargest > target && tempMax < nextLargest )
				nextLargest = tempMax;
			else if ( nextLargest < target )
				nextLargest = tempMax;
		}
	}
	return nextLargest;
}

int main(int argc, char const *argv[] ){
	int target;
	cin >> target;
	cout << getNextLargest( takeInput(), target );
	return 0;
}
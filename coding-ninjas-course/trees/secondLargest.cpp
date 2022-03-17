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

class elements {
	public :
		int largest = INT_MIN;
		int secondLargest = INT_MIN;
};

elements findSecondLargest( treeNode<int> *root ) {
	elements eobj;
	eobj.largest = root -> data;
	for (int i = 0; i < root -> childrens.size(); i++) {
		elements obj = findSecondLargest( root -> childrens.at(i) );
		
		if ( obj.largest > eobj.largest ) {
			int temp = eobj.largest;
			eobj.largest = obj.largest;
			if ( temp > obj.secondLargest )
				eobj.secondLargest = temp;
			else
				eobj.secondLargest = obj.secondLargest;
		}
		else if ( obj.largest < eobj.largest && obj.largest > eobj.secondLargest  ) {
			eobj.secondLargest = obj.largest;
		}
		else if ( obj.largest == eobj.largest && obj.secondLargest > eobj.secondLargest ) {
			eobj.secondLargest = obj.secondLargest;
		}
	}
	return eobj;
}

int main() {
	cout << findSecondLargest(takeInput()).secondLargest;
}
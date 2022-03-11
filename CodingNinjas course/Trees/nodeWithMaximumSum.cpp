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

class MaxSumPair {
	public :
		int sum = 0;
		int nodeData = 0;
};

MaxSumPair nodeWithMaximumSum( treeNode<int>* root ) {
	if (root == NULL) {
		MaxSumPair nullObj;
		nullObj.nodeData = -1;
		nullObj.sum = -1;
		return nullObj;
	}

	int sum = root -> data;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		sum += root -> childrens.at(i) -> data;
	}

	MaxSumPair obj;
	obj.nodeData = root -> data;
	obj.sum = sum;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		MaxSumPair tempObj;
		tempObj = nodeWithMaximumSum( root -> childrens.at(i) );
		if ( tempObj.sum > obj.sum )
			obj = tempObj;
	}
	return obj;
}

int main() {
	treeNode<int> *root = takeInput();
	MaxSumPair obj = nodeWithMaximumSum(root);
	cout << obj.nodeData; 
	delete root;
}
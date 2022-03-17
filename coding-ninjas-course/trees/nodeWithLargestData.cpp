#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode {
	public :
		int data;
		vector<TreeNode*> childrens;

		TreeNode( int data ) {
			this -> data = data;
		}
};

TreeNode* takeInput() {
	int rootData;
	cin >> rootData;
	TreeNode* root = new TreeNode(rootData);

	queue<TreeNode*> q;
	q.push(root);

	while( !q.empty() ) {
		TreeNode* front = q.front();
		q.pop();

		int childCount;
		cin >> childCount;
		for (int i = 0; i < childCount; ++i) {
			int childData;
			cin >> childData;
			TreeNode *child = new TreeNode(childData);

			front -> childrens.push_back(child);
			q.push(child);
		}
	}
	return root;
}

printTree( TreeNode* root ) {
	queue<TreeNode*> q;
	q.push(root);

	while( !q.empty() ) {
		TreeNode* front = q.front();
		q.pop();

		cout << front -> data << " : ";
		for (int i = 0; i < front -> childrens.size(); ++i) {
			cout << front -> childrens.at(i) -> data << ", ";
			q.push(front -> childrens.at(i));
		}
		cout << endl;
	}
}

int maximumNode( TreeNode* root ) {
	int max = root -> data;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		int temp = maximumNode(root -> childrens.at(i));
		if ( temp > max ) {
			max = temp;
		}
	}
	return max;
}

int main() {
	// printTree(takeInput());
	cout << maximumNode(takeInput());
}
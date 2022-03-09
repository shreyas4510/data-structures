#include <iostream>
#include <vector>
#include <queue>
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
	int input;
	cin >> input;
	TreeNode* root = new TreeNode(input);

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
			TreeNode* node = new TreeNode(childData);
			q.push(node);
			front -> childrens.push_back(node);
		}
	}
	return root;
}

printTree( TreeNode *root ) {
	queue<TreeNode*> q;
	q.push( root );

	while(!q.empty()) {
		TreeNode *front = q.front();
		q.pop();
		cout << front -> data << " : ";
		for (int i = 0; i < front -> childrens.size(); ++i) {
			q.push(front -> childrens.at(i));
			cout << front -> childrens.at(i) -> data << ", ";
		}
		cout << endl;
	}
}

int sumOfAllNodes( TreeNode* root ) {
	int data = root -> data;
	for (int i = 0; i < root -> childrens.size(); ++i) {
		data += sumOfAllNodes(root -> childrens.at(i));
	}
	return data;
}

int main() {
	// printTree( takeInput() );
	cout << sumOfAllNodes(takeInput());
}
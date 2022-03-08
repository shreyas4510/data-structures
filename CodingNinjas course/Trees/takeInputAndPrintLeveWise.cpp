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
	cout << "Enter root data : ";
	int data;
	cin >> data;
	TreeNode *root = new TreeNode(data);

	queue<TreeNode*> q;
	q.push(root);

	while( !q.empty() ) {

		TreeNode *front = q.front();
		q.pop();

		int childCount;
		cout << "Enter the number of childrens for " << front -> data << " : "; 
		cin >> childCount;

		for (int i = 1; i <= childCount; i++) {
			int childData;
			cout << "Enter data for " << i << "th child of " << front -> data << " : ";
			cin >> childData;

			TreeNode *child = new TreeNode(childData);
			front -> childrens.push_back(child);
			q.push(child);
		}
	}
	return root;
}

printTree(TreeNode *root) {
	queue<TreeNode*> q;
	q.push(root);
	
	while( !q.empty() ) {
		TreeNode* front = q.front();
		q.pop();

		cout << front -> data << " : ";
		for (int i = 0; i < front -> childrens.size(); i++) {
			cout << front -> childrens[i] -> data << ", ";
			q.push(front -> childrens[i]);
		}
		cout << endl;
	}
}

int main() {
	printTree(takeInput());
	return 0;
}
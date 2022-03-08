#include <iostream>
#include <vector>
using namespace std;

// template < typename type >
class TreeNode {
	public:
		int data;
		vector<TreeNode*> childrens;

		TreeNode( int data ) {
			this -> data = data;
		}
};

TreeNode* takeInput() {
	int input;
	cout << "Enter Data : ";
	cin >> input;

	TreeNode *node = new TreeNode(input);
	cout << "Enter the number of childrens for " << node -> data << " : ";
	int childrens;
	cin >> childrens;

	for (int i = 0; i < childrens; ++i) {
		TreeNode *child = takeInput();
		node -> childrens.push_back(child);
	}

	return node;
}

printTree(TreeNode *root) {
	cout << root -> data << " : ";
	for (int i = 0; i < root -> childrens.size(); ++i) {
		cout << root -> childrens[i] -> data << ", ";
	}
	cout << endl;

	for (int i = 0; i < root -> childrens.size(); ++i) {
		printTree(root -> childrens[i]);
	}
}

int main() {
	TreeNode *root = takeInput();
	printTree( root );
}
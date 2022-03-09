#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
	public:
		int data;
		vector<TreeNode*> childrens;

		TreeNode(int data) {
			this -> data = data;
		}
};

TreeNode* takeInput() {
	int input, childCount;
	cout << "Enter root value : ";
	cin >> input;
	TreeNode *root = new TreeNode(input);
	cout << "Enter child count : ";
	cin >> childCount;
	for (int i = 0; i < childCount; i++) {
		TreeNode *node = takeInput();
		root -> childrens.push_back(node);
	}
	return root;
}

void printTree( TreeNode *root ) {
	cout << root -> data << " : ";
	for (int i = 0; i < root -> childrens.size(); i++) {
		cout << root -> childrens.at(i) -> data << ", ";
	}
	cout << endl;
	for (int i = 0; i < root -> childrens.size(); i++) {
		printTree( root -> childrens.at(i) );
	}
}

int countNodes( TreeNode *root ) {
	int ans = 1;
	for (int i = 0; i < root -> childrens.size(); i++) {
		ans += countNodes(root -> childrens.at(i));
	}
	return ans;
}

int main() {
	// printTree(takeInput());
	cout << countNodes(takeInput());
}
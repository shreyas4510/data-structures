#include<iostream>
using namespace std;

template <typename type>
class TreeNode {
	public :
		type data;
		vector<TreeNode*> childrens;

		TreeNode( type data ) {
			this -> data = data;
		}
};

int main() {
	
	TreeNode<int> *root = new TreeNode<int>(5);
	TreeNode<int> *child1 = new TreeNode<int>(6);
	TreeNode<int> *child2 = new TreeNode<int>(7);

	root -> childrens.push_back( child1 );
	root -> childrens.push_back( child2 );

}
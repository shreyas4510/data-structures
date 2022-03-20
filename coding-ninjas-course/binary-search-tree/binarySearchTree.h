#include <iostream>
#include <queue>
using namespace std;

template< typename type >
class TreeNode {
	public :
		type data;
		TreeNode *leftNode;
		TreeNode *rightNode;

		TreeNode( type data ) {
			this -> data = data;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~TreeNode() {
			delete this -> leftNode;
			delete this -> rightNode;
		}
};

template < typename type >
class operations {
	public:
		TreeNode<type>* takeInput() {
			type input;
			queue<TreeNode<type>*> q;
			cin >> input;
			if (input == -1)
				return NULL;

			TreeNode<type> *root = new TreeNode<type>(input); 
			q.push( root );

			while( !q.empty() ) {
				TreeNode<type> *front = q.front();
				q.pop();

				type leftData, rightData;
				cin >> leftData >> rightData;

				if ( leftData != -1 ) {
					front -> leftNode = new TreeNode<type>(leftData);
					q.push(front -> leftNode);
				}

				if ( rightData != -1 ) {
					front -> rightNode = new TreeNode<type>(rightData);
					q.push(front -> rightNode);
				}
			}
			return root;
		}

		void printLevelWise( TreeNode<type> *root ) {
			queue<TreeNode<type>*> q;
			q.push(root);

			while( !q.empty() ) {
				TreeNode<type> *front = q.front();
				q.pop();

				cout << front -> data << " ";
				if (front -> leftNode) {
					q.push(front -> leftNode);
				}

				if (front -> rightNode) {
					q.push(front -> rightNode);
				}
			}
			cout << endl;
		} 
};
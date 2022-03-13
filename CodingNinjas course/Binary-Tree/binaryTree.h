#include <iostream>
#include <queue>
using namespace	std;

template <typename type>
class binaryTreeNode {
	public :
		type data;
		binaryTreeNode* leftNode;
		binaryTreeNode* rightNode;

		binaryTreeNode( type data ) {
			this -> data = data;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~binaryTreeNode() {
			delete leftNode;
			delete rightNode;
		}
};

template <typename type>
class operations {
	public :
		binaryTreeNode<type>* takeInput() {
			type input;
			cin >> input;
			if (input == -1)
				return NULL;

			binaryTreeNode<type>* root = new binaryTreeNode<type>(input);
			queue<binaryTreeNode<type>*> q;
			q.push(root);

			while ( !q.empty() ) {
				binaryTreeNode<type>* front = q.front();
				q.pop();

				type leftData, rightData;
				cin >> leftData >> rightData;

				if (leftData != -1){
					binaryTreeNode<type>* leftNode = new binaryTreeNode<type>(leftData);
					q.push(leftNode);
					front -> leftNode = leftNode;
				}

				if (rightData != -1) {
					binaryTreeNode<type>* rightNode = new binaryTreeNode<type>(rightData);
					front -> rightNode = rightNode;
					q.push(rightNode);
				}
			}
			return root;
		}

		void printLeveWise(binaryTreeNode<type>* root) {
			queue<binaryTreeNode<type>*> q;
			q.push(root);

			while( !q.empty() ) {

				binaryTreeNode<type>* front = q.front();
				q.pop();
			
				cout << front -> data << " : ";
				if( front -> leftNode ) {
					cout << " LN : " << front -> leftNode -> data << "  ";
					q.push( front -> leftNode );
				}

				if( front -> rightNode ) {
					cout << " RN : "<< front -> rightNode -> data << "  ";
					q.push( front -> rightNode );
				}
				cout << endl;
			}
		}
};
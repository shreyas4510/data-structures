#include "binarySearchTree.h"
#include <string>

class BST {
	public :
		TreeNode<int> *root;
		BST() {
			this -> root = NULL;
		}

	private :
		bool helperFindNode(int data, TreeNode<int> *root) {
			if ( !root )
				return false;

			if ( root -> data == data )
				return true;
			
			bool check = false;
			if ( data < root -> data  ) {
				check = helperFindNode( data, root -> leftNode );
			}
			
			if ( data > root -> data  )
				check = helperFindNode( data, root -> rightNode );

			return check;
		}

		TreeNode<int>* helperInsertFunction( int data, TreeNode<int> *root ) {
			if (!root)
				return new TreeNode<int>(data); 

			if ( data < root -> data )
				root -> leftNode = helperInsertFunction( data, root -> leftNode );
			else
				root -> rightNode = helperInsertFunction( data, root -> rightNode );

			return root;
		}

		void deleteNodeHelper( int data, TreeNode<int> *root, TreeNode<int> *prevNode, string loc ) {
			if (!root) {
				cout << "Element not found" << endl;
				return;
			}

			if ( root -> data == data ) {
				if (!root -> leftNode && !root -> rightNode) {
					if ( prevNode == root ) {
						this -> root = NULL;
						delete root;
						return;
					}
					TreeNode<int> *temp = root;
					if ( loc == "left" )
						prevNode -> leftNode = NULL;
					else
						prevNode -> rightNode = NULL;
					delete temp;
					return;
				}
				else if ( root -> leftNode && !root -> rightNode ) {
					if ( prevNode == root ) {
						TreeNode<int> *temp = root;

						TreeNode<int> *leftNode = root -> leftNode;
						temp -> rightNode = NULL;
						temp -> leftNode = NULL;

						this -> root = leftNode;
						delete temp;
						return;
					}

					TreeNode<int> *temp = root;
					TreeNode<int> *nextLeft = temp -> leftNode;
					temp -> leftNode  = NULL;
					if ( loc == "left" )
						prevNode -> leftNode = nextLeft;
					else
						prevNode -> rightNode = nextLeft;
					delete temp;
					return;
				}
				else if ( root -> rightNode && !root -> leftNode ) {
					if ( prevNode == root ) {
						TreeNode<int> *temp = root;

						TreeNode<int> *rightNode = root -> rightNode;
						temp -> rightNode = NULL;
						temp -> leftNode = NULL;

						this -> root = rightNode;
						delete temp;
						return;
					}
					TreeNode<int> *temp = root;
					TreeNode<int> *nextRight = temp -> rightNode;
					temp -> rightNode  = NULL;
					if ( loc == "left" )
						prevNode -> leftNode = nextRight;
					else		
						prevNode -> rightNode = nextRight;
					delete temp;
					return;
				}
				else {
					TreeNode<int> *temp = root, *tempPrev = root;
					while( temp -> rightNode ) {
						tempPrev = temp;
						temp = temp -> rightNode;
					}

					tempPrev -> rightNode = NULL;
					if ( temp -> leftNode ) {
						TreeNode<int> *nextLeft = temp -> leftNode;
						temp -> leftNode  = NULL;
						tempPrev -> rightNode = nextLeft;
					}

					TreeNode<int> *delNode = root;	
					TreeNode<int> *leftTemp = delNode -> leftNode;
					TreeNode<int> *rightTemp = delNode -> rightNode;

					delNode -> leftNode = NULL;
					delNode -> rightNode = NULL;

					temp -> leftNode = leftTemp;
					temp -> rightNode = rightTemp;

					if ( prevNode == root ) {
						this -> root = temp;	
						delete delNode;
						return;
					}

					if ( loc == "left" ){
						prevNode -> leftNode = NULL;
						prevNode -> leftNode = temp;
					}
					else {
						prevNode -> rightNode = NULL;
						prevNode -> rightNode = temp;
					}
					delete delNode;
					return;
				}
			}

			if ( data < root -> data ) {
				deleteNodeHelper( data, root -> leftNode, root, "left" );
			} else {
				deleteNodeHelper( data, root -> rightNode, root, "right" );
			}
		}

		void printTreeHelper( TreeNode<int> *root ) {
			if (!root)
				return;

			cout << root -> data << " : ";
			if ( root -> leftNode )
				cout << "L-" << root -> leftNode -> data << ", ";

			if ( root -> rightNode )
				cout << "R-" << root -> rightNode -> data;
			cout << endl;

			if ( root -> leftNode )
				printTreeHelper(root -> leftNode);

			if ( root -> rightNode )
				printTreeHelper(root -> rightNode);
		}

	public :
		bool findNode( int data ) {
			return helperFindNode( data, this -> root );
		}

		void insertNode( int data ) {
			this -> root = helperInsertFunction( data, this -> root );
		}

		void deleteNode( int data ) {
			deleteNodeHelper(data, root, root, "");
		}

		void printTree() {
			printTreeHelper( this -> root );
		}
};
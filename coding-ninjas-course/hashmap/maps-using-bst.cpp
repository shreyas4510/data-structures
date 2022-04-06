#include <iostream>
using namespace std;

class binarySearchTreeNode {
	public :
		int key, value;
		binarySearchTreeNode *leftNode;
		binarySearchTreeNode *rightNode;

		binarySearchTreeNode( int key, int value ) {
			this -> key = key;
			this -> value = value;
			this -> leftNode = NULL;
			this -> rightNode = NULL;
		}

		~binarySearchTreeNode() {
			delete this -> leftNode;
			delete this -> rightNode;
		}
};

class operations {

	public:
		binarySearchTreeNode *root = NULL;

	
	private:
		binarySearchTreeNode* helperSetFunction(int key, int value, binarySearchTreeNode *root) {

			if (!root)
				return new binarySearchTreeNode(key, value);

			if (root -> key <= key)
				root -> rightNode = helperSetFunction(key, value, root -> rightNode);

			if (root -> key > key)
				root -> leftNode = helperSetFunction(key, value, root -> leftNode);

			return root;

		}

		int helperGetFunction( int key, binarySearchTreeNode *root ) {

			if (!root)
				return -1;

			if( root -> key == key )
				return root -> value;

			if (root -> key <= key)
				return helperGetFunction( key, root -> rightNode );

			if (root -> key > key)
				return helperGetFunction( key, root -> leftNode );

			return 0;
		}	

		binarySearchTreeNode* removeNode( binarySearchTreeNode* root ) {
			if ( !root -> leftNode && !root -> rightNode ) {
				delete root;
				return NULL;
			}
			else if ( !root -> leftNode ) {
				binarySearchTreeNode *temp = root;
				binarySearchTreeNode *newRoot = root -> rightNode;
				root -> rightNode = NULL;
				delete temp;
				return newRoot;
			}
			else if ( !root -> rightNode ) {
				binarySearchTreeNode *temp = root;
				binarySearchTreeNode *newRoot = root -> leftNode;
				root -> leftNode = NULL;
				delete temp;
				return newRoot;
			}
			else {
				binarySearchTreeNode *temp = root -> leftNode;
				binarySearchTreeNode *prevNode = NULL;
				while( temp -> rightNode ) {
					prevNode = temp;
					temp = temp -> rightNode;
				}

				if (prevNode) {
					prevNode -> rightNode = NULL;
					prevNode -> rightNode = temp -> leftNode;
					temp -> leftNode = NULL;
				}

				temp -> rightNode = root -> rightNode;
				if (prevNode)
					temp -> leftNode = root -> leftNode;

				root -> leftNode = NULL;
				root -> rightNode = NULL;

				delete root;
				return temp;
			}
			return NULL;
		}

		void helperRemove( int key, binarySearchTreeNode *root ) {
			if (!root)
				return;

			if (root -> key == key)
				this -> root = removeNode( root );

			if (root -> leftNode && root -> leftNode -> key == key)
				root -> leftNode = removeNode( root -> leftNode );

			if (root -> rightNode && root -> rightNode -> key == key)
				root -> rightNode = removeNode( root -> rightNode );

			if (root -> key <= key)
				helperRemove( key, root -> rightNode );

			if (root -> key > key)
				helperRemove( key, root -> leftNode );

			return;
		}

	public :
		void set( int key, int data ) {
			if (!this -> root)
				root = new binarySearchTreeNode(key, data);
			else
				root = helperSetFunction(key, data, this -> root);
		}

		int get( int key ) {
			return helperGetFunction(key, this -> root);
		}

		void remove( int key ) {
			helperRemove( key, this -> root );
		}
};

int main() {
	
	operations op;
	
	op.set(6, 54);
	op.set(4, 98);
	op.set(5, 87);
	op.set(7, 72);
	op.set(3, 64);
	op.set(8, 35);
	op.set(2, 42);

	op.remove( 2 );
	cout << "key : 6, " << "value : " << op.get(6) << endl;
	cout << "key : 4, " << "value : " << op.get(4) << endl;
	cout << "key : 5, " << "value : " << op.get(5) << endl;
	cout << "key : 7, " << "value : " << op.get(7) << endl;
	cout << "key : 3, " << "value : " << op.get(3) << endl;
	cout << "key : 8, " << "value : " << op.get(8) << endl;
	cout << "key : 2, " << "value : " << op.get(2) << endl;

}
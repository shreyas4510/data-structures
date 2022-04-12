#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }

        ~Node() {
        	delete left;
        	delete right;
        }
};

class Solution {
	public:
		Node* insert( Node *root, int data ) {
			if ( !root ) {
				root = new Node( data );
			}
			else {
				if ( data < root -> data ) 
					root -> left = insert( root -> left, data );
				else
					root -> right = insert( root -> right, data );
			}
			return root;
		}

		void printLeveWise( Node *root ) {

			if (!root) 
				return;

			queue< Node* > q;
			q.push( root );
			while( !q.empty() ) {
				Node *front = q.front();
				cout << front -> data << " ";
				q.pop();

				if (front -> left)
					q.push( front -> left );

				if (front -> right)
					q.push( front -> right );
			}
		}
};

int main() {

	int size;
	Solution obj;

	cin >> size;
	Node *root = NULL;

	while( size ) {
		int data;
		cin >> data;
		root = obj.insert( root, data );
		size--;
	}

	obj.printLeveWise( root );
	cout << endl;
	delete root;
}
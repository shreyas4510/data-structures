#include <bits/stdc++.h>
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

		void arrangeElements( Node *root, map<int, vector<int>> *store, int num ) {
			if (!root)
				return;

			if (store -> find(num) == store -> end())
				store -> insert({ num, {} });
			store -> at(num).push_back( root -> data );
			
			if (root -> left)
				arrangeElements( root -> left, store, num - 1 );

			if (root -> right)
				arrangeElements( root -> right, store, num + 1 );
		}

		void printVerticalOrder( Node *root ) {
			map<int, vector<int>> *store = new map<int, vector<int>>();
			arrangeElements( root, store, 0 );

			for (auto p : *store) {
				cout << p.second.at( 0 ) << " : ";
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

	obj.printVerticalOrder( root );
	cout << endl;
	delete root;
}
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

		vector<int> storeLeveWise( Node *root, vector<int> levelData ) {
			if (!root) 
				return {};

			queue< Node* > q;
			q.push( root );
			while( !q.empty() ) {
				Node *front = q.front();
				levelData.push_back(front -> data);
				q.pop();

				if (front -> left)
					q.push( front -> left );

				if (front -> right)
					q.push( front -> right );
			}
			return levelData;
		}

		int getIndex( vector<int> v, int k ) {
			auto it = find( v.begin(), v.end(), k );
			return it - v.begin();
		} 
 
		void getVerticalView( Node *root, map<int, int> *store, vector<int> levelData, int key ) {
			if ( !root )
				return;

			if ( store -> find(key) == store -> end() )
				store -> insert({ key, INT_MAX });

			int index = getIndex( levelData, root -> data );
			if ( store -> at(key) > index )
				store -> at(key) = index;

			if (root -> left)
				getVerticalView( root -> left, store, levelData, key - 1 );

			if (root -> right)
				getVerticalView( root -> right, store, levelData, key + 1 );
		}

		void topView(Node * root) {
	        vector<int> levelData;
	        levelData = storeLeveWise( root, levelData );

	        map<int, int> *store = new map<int, int>();
	        getVerticalView( root, store, levelData, 0 );
	        for (auto obj : *store)
				cout << levelData.at(obj.second) << " ";
			delete store;
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

	obj.topView( root );
	cout << endl;
	delete root;
}
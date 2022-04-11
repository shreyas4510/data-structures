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
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    int getHelperHeight( Node *root, int index, int *max ) {
        if (!root)
            return index - 1;

        int leftMax = getHelperHeight( root -> left, index+1, max );
        int rightMax = getHelperHeight( root -> right, index+1, max );

        if ( leftMax > *max )
            *max = leftMax;

        if ( rightMax > *max )
            *max = rightMax;

        return *max;
    } 

    int height(Node* root) {
        int max = 0;
        return getHelperHeight(root, 0, &max);
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}
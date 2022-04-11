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

/* 
Sample Output : 

    First : 
        6
        1 2 5 3 6 4
    
    Second : 
        15
        1 14 3 7 4 5 15 6 13 10 11 2 12 8 9
*/


    void postOrder(Node *root) {

        if (!root)
            return;

        postOrder(root -> left);
        postOrder(root -> right);
        cout << root -> data << " ";
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
  
    myTree.postOrder(root);
    return 0;
}

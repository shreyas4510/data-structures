#include <iostream>
#include "bstClass.h"
using namespace std;

int main() {
	BST binarySearchTree;
	binarySearchTree.insertNode(7);
	binarySearchTree.insertNode(3);
	binarySearchTree.insertNode(12);
	binarySearchTree.insertNode(1);
	binarySearchTree.insertNode(5);
	binarySearchTree.insertNode(11);
	binarySearchTree.insertNode(4);
	binarySearchTree.insertNode(10);

	binarySearchTree.printTree();

	cout << endl << endl;
	binarySearchTree.deleteNode(3);
	binarySearchTree.printTree();

	// cout << endl;
	// cout << ( binarySearchTree.findNode( 1 ) ? "true" : "false" ) << endl;
	// cout << ( binarySearchTree.findNode( 7 ) ? "true" : "false" ) << endl;
	// cout << ( binarySearchTree.findNode( 10 ) ? "true" : "false" ) << endl;
	// cout << ( binarySearchTree.findNode( 2 ) ? "true" : "false" ) << endl;
	// cout << ( binarySearchTree.findNode( 5 ) ? "true" : "false" ) << endl;
	// cout << ( binarySearchTree.findNode( 4 ) ? "true" : "false" ) << endl;
}
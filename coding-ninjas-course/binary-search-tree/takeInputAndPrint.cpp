#include <iostream>
#include "binarySearchTree.h"
using namespace std;

int main(int argc, char const *argv[])
{
	operations<int> op;
	TreeNode<int> *root = op.takeInput();
	op.printLevelWise(root);
	return 0;
}
/*
 * BinaryTreeInorderTraversal.cpp
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#include "P51~100.h"

vector<int> inorderTraversal(TreeNode* root) {

}


void BinaryTreeTest()
{
	TreeNode * root = NULL;
	map<int, int> nodes;

	cout << "test case 1" << endl;
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 2" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	assert(root == NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 3" << endl;
	nodes = {{5, 5}, {1, 1}, {3, 3}, {4, 4}, {2, 2}, {6, 6}, {7, 7}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 4" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 5" << endl;
	nodes = {{1, 1}, {2, 2}, {4, 4}, {8, 8}, {16, 16}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {3, 3}, {7, 7}, {15, 15}, {31, 31}};
	root = GenBinaryTreeFromMap(nodes);
	assert(root != NULL);
	InOrderTraversal(root);
	PreOrderTraversal(root);
	PostOrderTraversal(root);
	BreadthTraversal(root);
}

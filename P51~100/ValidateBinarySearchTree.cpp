/*
 * ValidateBinarySearchTree.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: user
 */

#include "P51~100.h"

void InOrderVisit(vector<int> & mem, TreeNode * root)
{
	if(!root)
		return;

	if(root->left)
		InOrderVisit(mem, root->left);
	mem.push_back(root->val);
	if(root->right)
		InOrderVisit(mem, root->right);
}

bool isValidBST(TreeNode* root) {
	vector<int> mem;
	InOrderVisit(mem, root);

	int n = mem.size();

	if(n <= 1)
		return true;

	bool ret = true;
	for(int i = 1 ; i < n; ++ i)
	{
		if(mem[i] <= mem[i - 1])
		{
			ret = false;
			break;
		}
	}
	return ret;
}

void IsValidBSTTest()
{
	TreeNode * root = NULL;
	map<int, int> nodes;
	bool ret;

	cout << "test case 1" << endl;
	nodes = {};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 2" << endl;
	nodes = {{1, 1}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 3" << endl;
	nodes = {{1, 2}, {2, 1}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 4" << endl;
	nodes = {{1, 1}, {3, 2}, {7, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 5" << endl;
	nodes = {{1, 3}, {2, 2}, {4, 1}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 6" << endl;
	nodes = {{1, 1}, {2, 2}, {3, 3}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 7" << endl;
	nodes = {{1, 1}, {3, 3}, {6, 2}};
	root = GenBinaryTreeFromMap(nodes);
	ret = isValidBST(root);
	assert(ret == true);
	cout << ret << endl;

}

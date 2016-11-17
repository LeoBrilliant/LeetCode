/*
 * Tree.cpp
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#include "Tree.h"
#include "VectorFuncs.h"

// 根节点的索引是1
TreeNode* GenBinaryTreeFromMap(map<int, int>& nodes) {
	TreeNode * root = NULL;
	TreeNode * curr = NULL;

	int leftindex = -1;
	int rightindex = -1;

	list<TreeNode *> buffer;

	for(auto node : nodes)
	{
		if(!root)
		{
			curr = new TreeNode(node.second);
			root = curr;
			buffer.push_back(root);
		}

		curr = buffer.front();
		leftindex = node.first * 2;
		rightindex = node.first * 2 + 1;

		if(nodes.find(leftindex) != nodes.end())
		{
			TreeNode * left = new TreeNode(nodes[leftindex]);
			curr->left = left;
			buffer.push_back(left);
		}

		if(nodes.find(rightindex) != nodes.end())
		{
			TreeNode * right = new TreeNode(nodes[rightindex]);
			curr->right = right;
			buffer.push_back(right);
		}

		buffer.pop_front();
	}

	return root;
}

void InOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;

	if(root->left)
		InOrderTraversalHandler(root->left);
	cout << root->val << ", ";
	if(root->right)
		InOrderTraversalHandler(root->right);
}

void InOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	InOrderTraversalHandler(root);
	cout << "] " << endl;
}

void PreOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;
	cout << root->val << ", ";

	PreOrderTraversalHandler(root->left);

	if(root->right)
		PreOrderTraversalHandler(root->right);
}

void PreOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	PreOrderTraversalHandler(root);
	cout << "] " << endl;
}

void PostOrderTraversalHandler(TreeNode* root) {
	if(!root)
		return;
	if(root->left)
		PostOrderTraversalHandler(root->left);

	if(root->right)
		PostOrderTraversalHandler(root->right);

	cout << root->val << ", ";

}

void PostOrderTraversal(TreeNode* root)
{
	cout << "[ ";
	PostOrderTraversalHandler(root);
	cout << "] " << endl;
}

void BreadthTraversal(TreeNode* root) {
	if(!root)
		return;

	list<TreeNode *> buffer;
	vector<int> value;

	buffer.push_back(root);

	while(!buffer.empty())
	{
		TreeNode * curr = buffer.front();
		if(curr->left)
			buffer.push_back(curr->left);
		if(curr->right)
			buffer.push_back(curr->right);

		value.push_back(curr->val);
		buffer.pop_front();
	}

	DumpVector(value);
}

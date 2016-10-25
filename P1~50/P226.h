/*
 * P226.h
 *
 *  Created on: 2016年10月3日
 *      Author: LeoBrilliant
 */

#ifndef P226_H_
#define P226_H_

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef struct TreeNode TreeNode;

TreeNode * invertTree(TreeNode * root)
{
	if(!root) return NULL;
	TreeNode * left = root->left;
	root->left = root->right;
	root->right = left;
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

TreeNode * invertTree2(TreeNode * root)
{
	if(!root) return NULL;
	list<TreeNode*> lt;
	lt.push_back(root);
	for(auto i : lt)
	{
		TreeNode * left = i->left;
		i->left = i->right;
		i->right = left;
		if(i->left)
		lt.push_back(i->left);
		if(i->right)
		lt.push_back(i->right);
	}
	return root;
}

void PreorderTravel(TreeNode * root)
{
	if(root)
	{
		cout << root->val << ", ";
		PreorderTravel(root->left);
		PreorderTravel(root->right);
	}
	else
		return;
}

void InorderTravel(TreeNode * root)
{
	if(root)
	{
		PreorderTravel(root->left);
		cout << root->val << ", ";
		PreorderTravel(root->right);
	}
	else
		return;
}
TreeNode * GenBinaryTree(list<TreeNode*> &nodes, list<int> & eles)
{
	TreeNode * root, * curr;
	if(eles.size())
	{
		if(nodes.empty())
		{
			root = new TreeNode(eles.front());
			//root->val = eles.front();
			eles.pop_front();
			nodes.push_back(root);
		}

		for(auto i = nodes.begin(); i != nodes.end() && eles.size(); ++i)
		{
			curr = *i;
			curr->left = new TreeNode(eles.front());
			curr->left->val = eles.front();
			eles.pop_front();
			nodes.push_back(curr->left);

			if(eles.size())
			{
				curr->right = new TreeNode(eles.front());
				curr->right->val = eles.front();
				eles.pop_front();
				nodes.push_back(curr->right);
			}
		}
	}

	root = nodes.front();
	return root;
}

void InvertBinaryTreeTest()
{
	list<TreeNode*> lt;
	list<int> eles{4, 2, 7, 1, 3, 6, 9};
	TreeNode * root;

	root = GenBinaryTree(lt, eles);

	PreorderTravel(root);
	cout << endl;
	InorderTravel(root);
	cout << endl;

	root = invertTree2(root);

	PreorderTravel(root);
	cout << endl;
	InorderTravel(root);
	cout << endl;
}

#endif /* P226_H_ */

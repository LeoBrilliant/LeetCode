/*
 * UniqueBinarySearchTreeII.cpp
 *
 *  Created on: 2016年11月16日
 *      Author: user
 */

#include "P51~100.h"

TreeNode * InsertNode(TreeNode * parent, int value)
{
	TreeNode * ret = NULL;
	if(!parent)
	{
		parent = new TreeNode(value);
		ret = parent;
	}
	else if(parent->val > value)
	{
		if(!parent->left)
		{
			parent->left = new TreeNode(value);
			ret = parent->left;
		}
		else
		{
			ret = InsertNode(parent->left, value);
		}
	}
	else if(parent->val < value)
	{
		if(!parent->right)
		{
			parent->right = new TreeNode(value);
			ret = parent->right;
		}
		else
		{
			ret = InsertNode(parent->right, value);
		}
	}

	return ret;
}

TreeNode * CopyTree(TreeNode * root)
{
	TreeNode * ret = NULL;
	if(!root)
	{
		ret = NULL;
	}
	else
	{
		ret = new TreeNode(root->val);
		ret->left = CopyTree(root->left);
		ret->right = CopyTree(root->right);
	}
	return ret;
}

void DeleteTree(TreeNode * root)
{
	if(!root)
	{
		return;
	}
	else
	{
		if(root->left)
			DeleteTree(root->left);
		if(root->right)
			DeleteTree(root->right);
		delete root;
	}
}

bool IsSameTree(TreeNode * t1, TreeNode * t2)
{
	bool ret = true;
	if(!t1 && !t2)
	{
		ret = true;
	}
	else if(!t1 || !t2)
	{
		ret = false;
	}
	else if(t1->val != t2->val)
	{
		ret = false;
	}
	else
	{
		ret = IsSameTree(t1->left, t2->left) && IsSameTree(t1->right, t2->right);
	}
	return ret;
}

void GenerateTree(vector<TreeNode*> & trees, vector<int> & nodes, TreeNode * root)
{
	if(nodes.size() == 0)
	{
		bool hasSame = false;
		for(auto t : trees)
		{
			if(IsSameTree(t, root))
			{
				hasSame = true;
				break;
			}
		}
		if(!hasSame)
			trees.push_back(root);
		else
			DeleteTree(root);
		return;
	}

	int n = nodes.size();
	for(int i = 0; i < n; ++i)
	{
		vector<int> left;
		TreeNode * next = CopyTree(root);
		if(!root)
			root = InsertNode(root, nodes[i]);
		else
			InsertNode(root, nodes[i]);
		for(int j = 0; j < n; ++j)
		{
			if(i != j)
				left.push_back(nodes[j]);
		}
		GenerateTree(trees, left, root);

		root = next;
	}
}

vector<TreeNode*> AgenerateTrees(int n) {

	vector<TreeNode*> ret;

	if(n == 0)
		return ret;

	vector<int> nodes;
	for(int i = 1; i <= n; ++i)
		nodes.push_back(i);

	GenerateTree(ret, nodes, NULL);
	return ret;
}

vector<TreeNode*> Helper(int begin, int end)
{
	vector<TreeNode*> ret;
	if(begin > end)
	{
		ret.push_back(NULL);
	}
	else if(begin == end)
	{
		TreeNode * node = new TreeNode(begin);
		ret.push_back(node);
	}
	else
	{
		for(int i = begin; i <= end; ++i)
		{
			vector<TreeNode*> left = Helper(begin, i - 1);
			vector<TreeNode*> right = Helper(i + 1, end);
			for(int l = 0; l < left.size(); ++l)
			{
				for(int r = 0; r < right.size(); ++r)
				{
					TreeNode * root = new TreeNode(i);
					root->left = left[l];
					root->right = right[r];
					ret.push_back(root);
				}
			}
		}
	}
	return ret;
}

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> ret;

	if(n == 0)
		return ret;

	return Helper(1, n);
}

void GenerateTreesTest()
{
	vector<TreeNode*> ret;
	int n;
	int count;
	cout << "test case 1" << endl;
	n = 0;
	ret = generateTrees(n);
	count = ret.size();
	assert(count == 0);
	for(auto t : ret)
	{
		InOrderTraversal(t);
	}

	cout << "test case 2" << endl;
	n = 1;
	ret = generateTrees(n);
	count = ret.size();
	assert(count == 1);
	for(auto t : ret)
	{
		InOrderTraversal(t);
	}

	cout << "test case 3" << endl;
	n = 2;
	ret = generateTrees(n);
	count = ret.size();
	assert(count == 2);
	for(auto t : ret)
	{
		TreeNode * root = t;
		//cout << t << endl;
		//InOrderTraversal(t);
		PostOrderTraversal(t);
		//PostOrderTraversal(root);
	}

	cout << "test case 4" << endl;
	n = 3;
	ret = generateTrees(n);
	count = ret.size();
	assert(count == 5);
	for(auto t : ret)
	{
		//cout << t << endl;
		//InOrderTraversal(t);
		PreOrderTraversal(t);
		PostOrderTraversal(t);
	}

	cout << "test case 5" << endl;
	n = 8;
	ret = generateTrees(n);
	count = ret.size();
	//assert(count == 5);
	for(auto t : ret)
	{
		//cout << t << endl;
		//InOrderTraversal(t);
		//PostOrderTraversal(t);
	}
}

/*
 * UniqueBinarySearchTrees.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: user
 */

#include "P51~100.h"

static vector<TreeNode*> Helper(int begin, int end)
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

int AnumTrees(int n) {
	vector<TreeNode*> ret;

	if(n == 0)
		return 0;

	ret = Helper(1, n);
	return ret.size();
}

int numTrees(int n)
{
	if(n == 0)
		return 0;

	vector<int> ret{1, 1, 2, 5};
	if(n > 3)
	{
		for(int i = 4; i <= n; ++i)
		{
			int count = 0;
			for(int j = 0; j < i; ++j)
			{
				count += ret[j] * ret[i - 1 - j];
			}
			ret.push_back(count);
		}
	}
	return ret[n];
}

void NumTreesTest()
{
	int n;
	int ret;

	cout << "test case 1" << endl;
	n = 0;
	ret = numTrees(n);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	n = 1;
	ret = numTrees(n);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 3" << endl;
	n = 2;
	ret = numTrees(n);
	assert(ret == 2);
	cout << ret << endl;

	cout << "test case 4" << endl;
	n = 3;
	ret = numTrees(n);
	assert(ret == 5);
	cout << ret << endl;

	cout << "test case 5" << endl;
	n = 8;
	ret = numTrees(n);
	assert(ret == 1430);
	cout << ret << endl;

	cout << "test case 6" << endl;
	n = 4;
	ret = numTrees(n);
	assert(ret == 14);
	cout << ret << endl;

	cout << "test case 7" << endl;
	n = 5;
	ret = numTrees(n);
	assert(ret == 42);
	cout << ret << endl;

	cout << "test case 8" << endl;
	n = 19;
	ret = numTrees(n);
//	assert(ret == 42);
	cout << ret << endl;
}



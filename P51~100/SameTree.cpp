/*
 * SameTree.cpp
 *
 *  Created on: 2016年11月17日
 *      Author: user
 */

#include "P51~100.h"


bool isSameTree(TreeNode * t1, TreeNode * t2)
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
		ret = isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
	}
	return ret;
}

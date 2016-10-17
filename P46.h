/*
 * P46.h
 *
 *  Created on: 2016年10月16日
 *      Author: LeoBrilliant
 */

#ifndef P46_H_
#define P46_H_

#include "Common.h"

void PermuteRecursive(vector<vector<int>> & all, vector<int> & curr, vector<int> & left)
{
	if(left.size() == 0)
	{
		all.push_back(curr);
		return;
	}

	for(auto i : left)
	{
		curr.push_back(i);
		vector<int> nleft;
		for(auto j : left)
		{
			if(i != j)
				nleft.push_back(j);
		}
		PermuteRecursive(all, curr, nleft);
		curr.pop_back();
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<int> curr;
	vector<vector<int>> all;
	PermuteRecursive(all, curr, nums);
	return all;
}

void PermuteTest()
{
	vector<int> vi;

	vi = {1, 2, 3};

	vi = {};

	vi = {1};

	vector<vector<int>> result = permute(vi);

	DumpVectorOfVector(result);
}

#endif /* P46_H_ */

/*
 * P31.h
 *
 *  Created on: 2016年10月18日
 *      Author: LeoBrilliant
 */

#ifndef P31_H_
#define P31_H_

#include "Common.h"

void NextPermuteUniqueRecursive(vector<vector<int>> & all, vector<int> & curr,
		vector<int> & left, vector<int> & nums, int index)
{
	if(left.size() == 0 && all.size() < 2)
	{
		all.push_back(curr);
		return;
	}

	bool begin = false;
	int last = -1;
	for(size_t i = 0; i < left.size(); ++i)
	{
		if((!begin  || left[last] != left[i]) &&
				(left[i] == nums[index] || (all.size() == 1)))
		{
			curr.push_back(left[i]);
			last = i;
			begin = true;
		}
		else
		{
			continue;
		}

		vector<int> nleft;
		for(size_t j = 0; j < left.size(); ++j)
		{
			if(i != j)
				nleft.push_back(left[j]);
		}
		NextPermuteUniqueRecursive(all, curr, nleft, nums, index + 1);
		curr.pop_back();
	}
}



void nextPermutation(vector<int>& nums) {
	vector<int> curr;
	vector<int> left = nums;
	vector<vector<int>> all;
	sort(left.begin(), left.end());
	NextPermuteUniqueRecursive(all, curr, left, nums, 0);
	if(all.size() == 2)
		nums = all[1];
	else
		nums = left;
	return;
}

void NextPermutationTest()
{
	vector<int> vi;

	vi = {1, 2, 3};

	vi = {};

	//vi = {1};
//
//	vi = {1, 1, 2};
//
//	vi = {1, 2, 1};
//
//	vi = {2, 1, 1};

	//vi = {1, 1, 1};

	nextPermutation(vi);

	DumpVector(vi);
}

#endif /* P31_H_ */

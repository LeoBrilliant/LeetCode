/*
 * P47.h
 *
 *  Created on: 2016年10月17日
 *      Author: LeoBrilliant
 */

#ifndef P47_H_
#define P47_H_

#include "Common.h"


void PermuteUniqueRecursive(vector<vector<int>> & all, vector<int> & curr, vector<int> & left)
{
	if(left.size() == 0)
	{
		all.push_back(curr);
		return;
	}

	bool begin = false;
	int last = 0;
	for(size_t i = 0; i < left.size(); ++i)
	{
		if(!begin  || last != left[i])
		{
			curr.push_back(left[i]);
			last = left[i];
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
		PermuteUniqueRecursive(all, curr, nleft);
		curr.pop_back();
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<int> curr;
	vector<vector<int>> all;
	sort(nums.begin(), nums.end());
	PermuteUniqueRecursive(all, curr, nums);
	return all;
}

void PermuteUniqueTest()
{
	vector<int> vi;

	vi = {1, 2, 3};

	//vi = {};

	//vi = {1};

	vi = {1, 1, 2};

	vi = {1, 1, 1};

	vector<vector<int>> result = permuteUnique(vi);

	DumpVectorOfVector(result);
}


#endif /* P47_H_ */

/*
 * P40.h
 *
 *  Created on: 2016年10月19日
 *      Author: user
 */

#ifndef P40_H_
#define P40_H_

#include "Common.h"

void GetCombinationSum(vector<vector<int>> & s, vector<int> & c, vector<int> & curr, int target)
{
	if(target == 0)
	{
		s.push_back(curr);

		return;
	}
	else if(target < 0)
		return;

	int last = -1;
	for(size_t i = 0; i < c.size(); ++i)
	//while(!left.empty())
	{
		//int i = left[0];
		//left.erase(left.begin());
		if(c[i] != last && target - c[i] >= 0)
		{
			vector<int> left;
			for(size_t j = i + 1; j < c.size(); ++j)
				left.push_back(c[j]);

			curr.push_back(c[i]);
			GetCombinationSum(s, left, curr, target - c[i]);
			last = curr.back();
			curr.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ret;
	vector<int> curr;
	sort(candidates.begin(), candidates.end());
	GetCombinationSum(ret, candidates, curr, target);

	return ret;
}


void CombinationSum2Test()
{
	vector<int> vi;
	int t;

	vi = {2, 3, 6, 7};
	t = 7;

	vi = {};
	t = 0;

	vi = {1, 2, 3, 4, 5, 6};
	t = 7;

	vi = {10, 1, 2, 7, 6, 1, 5};
	t = 8;
	vector<vector<int>> ret = combinationSum2(vi, t);

	DumpVectorOfVector(ret);
}


#endif /* P40_H_ */

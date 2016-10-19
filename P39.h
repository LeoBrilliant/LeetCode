/*
 * P39.h
 *
 *  Created on: 2016年10月19日
 *      Author: user
 */

#ifndef P39_H_
#define P39_H_

#include "Common.h"


void GetCombinationSum(set<vector<int>> & s, vector<int> & c, vector<int> & curr, int target)
{
	if(target == 0)
	{
		vector<int> tmp(curr);
		sort(tmp.begin(), tmp.end());
		if(!s.count(tmp))
			s.insert(tmp);

		return;
	}
	else if(target < 0)
		return;

	for(auto i : c)
	{
		if(target - i >= 0)
		{
			curr.push_back(i);
			GetCombinationSum(s, c, curr, target - i);
			curr.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	set<vector<int>> s;
	vector<int> curr;
	GetCombinationSum(s, candidates, curr, target);

	vector<vector<int>> ret;

	for(auto vi : s)
	{
		ret.push_back(vi);
	}
	return ret;
}

void CombinationSumTest()
{
	vector<int> vi;
	int t;

	vi = {2, 3, 6, 7};
	t = 7;

	vi = {};
	t = 0;

	vi = {1, 2, 3, 4, 5, 6};
	t = 7;
	vector<vector<int>> ret = combinationSum(vi, t);

	DumpVectorOfVector(ret);
}

#endif /* P39_H_ */

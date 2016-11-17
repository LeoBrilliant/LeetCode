/*
 * SubsetsII.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

static void Combination(vector<vector<int>> & ret, vector<int> & curr, vector<int> & nums, int index, int left)
{
	if(left == 0)
	{
		ret.push_back(curr);
		return;
	}

	if(nums.size() - index < left)
		return;

	int last = -1;

	for(int i = index; i < nums.size(); ++ i)
	{
		if(last == -1 || nums[last] != nums[i])
		{
			curr.push_back(nums[i]);
			last = i;
			Combination(ret, curr, nums, i + 1, left - 1);
			curr.pop_back();
		}
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ret;
	int n = nums.size();

	sort(nums.begin(), nums.end());

	for(int i = 1; i <= n; ++i)
	{
		vector<int> curr;
		vector<vector<int>> tmp;
		Combination(tmp, curr, nums, 0, i);

		for(auto vi : tmp)
			ret.push_back(vi);
	}

	vector<int> v;
	ret.push_back(v);
	return ret;
}

void SubsetsIITest()
{
	vector<int> nums;
	vector<vector<int>> ret;

	cout << "test case 1" << endl;
	nums = {};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 2" << endl;
	nums = {1, 2, 3};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 8);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	nums = {1};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 4" << endl;
	nums = {1, 1, 1};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 4);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	nums = {1, 2, 2};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 6);
	DumpVectorOfVector(ret);

	cout << "test case 6" << endl;
	nums = {4,4,4,1,4};
	ret = subsetsWithDup(nums);
	assert(ret.size() == 10);
	DumpVectorOfVector(ret);

}

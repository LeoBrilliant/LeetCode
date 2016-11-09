/*
 * Combinations.cpp
 *
 *  Created on: 2016年11月9日
 *      Author: user
 */

#include "P51~100.h"

void Combination(vector<vector<int>> & ret, vector<int> & curr, vector<int> & nums, int index, int left)
{
	if(left == 0)
	{
		ret.push_back(curr);
		return;
	}

	if(nums.size() - index < left)
		return;

	for(int i = index; i < nums.size(); ++ i)
	{
		curr.push_back(nums[i]);
		Combination(ret, curr, nums, i + 1, left - 1);
		curr.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ret;

	if(n <= 0 || k <= 0)
		return ret;

	vector<int> nums;
	for(int i = 1; i <= n ; ++i)
		nums.push_back(i);

	vector<int> curr;

	Combination(ret, curr, nums, 0, k);
	return ret;
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> ret;
	int n = nums.size();

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

void CombineTest()
{
	int n;
	int k;
	vector<vector<int>> ret;

	cout << "test case 1" << endl;
	n = 0;
	k = 0;
	ret = combine(n, k);
	assert(ret.size() == 0);
	DumpVectorOfVector(ret);

	cout << "test case 2" << endl;
	n = 0;
	k = 1;
	ret = combine(n, k);
	assert(ret.size() == 0);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	n = 1;
	k = 0;
	ret = combine(n, k);
	assert(ret.size() == 0);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	n = 4;
	k = 2;
	ret = combine(n, k);
	assert(ret.size() == 6);
	assert(ret[0].size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 4" << endl;
	n = 4;
	k = 1;
	ret = combine(n, k);
	assert(ret.size() == 4);
	assert(ret[0].size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	n = 4;
	k = 3;
	ret = combine(n, k);
	assert(ret.size() == 4);
	assert(ret[0].size() == 3);
	DumpVectorOfVector(ret);

	cout << "test case 6" << endl;
	n = 4;
	k = 4;
	ret = combine(n, k);
	assert(ret.size() == 1);
	assert(ret[0].size() == 4);
	DumpVectorOfVector(ret);

	cout << "test case 7" << endl;
	n = 1;
	k = 1;
	ret = combine(n, k);
	assert(ret.size() == 1);
	assert(ret[0].size() == 1);
	DumpVectorOfVector(ret);
}


void SubsetsTest()
{
	vector<int> nums;
	vector<vector<int>> ret;

	cout << "test case 1" << endl;
	nums = {};
	ret = subsets(nums);
	assert(ret.size() == 1);
	DumpVectorOfVector(ret);

	cout << "test case 1" << endl;
	nums = {1};
	ret = subsets(nums);
	assert(ret.size() == 2);
	DumpVectorOfVector(ret);

	cout << "test case 3" << endl;
	nums = {1, 2};
	ret = subsets(nums);
	assert(ret.size() == 4);
	DumpVectorOfVector(ret);

	cout << "test case 4" << endl;
	nums = {2, 1};
	ret = subsets(nums);
	assert(ret.size() == 4);
	DumpVectorOfVector(ret);

	cout << "test case 5" << endl;
	nums = {1, 2, 3};
	ret = subsets(nums);
	assert(ret.size() == 8);
	DumpVectorOfVector(ret);

}

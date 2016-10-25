/*
 * P41.h
 *
 *  Created on: 2016年10月17日
 *      Author: user
 */

#ifndef P41_H_
#define P41_H_

#include "Common.h"

int firstMissingPositive(vector<int>& nums) {

	if(nums.size() == 0) return 1;

	int ret = 0;
	for(int i = 0; i < nums.size(); ++i)
	{
		while(nums[i] > 0 && nums[i] != i + 1 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
		{
			swap(nums[i], nums[nums[i] - 1]);
		}
	}

	int i;
	for(i = 0; i < nums.size(); ++i)
	{
		if(nums[i] != i + 1)
		{
			ret = i + 1;
			break;
		}
	}

	if(i == nums.size())
		ret = i + 1;

	return ret;
}

void FirstMissingPositiveTest()
{
	vector<int> vi;

	vi = {};
	//vi = {1,2,0};
	//vi = {3, 4, -1, 1};
	vi = {-1, -2};
	vi = {-1, 2};
	//vi = {0, 1};
	vi = {-1, 1000};
	vi = {1, 1};
	vi = {3, 2};
	int ret = firstMissingPositive(vi);

	cout << ret << endl;

	DumpVector(vi);
}

#endif /* P41_H_ */

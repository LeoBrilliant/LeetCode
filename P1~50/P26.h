/*
 * P26.h
 *
 *  Created on: 2016年10月15日
 *      Author: LeoBrilliant
 */

#ifndef P26_H_
#define P26_H_

#include "Common.h"

int removeDuplicates(vector<int>& nums) {

	if(nums.size() <= 1)
		return nums.size();

	size_t i, j;
	int lastinsert = nums[0];

	for(i = 1, j = 1; i < nums.size(); ++i)
	{
		if(nums[i] == lastinsert)
		{
			//insert position
			if(j == 0)
				j = i;
		}
		else
		{
			nums[j++] = nums[i];
			lastinsert = nums[i];
		}
	}

	return j;
}

void RemoveDuplicatesTest()
{
	vector<int> vi;

	vi = {1, 1, 2};

	//vi = {1};

	//vi = {1, 1};

	//vi = {1, 1, 1};

	//vi = {1, 2, 3};

	vi = {1, 2, 3, 3, 4, 5, 5, 6};

	int k = removeDuplicates(vi);

	cout << k << endl;

	DumpVector(vi);
}

#endif /* P26_H_ */

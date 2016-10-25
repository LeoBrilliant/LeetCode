/*
 * P35.h
 *
 *  Created on: 2016年10月18日
 *      Author: LeoBrilliant
 */

#ifndef P35_H_
#define P35_H_

#include "Common.h"

int binarySearchPosition(vector<int>& nums, int begin, int end, int target)
{
	int index = -1;
	int high = nums.size();
	int low = -1;
	for(int i = begin, j = end; i <= j;)
	{
		int middle = (i + j) / 2;
		if(nums[middle] == target)
		{
			index = middle;
			break;
		}
		else if(nums[middle] > target)
		{
			j = middle - 1;
			high = middle;
		}
		else
		{
			i = middle + 1;
			low = middle;
		}
	}

	int ret = -1;
	if(index != -1)
	{
		ret = index;
	}
	else if(high == 0)
	{
		ret = high;
	}
	else if(low == end)
	{
		ret = end + 1;
	}
	else if(nums[low] < target)
	{
		ret = low + 1;
	}

	return ret;
}
int searchInsert(vector<int>& nums, int target) {
	return binarySearchPosition(nums, 0, nums.size() - 1 , target);
}

void SearchInsertTest()
{
	vector<int> vi;
	int target;

	vi = {0, 1, 2, 3, 5, 6, 7};

	target = 0;

	target = -1;

	target = 8;

	target = 4;

	vi = {0, 1, 2, 4, 5, 6, 7};
	target = 3;

	vi = {0, 1, 3, 4, 5, 6, 7};
	target = 2;
	int index;
	index = searchInsert(vi, target);

	cout << index << endl;
}


#endif /* P35_H_ */

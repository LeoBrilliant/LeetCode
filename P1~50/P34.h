/*
 * P34.h
 *
 *  Created on: 2016年10月18日
 *      Author: LeoBrilliant
 */

#ifndef P34_H_
#define P34_H_

#include "Common.h"

int binarySearchCpy(vector<int>& nums, int begin, int end, int target)
{
	int index = -1;
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
		}
		else
		{
			i = middle + 1;
		}
	}

	return index;
}

int FindLowest(vector<int> & nums, int begin, int end, int target)
{
	int index = -1;
	int lowest = binarySearch(nums, begin, end, target);
	index = lowest;
	while(index != -1)
	{
		index = binarySearch(nums, begin, lowest - 1, target);
		if(index != -1)
			lowest = index;
	}
	return lowest;
}

int FindHighest(vector<int> & nums, int begin, int end, int target)
{
	int index = -1;
	int highest = binarySearch(nums, begin, end, target);
	index = highest;
	while(index != -1)
	{
		index = binarySearch(nums, highest + 1, end, target);
		if(index != -1)
			highest = index;
	}
	return highest;
}

vector<int> searchRange(vector<int>& nums, int target) {
	int low = FindLowest(nums, 0, nums.size() - 1, target);
	int high = FindHighest(nums, 0, nums.size() - 1, target);

	vector<int> ret {low, high};
	return ret;
}

void SearchRangeTest()
{
	vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7};
	//vector<int> vi{4, 5, 6, 7, 0, 1, 2, 3};

	int target = 0;
	target = 3;
	vi = {0, 0, 0, 3, 3, 3, 6, 7};
	target = 8;

	vi = {8, 8, 8, 8, 8, 9};
	vector<int> index;
	index = searchRange(vi, target);

	DumpVector(index);
}

#endif /* P34_H_ */

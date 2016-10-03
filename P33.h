/*
 * P33.h
 *
 *  Created on: 2016年10月3日
 *      Author: LeoBrilliant
 */

#include <iostream>

using namespace std;

int binarySearch(vector<int>& nums, int begin, int end, int target)
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

int search(vector<int> & nums, int target)
{
	//确定pivot
	int pivot = -1, index = -1;
	for(int i = 0; i < nums.size() - 1; ++i)
	{
		if(nums[i] > nums[i + 1])
			pivot = i;
	}

	if(pivot == -1)
	{
		index = binarySearch(nums, 0, nums.size() - 1, target);
	}
	else
	{
		index = binarySearch(nums, 0, pivot, target);
		if(index == -1)
			index = binarySearch(nums, pivot + 1, nums.size() - 1, target);
	}

	return index;
}

void SearchTest()
{
	//vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7};
	vector<int> vi{4, 5, 6, 7, 0, 1, 2, 3};

	int target = 0;
	int index = -1;
	index = search(vi, target);

	cout << index << endl;
}




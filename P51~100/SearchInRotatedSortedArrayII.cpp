/*
 * SearchInRotatedSortedArrayII.cpp
 *
 *  Created on: 2016年11月9日
 *      Author: user
 */

#include "P51~100.h"

int binarySearchA(vector<int>& nums, int begin, int end, int target)
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

int binarySearch(vector<int> & nums, int begin, int end, int target)
{
	int index = -1;

	if(begin > end)
	{
		return index;
	}

	int middle = (begin + end) / 2;
	if(nums[middle] == target)
		return middle;

	if(nums[middle] < target && target <= nums[end])
	{
		index = binarySearch(nums, middle + 1, end, target);
	}
	else if(nums[middle] < target && target > nums[end])
	{
		index = binarySearch(nums, begin, middle - 1, target);
	}
	else if(nums[middle] > target && target >= nums[begin])
	{
		index = binarySearch(nums, begin, middle - 1, target);
	}
	else if(nums[middle] > target && target <= nums[begin])
	{
		index = binarySearch(nums, middle + 1, end, target);
	}

	return index;
}

bool search(vector<int> & nums, int target)
{
	int n = nums.size();
	if(!n)
		return false;

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
		if(target >= nums[0])
			index = binarySearch(nums, 0, pivot, target);
		//if(index == -1)
		else
			index = binarySearch(nums, pivot + 1, nums.size() - 1, target);
	}

	return index != -1;
}

void SearchTest()
{
	vector<int> vi;
	int target;
	bool ret;

	cout << "test case 1" << endl;
	vi = {};
	target = 1;
	ret = search(vi, target);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {1};
	target = 1;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {0, 1, 2, 3, 4, 5, 6, 7};
	target = 0;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vi = {0, 1, 2, 3, 4, 5, 6, 7};
	target = 7;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 5" << endl;
	vi = {0, 1, 2, 3, 4, 5, 6, 7};
	target = 8;
	ret = search(vi, target);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vi = {4, 5, 6, 7, 0, 1, 2, 3};
	target = 7;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 7" << endl;
	vi = {4, 5, 5,  6, 7, 0, 1, 2, 3};
	target = 5;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 8" << endl;
	vi = {4, 5, 5, 6, 7, 0, 1, 2, 3, 3, 4};
	target = 4;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 9" << endl;
	vi = {5, 5, 6, 7, 0, 1, 2, 3, 3, 4};
	target = 4;
	ret = search(vi, target);
	assert(ret == true);
	cout << ret << endl;
}

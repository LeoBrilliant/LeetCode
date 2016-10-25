/*
 * MaximumSubarray.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

int MaxSubSum(vector<int> & nums, int left, int right)
{
	if(left == right) return nums[left];

	int middle = (left + right) / 2;
	int leftsum = MaxSubSum(nums, left, middle);
	int rightsum = MaxSubSum(nums, middle + 1, right);
	int sl = nums[middle];
	int lefts = 0;
	for(int i = middle; i >= left; -- i)
	{
		lefts += nums[i];
		if(lefts > sl) sl = lefts;
	}

	int sr = nums[middle + 1];
	int rights = 0;
	for(int i = middle + 1; i <= right; ++ i)
	{
		rights += nums[i];
		if(rights > sr) sr = rights;
	}

	int sum = sl + sr;
	if(sum < leftsum) sum = leftsum;
	if(sum < rightsum) sum = rightsum;
	return sum;
}

int maxSubArray(vector<int> &nums)
{
	if(!nums.size()) return 0;

	return MaxSubSum(nums, 0, nums.size() - 1);
}
int maxSubArray2(vector<int> & nums)
{
	if(!nums.size()) return 0;
	int sum = nums[0];
	int b = nums[0];
	for(size_t i = 1; i < nums.size(); ++ i)
	{
		if(b > 0) b += nums[i];
		else	b = nums[i];
		if(b > sum) sum = b;
	}
	return sum;
}
int maxSubArray1(vector<int>& nums) {
	size_t n = nums.size();

	if(!n) return 0;

	vector<int> sum(n, 0);
	sum[0] = nums[0];

	int max = sum[0];
	for(size_t i = 1; i < n; ++i)
	{
		if(sum[i - 1] > 0)
		{
			sum[i] = nums[i] + sum[i - 1];
		}
		else
		{
			sum[i] = nums[i];
		}
		if(sum[i] > max)
			max = sum[i];
	}
	DumpVector(sum);
	return max;
}

void MaxSubArrayTest()
{
	vector<int> vi;
	int ret;

	cout << "test case 1" << endl;
	vi = {};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {-2,1,-3,4,-1,2,1,-5,4};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {-2,1};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vi = {-1};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 5" << endl;
	vi = {2, 3};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vi = {3, -2, 5, -4};
	ret = maxSubArray(vi);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vi = {-2, -1};
	ret = maxSubArray(vi);
	cout << ret << endl;
}

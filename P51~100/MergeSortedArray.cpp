/*
 * MergeSortedArray.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	while(nums1.size() < m + n)
	{
		nums1.push_back(0);
	}

	int curr = m + n - 1;

	while(m > 0 && n > 0)
	{
		if(nums2[n - 1] > nums1[m - 1])
		{
			nums1[curr] = nums2[--n];
		}
		else
		{
			nums1[curr] = nums1[--m];
		}
		curr --;
	}

/*
	while(m > 0)
	{
		nums1[curr--] = nums1[m--];
	}
*/

	while(n > 0)
	{
		nums1[curr--] = nums2[--n];
	}
}

void MergeSortedArrayTest()
{
	vector<int> nums1;
	vector<int> nums2;
	int m;
	int n;

	cout << "test case 1" << endl;
	nums1 = {};
	nums2 = {};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 0);
	DumpVector(nums1);

	cout << "test case 2" << endl;
	nums1 = {1};
	nums2 = {};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 1);
	DumpVector(nums1);

	cout << "test case 3" << endl;
	nums1 = {};
	nums2 = {1};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 1);
	DumpVector(nums1);

	cout << "test case 4" << endl;
	nums1 = {1};
	nums2 = {1};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 2);
	DumpVector(nums1);

	cout << "test case 5" << endl;
	nums1 = {2};
	nums2 = {1, 3};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 3);
	DumpVector(nums1);

	cout << "test case 6" << endl;
	nums1 = {1};
	nums2 = {2, 3};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 3);
	DumpVector(nums1);

	cout << "test case 7" << endl;
	nums1 = {4};
	nums2 = {2, 3};
	m = nums1.size();
	n = nums2.size();
	DumpVector(nums1);
	DumpVector(nums2);
	merge(nums1, m, nums2, n);
	assert(nums1.size() == 3);
	DumpVector(nums1);
}

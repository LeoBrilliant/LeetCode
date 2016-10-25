/*
 * P4.h
 *
 *  Created on: 2016年10月6日
 *      Author: LeoBrilliant
 */

#ifndef P4_H_
#define P4_H_

#include "Common.h"

/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	int left = right = 0;

	int a = nums1[nums1.size() / 2];
	int b = nums2[nums2.size() / 2];

	bool one = (nums1.size() + nums2.size()) % 2 == 1 ? true : false;

	if(a > b)
	{
		left = nums1.size() - nums1.size() / 2 - 1 + nums2.size() - nums2.size() / 2;
		while
	}
}
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> v;
	auto i1 = nums1.begin(), i2 = nums2.begin();
	for(; i1 != nums1.end() && i2 != nums2.end();)
	{
		if(*i1 < *i2)
		{
			v.push_back(*i1++);
		}
		else
		{
			v.push_back(*i2++);
		}
	}
	while(i1 != nums1.end())
		v.push_back(*i1++);
	while(i2 != nums2.end())
		v.push_back(*i2++);

	double ret = 0;

	if(v.size() == 0)
		ret = 0.0;
	else if(v.size() % 2)
		ret = v[v.size() / 2] * 1.0;
	else
		ret = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;

	return ret;
}

void FindMedianSortedArrays()
{
//	vector<int> v1{1, 3};
//	vector<int> v2{2};
	vector<int> v1{1, 2};
	vector<int> v2{3, 4};
	double ret = 0;

	ret = findMedianSortedArrays(v1, v2);

	cout << ret << endl;
}
#endif /* P4_H_ */

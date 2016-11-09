/*
 * RemoveDuplicatesFromSortedArrayII.cpp
 *
 *  Created on: 2016年11月9日
 *      Author: user
 */

#include "P51~100.h"

int removeDuplicates(vector<int>& nums) {

	int n = nums.size();
	if(n <= 1)
		return n;

	int S = 1, I = 1, counter = 0;
	while(S < n)
	{
		int last = nums[I - 1];
		if(nums[S] == last)
		{
			counter ++;
			if(counter == 1)
			{
				nums[I++] = nums[S];
			}
		}
		else
		{
			nums[I++] = nums[S];
			counter = 0;
		}
		S++;
	}
	return I;
}

void RemoveDuplicatesTest()
{
	vector<int> vi;
	int ret;

	cout << "test case 1" << endl;
	vi = {};
	ret = removeDuplicates(vi);
	assert(ret == 0);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 2" << endl;
	vi = {1};
	ret = removeDuplicates(vi);
	assert(ret == 1);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 3" << endl;
	vi = {1, 1};
	ret = removeDuplicates(vi);
	assert(ret == 2);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 4" << endl;
	vi = {1, 1, 1};
	ret = removeDuplicates(vi);
	assert(ret == 2);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 5" << endl;
	vi = {1, 1, 1, 1};
	ret = removeDuplicates(vi);
	assert(ret == 2);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 6" << endl;
	vi = {1, 1, 1, 1, 2};
	ret = removeDuplicates(vi);
	assert(ret == 3);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 7" << endl;
	vi = {1, 1, 1, 1, 2, 2};
	ret = removeDuplicates(vi);
	assert(ret == 4);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 9" << endl;
	vi = {1, 1, 1, 1, 2, 2, 2};
	ret = removeDuplicates(vi);
	assert(ret == 4);
	cout << ret << endl;
	DumpVector(vi);

	cout << "test case 10" << endl;
	vi = {1,1,1,2,2,3};
	ret = removeDuplicates(vi);
	assert(ret == 5);
	cout << ret << endl;
	DumpVector(vi);
}


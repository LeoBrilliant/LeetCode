/*
 * JumpGame.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */


#include "P51~100.h"


bool canJump(vector<int>& nums) {

	int n = nums.size();
	if(n <= 1) return true;

	bool ret = false;
	//vector<int> s(n, 0);
	int max = 0;
	for(int i = 0; i <= max; ++i)
	{
		if(i + nums[i] > max)
			max = nums[i] + i;

		if(i == max && nums[i] == 0)
			break;

		if(max >= n - 1)
		{
			ret = true;
			break;
		}
	}
	return ret;
}

void CanJumpTest()
{
	vector<int> vi;
	bool ret;

	cout << "test case 1" << endl;
	vi = {2,3,1,1,4};
	ret = canJump(vi);
	assert(ret);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {3,2,1,0,4};
	ret = canJump(vi);
	assert(!ret);
	cout << ret << endl;
}

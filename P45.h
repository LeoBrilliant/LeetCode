/*
 * P45.h
 *
 *  Created on: 2016年10月20日
 *      Author: user
 */

#ifndef P45_H_
#define P45_H_

#include "Common.h"


// 动态规划的解法
// 结果应该没问题，超时。原因是为了寻找全局最优，有很多的不必要计算
int jump2(vector<int>& nums) {

	vector<int> s(nums.size(), -1);
	vector<int> move(nums.size(), -1);
	int n = nums.size() - 1;

	s[n] = 0;
	move[n] = 0;

	for(int i = n - 1; i >= 0; -- i)
	{
		int min = -1;
		for(int d = 0; d <= nums[i] && d + i < n; ++d)
		{
			if(i + nums[i] >= n)
			{
				min = 1;
				move[i] = n - i;
				break;
			}
			if(s[i + d] != -1)
			{
				int step = 1 + s[i + d];
				if(min == -1)
				{
					min = step;
					move[i] = d;
				}
				else
				{
					min = min <= step ? min : step;
					move[i] = min == step? d : move[i];
				}
			}
		}

		s[i] = min;
	}

	//DumpVector(s);
	//DumpVector(move);
	return s[0];
}

//贪心算法加剪枝
int jump(vector<int>& nums) {

	if(nums.size() == 1)
		return 0;

	vector<int> s(nums.size(), -1);
	vector<int> move(nums.size(), -1);
	int n = nums.size() - 1;

	s[0] = 0;
	move[0] = 0;

	int max = 0;
	for(int i = 0; i <= n; ++ i)
	{
		for(int d = i; d <= i + nums[i] && d <= n; ++d)
		{
			if(s[d] == -1)
			{
				s[d] = s[i] + 1;
				move[d] = i;
			}
			else
			{
				if(s[d] > s[i] + 1)
				{
					s[d] = s[i] + 1;
					move[d] = i;
				}
			}
			if(d + nums[d] > max)
			{
				max = d + nums[d];

				if(max >= n)
				{
					s[n] = s[d] + 1;
					move[n] = d;
					break;
				}
				else
				{
					s[max] = s[d] + 1;
					move[max] = d;
				}
			}
			else
				continue;
		}
		if(s[n] != -1)
			break;
	}

	DumpVector(s);
	DumpVector(move);
	return s[n];
}

void JumpTest()
{
	vector<int> vi;

	vi = {2,3,1,1,4};

	vi = {1, 1, 0, 1};

	vi = {4, 3, 2, 1, 0};

	vi = {1, 1, 1, 1};

	vi = {1};

	vi = {2, 1};

	vi = { 4, 2, 1};

	vi = {1, 1, 1, 1};
	vi = {1, 1, 1, 1, 1};
//	vi = {};
//	for(int i = 25000; i > 0; --i)
//		vi.push_back(i);
//	vi.push_back(1);
//	vi.push_back(0);

	int ret = jump(vi);

	cout << ret << endl;
}

#endif /* P45_H_ */

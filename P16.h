/*
 * P16.h
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#ifndef P16_H_
#define P16_H_

#include "Common.h"

int threeSumClosest(vector<int>& nums, int target) {
	int retvalue = 0;
	vector<vector<int>> ret;
	if(!nums.size()) return retvalue;

	sort(nums.begin(), nums.end());

	int max = -1;
	int distance = 0;
	for(size_t i = 0; i < nums.size() - 1;)
	{
		for(size_t j = i + 1, k = nums.size() - 1; j < k; )
		{
			int value = nums[i] + nums[j] + nums[k];
			distance = abs(value - target);

			if(max == -1 || distance < max)
			{
				max = distance;
				retvalue = value;
				vector<int> vi{nums[i], nums[j], nums[k]};

				if(!ret.empty())
					ret.pop_back();

				ret.push_back(vi);
				//break;
				//k--; j++;
				//while(k < nums.size() && k > j && nums[k] == nums[k + 1])
				//  k --;
				//while(j < k && nums[j] == nums[j - 1])
				//	j ++;
			}

			if(value > target)
			{
				k --;
				while(k < nums.size() && k > j && nums[k] == nums[k + 1])
					k --;
			}
			else if(value < target)
			{
				j ++;
				while(j < k && nums[j] == nums[j - 1])
					j ++;
			}
			else
			{
				return retvalue;
			}
		}
		++i;
		if(nums[i] != nums[i - 1])
			continue;
		while(i < nums.size() && nums[i] == nums[i - 1])
			i ++;
	}
	return retvalue;
}


void ThreeSumClosestTest()
{
	vector<int> vi{-1, 2, 1, -4};
	int target = 1;

	int ret = threeSumClosest(vi, target);

	cout << ret << endl;
}

#endif /* P16_H_ */

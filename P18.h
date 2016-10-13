/*
 * P18.h
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#ifndef P18_H_
#define P18_H_

#include "Common.h"

vector<vector<int>> fourSum(vector<int>& nums, int target) {
   	vector<vector<int>> ret;
	if(nums.size() < 4) return ret;

	sort(nums.begin(), nums.end());

	for(size_t i = 0; i < nums.size() - 1;)
	{
		for(size_t j = i + 1; j < nums.size(); )
		{
			for(size_t l = j + 1, r = nums.size() - 1; l < r; )
			{
				int value = nums[i] + nums[j] + nums[l] + nums[r];
				if(value > target)
				{
					r --;
					while(r < nums.size() && r > l && nums[r] == nums[r + 1])
						r --;
				}
				else if(value < target)
				{
					l ++;
					while(l < r && nums[l] == nums[l - 1])
						l ++;
				}
				else
				{
					vector<int> vi{nums[i], nums[j], nums[l], nums[r]};
					ret.push_back(vi);
					//break;
					r--; l++;
					while(r < nums.size() && r > l && nums[r] == nums[r + 1])
						r --;
					while(l < r && nums[l] == nums[l - 1])
						l ++;
				}
			}
			++j;
			if(nums[j] != nums[j - 1])
				continue;
			while(j < nums.size() && nums[j] == nums[j - 1])
				j ++;
		}
		++i;
		if(nums[i] != nums[i - 1])
			continue;
		while(i < nums.size() && nums[i] == nums[i - 1])
			i ++;
	}
	return ret;
}

void FourSumTest()
{
	vector<int> vi{1, 0, -1, 0, -2, 2};

	vi = {};

	int target = 0;

	vector<vector<int>> result;

	result = fourSum(vi, target);

	for(auto &p : result)
	{
		cout << "[ ";
		for(auto &q : p)
		{
			cout << q << ",";
		}
		cout << "] " << endl;
	}
}


#endif /* P18_H_ */

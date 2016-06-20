/*
 * Solution.h
 *
 *  Created on: 2016Äê6ÔÂ20ÈÕ
 *      Author: user
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_


#include <vector>
#include <map>
#include <assert.h>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		int index1, index2;
		for(int i = 0; i < nums.size(); ++i)
		{
			for(int j = i + 1; j < nums.size(); ++ j)
			{
				if(nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}

	void twoSumTest()
	{
		int array[] = {2, 7, 11, 15};

		vector<int>  nums(array);

		int target = 9;

		vector<int> result = this->twoSum(nums, target);

		assert(result[0] == 0);
		assert(result[1] == 1);
	}
};



#endif /* SOLUTION_H_ */

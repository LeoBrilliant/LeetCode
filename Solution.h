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
		map<int, int> buffer;
		vector<int> result;
		for(int i = 0; i < nums.size(); ++i)
		{
			buffer[nums[i]] = i;
		}

		for(int i = 0; i < nums.size(); ++i)
		{
			if(buffer.find(target - nums[i]) != buffer.end() && buffer[target - nums[i]] != i)
			{
				result.push_back(i);
				result.push_back(buffer[target - nums[i]]);
				break;
			}
		}
		return result;
	}

	void twoSumTest()
	{
		//vector<int>  nums {2, 7, 11, 15};
		vector<int> nums {3,2,4};
		int target = 6;

		vector<int> result = this->twoSum(nums, target);

		for(auto & p : result)
			cout << p << ", ";
		cout << endl;

		assert(result.size() == 2);
		assert(result[0] == 1);
		assert(result[1] == 2);



		std::cout << "Hello" << std::endl;
	}
};



#endif /* SOLUTION_H_ */

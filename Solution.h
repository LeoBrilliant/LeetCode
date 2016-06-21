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
#include <memory.h>
#include <string>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> result;
		unsigned char bitSign = 0x80;
		int index1, index2;
		int a;
		char loc, mask;
		int max, min;
		max = min = nums[0];
		for(unsigned int i = 1; i < nums.size(); ++i)
		{
			if(max < nums[i])
				max = nums[i];
			if(min > nums[i])
				min = nums[i];
		}

		int range = max - min;
		char * hashTable = new char[range / 8 + 1];
		memset(hashTable, 0, range / 8 + 1);

		for(unsigned int i = 0; i < nums.size(); ++i)
		{

			a = (target - nums[i]) - min;
			//assert(a >= 0);
			if(a < 0)
				continue;
			loc = hashTable[ (a) / 8];
			mask = (bitSign >> a % 8);
			if((loc &  mask) != 0)
			{
				index2 = i;
				break;
			}

			mask = (bitSign >> (nums[i] - min) % 8);
			loc |= mask;
			hashTable[ (nums[i] - min) / 8] |= mask;
		}

		a += min;
		for(unsigned int i = 0; i < nums.size(); ++ i)
		{
			if(nums[i] == a)
			{
				index1 = i;
				break;
			}
		}


		result.push_back(index1);
		result.push_back(index2);
		return result;
	}

	void twoSumTest()
	{
		vector<int>  nums {2, 7, 11, 15};
		//vector<int> nums {3,2,4};
		//vector<int> nums {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
		int target = 9;

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

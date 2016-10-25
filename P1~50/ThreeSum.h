/*
 * ThreeSum.h
 *
 *  Created on: 2016��6��24��
 *      Author: user
 */

#ifndef THREESUM_H_
#define THREESUM_H_

#include "Common.h"


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<int>::iterator iter= nums.begin();
    	vector<int> result;
    	vector<vector<int>> collection;
    	vector<vector<int>> ret;

    	multiset<int> order;
    	set<multiset<int>> uni;
    	Process(nums, iter, 0, result, collection);

    	for(auto & p : collection)
    	{
    		for(auto &q : p)
    		{
    			order.insert(q);
    		}
    		if(uni.find(order) == uni.end())
    		{
    			uni.insert(order);

    		}
    		order.clear();
    	}

    	for(auto &p: uni)
    	{
    		vector<int> tmp;
    		for(auto &q : p)
    		{
    			tmp.push_back(q);
    		}
    		if(tmp.size() == 3)
    		ret.push_back(tmp);
    	}
    	return ret;
    }

    void Process(vector<int>& nums, vector<int>::iterator iter, int sum, vector<int>& result, vector<vector<int>>& collection)
    {
    	if(result.size() > 3)
    		return;
    	if(result.size() == 3 && sum == 0)
    	{
    		//result.sort();

    		//if(collection.find(result) == collection.end())
    		{
    			//collection.insert(result);
    		}
    		collection.push_back(result);
    		return;
    	}

    	if(iter == nums.end())
    		return;

    	for(vector<int>::iterator i = iter; i != nums.end(); ++i)
    	{
    		result.push_back(*i);
    		Process(nums, i + 1, sum - *i, result, collection);
    		result.pop_back();
    	}
    }

    vector<vector<int>> threeSum2(vector<int>& nums) {

		vector<int>::iterator iter= nums.begin();
		vector<int>::iterator i, j, k;
		vector<int> result;
		vector<vector<int>> collection;
		vector<vector<int>> ret;

		multiset<int> order;
		set<multiset<int>> uni;

		int sum;
        for(i = iter; i != nums.end(); ++i)
        {
        	for(j = i+1; j != nums.end(); ++j)
        	{
        		for(k = j + 1; k != nums.end(); ++k)
        		{
        			sum = *i + *j + *k;
        			if(sum == 0)
        			{
        				order.insert(*i);
        				order.insert(*j);
        				order.insert(*k);
        				if(uni.find(order) == uni.end())
        				{
        					uni.insert(order);
        				}
        				order.clear();
        			}
        		}
        	}
        }

        for(auto &p: uni)
		{
			vector<int> tmp;
			for(auto &q : p)
			{
				tmp.push_back(q);
			}
			if(tmp.size() == 3)
			ret.push_back(tmp);
		}
		return ret;

    }
    vector<vector<int>> threeSum3(vector<int>& nums)
	{
    	vector<vector<int>> ret;
    	if(!nums.size()) return ret;

    	sort(nums.begin(), nums.end());

    	for(size_t i = 0; i < nums.size() - 1;)
    	{
    		for(size_t j = i + 1, k = nums.size() - 1; j < k; )
    		{
    			int value = nums[i] + nums[j] + nums[k];
    			if(value > 0)
    			{
    				k --;
        			while(k < nums.size() && k > j && nums[k] == nums[k + 1])
        			    k --;
    			}
    			else if(value < 0)
    			{
    				j ++;
        			while(j < k && nums[j] == nums[j - 1])
        				j ++;
    			}
    			else
    			{
    				vector<int> vi{nums[i], nums[j], nums[k]};
    				ret.push_back(vi);
    				//break;
    				k--; j++;
        			while(k < nums.size() && k > j && nums[k] == nums[k + 1])
        			    k --;
        			while(j < k && nums[j] == nums[j - 1])
        				j ++;
    			}
    		}
    		++i;
    		if(nums[i] != nums[i - 1])
    			continue;
    		while(i < nums.size() && nums[i] == nums[i - 1])
    		    i ++;
    	}
    	return ret;
	}

    void test()
    {
    	//vector<int> nums {-1, 0, 1, 2, -1, -4};
    	//vector<int> nums {0, 0, 0};

    	//vector<int> nums {0, 0,1,2,-1,0};
    	//vector<int> nums {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    	//vector<int> nums {0,7,-4,-7,0,14,-6,-4,-12,11,4,9,7,4,-10,8,10,5,4,14,6,0,-9,5,6,6,-11,1,-8,-1,2,-1,13,5,-1,-2,4,9,9,-1,-3,-1,-7,11,10,-2,-4,5,10,-15,-4,-6,-8,2,14,13,-7,11,-9,-8,-13,0,-1,-15,-10,13,-2,1,-1,-15,7,3,-9,7,-1,-14,-10,2,6,8,-6,-12,-13,1,-3,8,-9,-2,4,-2,-3,6,5,11,6,11,10,12,-11,-14};
    	//vector<int> nums;
    	vector<int> nums{-2,0,0,2,2};
    	vector<vector<int>> result;

    	result = threeSum3(nums);

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
};


#endif /* THREESUM_H_ */

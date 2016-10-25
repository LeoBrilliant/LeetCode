/*
 * RemoveElement.h
 *
 *  Created on: 2016年6月23日
 *      Author: user
 */

#ifndef REMOVEELEMENT_H_
#define REMOVEELEMENT_H_

#include "CommonHeaders.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

    	vector<int>::iterator iter = nums.begin();
    	vector<int>::iterator index = iter+1;
    	int counter = 0;
    	int temp = 0;
    	while(iter != nums.end())
    	{
    		if(*iter == val)
    		{
    			if(index <= iter)
    				index = iter + 1;
    			while(index != nums.end())
    			{
    				if(*index != val)
    				{
    					temp = *index;
    					*index = *iter;
    					*iter = temp;
    					index ++;
    					break;
    				}
    				index ++;
    			}
    			//nums.erase(iter);
    		}
    		iter++;
    	}
    	iter = nums.begin();
    	while(iter != nums.end())
    	{
    		if(*iter == val)
    			counter ++;
    		++iter;
    	}

    	return nums.size() - counter;
    }

    //已经没法通过Judge了。
    int removeElement2(vector<int>& nums, int val) {

		vector<int>::iterator iter = nums.begin();
		vector<int>::iterator index = nums.begin();
		int counter = 0;
		while(iter != nums.end())
		{
			if(*iter == val)
			{
				iter++;
				continue;
			}
			*index = *iter;
			index ++ , iter ++;
			counter++;
		}
		return nums.size() - counter;
    }
    void removeElementTest()
    {
    	vector<int> nums1 {2, 3, 7, 3, 9, 0};
    	//vector<int> nums1 {3, 2, 2, 3};
    	//vector<int> nums1 {1};
    	int val = 3;
    	int len = 0;
    	int result = 0;
		vector<int> nums2 {1}; //, 3, 6, 0, 2, 4


		//vector<int> nums {3,2,4};
		//vector<int> nums {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};

		for(auto &p : nums1)
		{
			cout << p << "->";
		}
		cout << endl;

		len = nums1.size();
		result = this->removeElement(nums1, val);

		for(auto &p : nums1)
		{
			cout << p << "->";
		}
		cout << endl;
		assert(len - 1 == result);
    }
};



#endif /* REMOVEELEMENT_H_ */

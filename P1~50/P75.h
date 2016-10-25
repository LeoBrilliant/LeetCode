/*
 * P75.h
 *
 *  Created on: 2016年10月3日
 *      Author: LeoBrilliant
 */

#ifndef P75_H_
#define P75_H_

#include <iostream>

using namespace std;

void sortColors(vector<int> & nums)
{
	//vector<int> vi(nums.size(), 0);

	int one, two, three, index;
	one = two = three = index = 0;
	for(auto i : nums)
	{
		switch(i)
		{
		case 0:
			one++;
			break;
		case 1:
			two++;
			break;
		case 2:
			three++;
			break;
		}
	}

	for(auto i = 0 ; i < nums.size(); ++i)
	{
		if(i < one)
			nums[i] = 0;
		else if(i >= one && i < (one + two))
		{
			nums[i] = 1;
		}
		else
			nums[i] = 2;
	}
}



#endif /* P75_H_ */

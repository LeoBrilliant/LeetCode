/*
 * P42.h
 *
 *  Created on: 2016年10月20日
 *      Author: LeoBrilliant
 */

#ifndef P42_H_
#define P42_H_


#include "Common.h"

int trap(vector<int>& height) {

	if(!height.size())
		return 0;

	stack<pair<int, int>> t;

	bool desc = true;


	int left = 0, right = height.size() - 1;

	// 寻找第一个递减序列的左边界
	for(left = 0; left < height.size() - 1 ; ++left)
	{
		if(height[left] > height[left + 1])
		{
			break;
		}
	}

	if(left == height.size() - 1)
		return 0;

	// 寻找最后一个递增序列的右边界
	for(right = height.size() - 1; right >= left; --right)
	{
		if(height[right] > height[right - 1])
		{
			break;
		}
	}

	if(right <= left + 1)
		return 0;

	int currleft = left, currright = right;
	int maxleft = left;
	for(int i = left; i <= right; ++i)
	{
		if(desc)
		{
			if(height[i] > height[currleft])
				currleft = i;
			if(height[i] < height[i + 1])
			{
				desc = false;
			}
		}
		else
		{
			if(i == right || height[i] > height[i + 1])
			{
				currright = i;

				if(t.empty())
				{
					t.push(make_pair(currleft, currright));
					maxleft = currleft;
					if(height[currright] > height[maxleft])
					{
						maxleft = currright;
					}
				}
				else
				{
					if(height[currright] > height[currleft] && height[maxleft] > height[currleft])
					{
						pair<int, int> pi;
						while(t.size() && height[t.top().first] >= height[t.top().second] && height[t.top().second] <= height[currright])
						{
							pi = t.top();
							t.pop();
						}
						t.push(make_pair(pi.first, currright));
					}
					else
					{
						t.push(make_pair(currleft, currright));
					}

					if(height[currright] > height[maxleft])
					{
						maxleft = currright;
					}
				}

				currleft = currright;
				desc = true;
			}
		}
	}

	int ret = 0;
	int debug = t.size();
	while(t.size())
	{
		pair<int, int> index = t.top();
		int watermark = min(height[index.first], height[index.second]);
		for(int i = index.first; i <= index.second; ++i)
		{
			if(watermark > height[i])
				ret += watermark - height[i];
		}
		t.pop();
	}

	return ret;
}

void TrapTest()
{
	vector<int> vi;
	vi = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6

	vi = {0, 3, 1, 2, 1, 0, 1, 3, 0}; // 10

	//vi = {2, 0, 2}; // 2

	//vi = {8,9,3,6,9,6,8,0,7,6,8,1}; // 22

	int ret = trap(vi);

	cout << ret << endl;
}
#endif /* P42_H_ */

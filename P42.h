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

	stack<pair<int, int>> t;

	bool desc = true;


	int left = 0, right = height.size() - 1;

	for(left = 0; left < height.size() - 1 ; ++left)
	{
		if(height[left] > height[left + 1])
		{
			break;
		}
	}

	if(left == height.size() - 1)
		return 0;

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
	int maxleft = height[left], maxright = height[right];
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
			if(height[i] > height[i + 1])
			{
				currright = i;

				if(t.empty())
				{
					t.push(make_pair(currleft, currright));
					maxleft = currleft;
					maxright = right;
				}
				else
				{
					if(height[currright] > height[currleft] && height[maxleft] > height[currleft])
					{
						while(t.top().first != maxleft && height[t.top().second] <= height[currright])
							t.pop();

						pair<int, int> pi = t.top();
						t.pop();
						t.push(make_pair(pi.first, currright));
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
	vi = {0,1,0,2,1,0,1,3,2,1,2,1};

	int ret = trap(vi);

	cout << ret << endl;
}
#endif /* P42_H_ */

/*
 * LargestRectangleInHistogram.cpp
 *
 *  Created on: 2016年10月27日
 *      Author: user
 */

#include "P51~100.h"

// TLE
int largestRectangleArea(vector<int>& heights) {
	pair<int, int> curr;
	vector<pair<int, int>> rect;
	int minheight = 0, maxarea = 0;

	for(size_t i = 0; i < heights.size(); ++i)
	{
		curr.first = heights[i];
		curr.second = 1;
		if(rect.empty())
		{
			rect.push_back(curr);
			minheight = curr.first;
			maxarea = curr.first * curr.second;
		}
		else
		{
			minheight = heights[i];
			int area2 = 0;
			for(int j = i; j >= 0; --j)
			{
				if(heights[j] < minheight)
					minheight = heights[j];
				int area1 = minheight * (i - j + 1);
				if(area2 < area1)
				{
					area2 = area1;
				}
			}

			if(area2 > maxarea)
			{
				maxarea = area2;
			}
			/*
			int h = (curr.first < rect[i - 1].first ? curr.first : rect[i - 1].first);
			int w = rect[i - 1].second + 1;
			int area2 = h * w;
			minheight = (minheight < curr.first ? minheight : curr.first);
			int area3 = minheight * (i + 1);

			if(area1 < area2)
			{
				curr.first = h;
				curr.second = w;
			}
			else if(area1 < area3)
			{
				curr.first = minheight;
				curr.second = i + 1;
			}

			area1 = curr.first * curr.second;
			maxarea = (maxarea > area1 ? maxarea : area1);
			rect.push_back(curr);
			*/
		}
	}
	return maxarea;
}

void LargestRectangleAreaTest()
{
	vector<int> vi;
	int ret;

	cout << "test case 1" << endl;
	vi = {};
	ret = largestRectangleArea(vi);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {4};
	ret = largestRectangleArea(vi);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {2,1,5,6,2,3};
	ret = largestRectangleArea(vi);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {1, 2, 3, 4, 5};
	ret = largestRectangleArea(vi);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vi = {};
	for(int i = 0; i < 20000; ++i)
		vi.push_back(i);
	ret = largestRectangleArea(vi);
	cout << ret << endl;
}

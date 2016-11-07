/*
 * MaximalRectangle.cpp
 *
 *  Created on: 2016年11月7日
 *      Author: user
 */

#include "P51~100.h"

static int largestRectangleArea(vector<int>& heights)
{
	int ret  = 0;
	stack<int> si;
	for(int i = 0; i < heights.size(); ++i)
	{
		while(!si.empty() && heights[si.top()] >= heights[i])
		{
			int h = heights[si.top()];
			si.pop();

			int area = h * (si.empty() ? i : (i - si.top() - 1));
			ret = max(ret, area);
		}

		si.push(i);
	}

	while(!si.empty())
	{
		int h = heights[si.top()];
		si.pop();
		int area = h * (si.empty() ? heights.size() : (heights.size() - si.top() - 1));
		ret = max(ret, area);
	}

	return ret;
}

int maximalRectangle(vector<vector<char>>& matrix) {

	if(matrix.size() == 0)
		return 0;

	vector<int> height(matrix[0].size(), 0);
	int maxarea = 0;
	for(int i = 0; i < matrix.size(); ++i)
	{
		for(int j = 0; j < matrix[0].size(); ++j)
		{
			if(matrix[i][j] == '1')
			{
				height[j] += 1;
			}
			else
			{
				height[j] = 0;
			}
		}

		int curr = largestRectangleArea(height);
		if(curr > maxarea)
			maxarea = curr;
	}

	return maxarea;
}

void MaximalRectangleTest()
{
	vector<vector<char>> vvc;
	vector<string> vs;
	int ret;

	cout << "test case 1" << endl;
	ret = maximalRectangle(vvc);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vs = {"10100","10111","11111","10010"};
	VectorStringToVectorOfVectorOfChar(vs, vvc);
	DumpVectorOfVector(vvc);
	ret = maximalRectangle(vvc);
	cout << ret << endl;
}





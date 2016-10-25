/*
 * SpiralMatrix.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

vector<int> spiralOrder(vector<vector<int>>& matrix) {

	pair<int, int> topleft, topright, bottomleft, bottomright;

	int w = matrix.size();
	vector<int> ret;
	if(!w) return ret;
	int h = matrix[0].size();
	int count = 0;
	topleft = make_pair(0, 0);
	topright = make_pair(0, h - 1);
	bottomleft = make_pair(w - 1, 0);
	bottomright = make_pair(w - 1, h - 1);

	while(topleft.second <= topright.second && topleft.first <= bottomleft.first)
	{
		int x, y;
		// top side
		for(x = topleft.first, y = topleft.second; y < topright.second && count < w * h; ++ y)
		{
			ret.push_back(matrix[x][y]);
			count ++;
		}
		if(topleft.second == topright.second && bottomleft.first == topleft.first)
		{
			ret.push_back(matrix[x][y]);
			count ++;
			break;
		}
		// right side
		for(x = topright.first, y = topright.second; x < bottomright.first && count < w * h; ++x)
		{
			ret.push_back(matrix[x][y]);
			count ++;
		}
		if(topleft.second == bottomright.second)
		{
			ret.push_back(matrix[x][y]);
			count ++;
			break;
		}
		// bottom side
		for(x = bottomright.first, y = bottomright.second; y > bottomleft.second && count < w * h; --y)
		{
			count ++;
			ret.push_back(matrix[x][y]);
		}
		// left side
		for(x = bottomleft.first, y = bottomleft.second; x > topleft.first && count < w * h; --x)
		{
			count ++;
			ret.push_back(matrix[x][y]);
		}

		topleft.first++, topleft.second++;
		topright.first++, topright.second--;
		bottomleft.first--, bottomleft.second++;
		bottomright.first--, bottomright.second--;
	}
	return ret;
}

void SpiralOrderTest()
{
	vector<vector<int>> vvi;
	vector<int> ret;

	cout << "test case 1" << endl;
	vvi = {{ 1, 2, 3 },
			{ 4, 5, 6 },
			{ 7, 8, 9 }};

	ret = spiralOrder(vvi);
	DumpVector(ret);

	cout << "test case 2" << endl;
	vvi = {{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12},
			{13, 14, 15, 16}
	};

	ret = spiralOrder(vvi);
	DumpVector(ret);

	cout << "test case 3" << endl;
	vvi = {{1}};
	ret = spiralOrder(vvi);
	DumpVector(ret);

	cout << "test case 4" << endl;
	vvi = {{1, 2}};
	ret = spiralOrder(vvi);
	DumpVector(ret);

	cout << "test case 5" << endl;
	vvi = {{1}, {2}};
	ret = spiralOrder(vvi);
	DumpVector(ret);

	cout << "test case 5" << endl;
	vvi = {{6, 9, 7}};
	ret = spiralOrder(vvi);
	DumpVector(ret);
}


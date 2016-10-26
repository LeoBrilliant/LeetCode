/*
 * SpiralMatrixII.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "P51~100.h"

vector<vector<int>> generateMatrix(int n) {
	pair<int, int> topleft, topright, bottomleft, bottomright;

	int w = n;
	vector<vector<int>> matrix;
	if(!w) return matrix;
	int h = n;

	vector<int> vi(n, 0);
	for(int i = 0; i < n; ++i)
	{
		matrix.push_back(vi);
	}

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
			//ret.push_back(matrix[x][y]);
			matrix[x][y] = ++count;
		}
		if(topleft.second == topright.second && bottomleft.first == topleft.first)
		{
			//ret.push_back(matrix[x][y]);
			matrix[x][y] = ++count;
			break;
		}
		// right side
		for(x = topright.first, y = topright.second; x < bottomright.first && count < w * h; ++x)
		{
			matrix[x][y] = ++count;
		}
		if(topleft.second == bottomright.second)
		{
			matrix[x][y] = ++count;
			break;
		}
		// bottom side
		for(x = bottomright.first, y = bottomright.second; y > bottomleft.second && count < w * h; --y)
		{
			matrix[x][y] = ++count;
		}
		// left side
		for(x = bottomleft.first, y = bottomleft.second; x > topleft.first && count < w * h; --x)
		{
			matrix[x][y] = ++count;
		}

		topleft.first++, topleft.second++;
		topright.first++, topright.second--;
		bottomleft.first--, bottomleft.second++;
		bottomright.first--, bottomright.second--;
	}
	return matrix;
}

void GenerateMatrixTest()
{
	vector<vector<int>> vvi;
	int n;

	cout << "test case 1" << endl;
	n = 1;
	vvi = generateMatrix(n);
	DumpVectorOfVector(vvi);

	cout << "test case 2" << endl;
	n = 2;
	vvi = generateMatrix(n);
	DumpVectorOfVector(vvi);

	cout << "test case 3" << endl;
	n = 3;
	vvi = generateMatrix(n);
	DumpVectorOfVector(vvi);

	cout << "test case 4" << endl;
	n = 4;
	vvi = generateMatrix(n);
	DumpVectorOfVector(vvi);
}



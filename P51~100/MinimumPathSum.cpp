/*
 * MinimumPathSum.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	if(m == 0)
		return 0;

	int n = grid[0].size();
	if(n == 0)
		return 0;

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i == 0 && j == 0)
				continue;

			if(j == 0 && i != 0)
			{
				grid[i][j] += grid[i - 1][j];
			}
			else if(j != 0 && i == 0)
			{
				grid[i][j] += grid[i][j - 1];
			}
			else if(j != 0 && i != 0)
			{
				grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
			}
		}
	}

	DumpVectorOfVector(grid);

	return grid[m - 1][n - 1];
}

void MinPathSumTest()
{
	vector<vector<int>> vvi;
	int ret;

	cout << "test case 1" << endl;
	vvi = {};
	ret = minPathSum(vvi);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vvi = {{0,0,0},
			  {0,1,0},
			  {0,0,0}};
	ret = minPathSum(vvi);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vvi = {{1,2,3},
			  {4,5,6},
			  {7,8,9}};
	ret = minPathSum(vvi);
	assert(ret == 21);
	cout << ret << endl;
}

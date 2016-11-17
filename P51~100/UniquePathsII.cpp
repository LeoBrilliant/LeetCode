/*
 * UniquePathsII.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	if(m == 0)
		return 0;

	int n = obstacleGrid[0].size();
	if(n == 0)
		return 0;

	if(obstacleGrid[0][0] == 1)
		return 0;

	obstacleGrid[0][0] = 1;
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i == 0 && j == 0)
				continue;

			if(obstacleGrid[i][j] != 1)
			{
				if(j == 0 && i != 0)
				{
					obstacleGrid[i][j] = obstacleGrid[i - 1][j];
				}
				else if(j != 0 && i == 0)
				{
					obstacleGrid[i][j] = obstacleGrid[i][j - 1];
				}
				else if(j != 0 && i != 0)
				{
					obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
				}
			}
			else
			{
				obstacleGrid[i][j] = 0;
			}
		}
	}

	DumpVectorOfVector(obstacleGrid);

	return obstacleGrid[m - 1][n - 1];
}

void UniquePathsIITest()
{
	vector<vector<int>> vvi;
	int ret;

	cout << "test case 1" << endl;
	vvi = {};
	ret = uniquePathsWithObstacles(vvi);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vvi = {{0,0,0},
			  {0,1,0},
			  {0,0,0}};
	ret = uniquePathsWithObstacles(vvi);
	assert(ret == 2);
	cout << ret << endl;

}

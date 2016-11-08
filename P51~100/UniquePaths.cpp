/*
 * UniquePaths.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

int uniquePathsA(int m, int n) {
	if(m == 0 || n == 0)
		return 0;
	vector<int> row(n, 0);
	vector<vector<int>> board;
	for(int i = 0; i < m; ++i)
	{
		board.push_back(row);
	}

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i == 0 && j == 0)
			{
				board[i][j] = 1;
			}
			else if((j == 0 && i != 0) || (j != 0 && i == 0))
			{
				board[i][j] = 1;
			}
			else
			{
				board[i][j] = board[i - 1][j] + board[i][j - 1];
			}
		}
	}

	return board[m - 1][n - 1];
}

int gcd(int a, int b)
{
	int temp;
	while(b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int uniquePaths(int m, int n)
{
	if(m == 0 || n == 0)
		return 0;

	if(m == 1 || n == 1)
		return 1;

	if(m > n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}

	long long dividend = 1;
	long long divisor = 1;
	for(int i = m - 1; i > 0; --i)
	{
		int common = gcd(dividend, divisor);
		if(common != 1)
		{
			dividend /= common;
			divisor /= common;
		}

		dividend *= n++;
		divisor *= (m-- - 1);

		common = gcd(dividend, divisor);
		if(common != 1)
		{
			dividend /= common;
			divisor /= common;
		}
	}

	return dividend / divisor;
}

void UniquePathsTest()
{
	int m;
	int n;
	int ret;

	cout << "test case 1" << endl;
	m = 0;
	n = 0;
	ret = uniquePaths(m, n);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	m = 3;
	n = 7;
	ret = uniquePaths(m, n);
	assert(ret == 28);
	cout << ret << endl;

	cout << "test case 3" << endl;
	m = 7;
	n = 3;
	ret = uniquePaths(m, n);
	assert(ret == 28);
	cout << ret << endl;

	cout << "test case 4" << endl;
	m = 4;
	n = 5;
	ret = uniquePaths(m, n);
	assert(ret == 35);
	cout << ret << endl;

	cout << "test case 5" << endl;
	m = 5;
	n = 5;
	ret = uniquePaths(m, n);
	assert(ret == 70);
	cout << ret << endl;

	cout << "test case 6" << endl;
	m = 1;
	n = 5;
	ret = uniquePaths(m, n);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 7" << endl;
	m = 1;
	n = 1;
	ret = uniquePaths(m, n);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 8" << endl;
	m = 51;
	n = 9;
	ret = uniquePaths(m, n);
	assert(ret == 1916797311);
	cout << ret << endl;
}



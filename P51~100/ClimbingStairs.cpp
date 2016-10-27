/*
 * ClimbingStairs.cpp
 *
 *  Created on: 2016年10月27日
 *      Author: user
 */

#include "P51~100.h"

// TLE
int AclimbStairs(int n) {

	if(n <= 1)
		return 1;
	if(n < 0)
		return 0;
	return AclimbStairs(n - 1) + AclimbStairs(n - 2);
}

int climbStairs(int n) {

	if(n <= 1)
		return 1;
	if(n < 0)
		return 0;

	int i = 1, j = 1;
	int ret = 0;
	for(int m = 2; m <= n; ++m)
	{
		ret = i + j;
		i = j;
		j = ret;
	}
	return ret;
}

void ClimbStairsTest()
{
	int n;
	int ret;

	cout << "test case 1" << endl;
	n = 0;
	ret = climbStairs(n);
	cout << ret << endl;

	cout << "test case 2" << endl;
	n = 1;
	ret = climbStairs(n);
	cout << ret << endl;

	cout << "test case 3" << endl;
	n = 2;
	ret = climbStairs(n);
	cout << ret << endl;

	cout << "test case 4" << endl;
	n = 3;
	ret = climbStairs(n);
	cout << ret << endl;

	cout << "test case 5" << endl;
	n = 4;
	ret = climbStairs(n);
	cout << ret << endl;

	cout << "test case 6" << endl;
	n = 44;
	ret = climbStairs(n);
	cout << ret << endl;
}

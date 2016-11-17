/*
 * SquareRoot.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

int mySqrt(int x) {

	if(x == 1)
		return x;

	int begin = 0;
	int end = x;
	long long middle = (begin + end) / 2;
	long long square = middle * middle;
	while(square != x)
	{
		if(square < x)
		{
			begin = middle;
		}
		else
		{
			end = middle;
		}

		if(middle != (begin + end) / 2)
		{
			middle = (begin + end) / 2;
			square = middle * middle;
		}
		else
		{
			break;
		}
	}
	return middle;
}

void MySqrtTest()
{
	int x;
	int root;

	cout << "test case 1" << endl;
	x = 0;
	root = mySqrt(x);
	assert(root == 0);
	cout << root << endl;

	cout << "test case 2" << endl;
	x = 1;
	root = mySqrt(x);
	assert(root == 1);
	cout << root << endl;

	cout << "test case 3" << endl;
	x = 4;
	root = mySqrt(x);
	assert(root == 2);
	cout << root << endl;

	cout << "test case 4" << endl;
	x = 1000000;
	root = mySqrt(x);
	assert(root == 1000);
	cout << root << endl;

	cout << "test case 5" << endl;
	x = 100000000;
	root = mySqrt(x);
	assert(root == 10000);
	cout << root << endl;

	cout << "test case 6" << endl;
	x = 2;
	root = mySqrt(x);
	assert(root == 1);
	cout << root << endl;
}

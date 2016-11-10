/*
 * GrayCode.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"

vector<int> grayCode(int n) {
	vector<int> ret;

	ret.push_back(0);

	if(n == 0)
		return ret;

	ret.push_back(1);

	if(n == 1)
		return ret;

	int base = 1;
	int size = ret.size();
	for(int i = 1; i < n; ++i)
	{
		size = ret.size();
		base *= 2;
		for(int j = size - 1; j >= 0; -- j)
		{
			ret.push_back(ret[j] + base);
		}
	}

	return ret;
}

void GrayCodeTest()
{
	int n;
	vector<int> vi;

	cout << "test case 1" << endl;
	n = 0;
	vi = grayCode(n);
	assert(vi.size() == 1);
	DumpVector(vi);

	cout << "test case 2" << endl;
	n = 1;
	vi = grayCode(n);
	assert(vi.size() == 2);
	DumpVector(vi);

	cout << "test case 3" << endl;
	n = 2;
	vi = grayCode(n);
	assert(vi.size() == 4);
	DumpVector(vi);

	cout << "test case 4" << endl;
	n = 3;
	vi = grayCode(n);
	assert(vi.size() == 8);
	DumpVector(vi);

	cout << "test case 5" << endl;
	n = 4;
	vi = grayCode(n);
	assert(vi.size() == 16);
	DumpVector(vi);
}

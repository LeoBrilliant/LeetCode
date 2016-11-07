/*
 * K-thSmallestInLexicographicalOrder.cpp
 *
 *  Created on: 2016年11月3日
 *      Author: user
 */

#include "P51~100.h"

int getNodeCount(vector<int> & level, vector<int> & counter, int height)
{
	int ret = 0;

	for(int i = height; i < level.size(); ++i)
	{
		if(level[i] >= counter[i - height])
		{
			ret += counter[i - height];
		}
		else
		{
			ret += level[i];
		}
	}

	return ret;
}

int findKthNumber(int n, int k) {
	vector<int> ruler{9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
	vector<int> counter{1,  10,  100,  1000,  10000,  100000,  1000000,  10000000,  100000000};

	vector<int> level;
	vector<int> digits;

	int x = n;
	for(int i = 0; x > 0 && i < ruler.size(); ++i)
	{
		if(x >= ruler[i])
		{
			level.push_back(ruler[i]);
		}
		else
		{
			level.push_back(x);
		}
		x -= ruler[i];
	}

	int height = level.size();

	int curr = 0;
	int count = 0;

	int d = 0;
	while(k > 0)
	{
		//vector<int> tree;
		count = getNodeCount(level, counter, curr);
		d ++;
		if(k > count)
		{
			for(int i = curr; i < level.size(); ++i)
			{
				if(level[i] >= counter[i - curr])
				{
					level[i] -= counter[i - curr];
				}
				else
				{
					level[i] = 0;
				}
			}
			k -= count;
		}
		else
		{
			if(curr == 0)
			{
				digits.push_back(d);
			}
			else
			{
				digits.push_back(d - 1);
			}

			curr ++;
			k -= 1;
			d = 0;
		}
	}

	// 拼接具体数字
	int ret = 0;
	for(auto i : digits)
	{
		ret = ret * 10 + i;
	}

	return ret;
}

void FindKthNumberTest()
{
	int n;
	int k;
	int ret;

	cout << "test case 1" << endl;
	n = 13;
	k = 2;
	ret = findKthNumber(n, k);
	assert(ret == 10);
	cout << ret << endl;

	cout << "test case 2" << endl;
	n = 13;
	k = 6;
	ret = findKthNumber(n, k);
	//assert(ret == 1);
	cout << ret << endl;

	cout << "test case 3" << endl;
	n = 13;
	k = 1;
	ret = findKthNumber(n, k);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 4" << endl;
	n = 13;
	k = 5;
	ret = findKthNumber(n, k);
	assert(ret == 13);
	cout << ret << endl;

	cout << "test case 5" << endl;
	n = 13;
	k = 13;
	ret = findKthNumber(n, k);
	assert(ret == 9);
	cout << ret << endl;

	cout << "test case 6" << endl;
	n = 9;
	k = 1;
	ret = findKthNumber(n, k);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 7" << endl;
	n = 9;
	k = 9;
	ret = findKthNumber(n, k);
	assert(ret == 9);
	cout << ret << endl;

	cout << "test case 8" << endl;
	n = 100;
	k = 10;
	ret = findKthNumber(n, k);
	assert(ret == 17);
	cout << ret << endl;

	cout << "test case 9" << endl;
	n = 100;
	k = 100;
	ret = findKthNumber(n, k);
	assert(ret == 99);
	cout << ret << endl;

	cout << "test case 10" << endl;
	n = 100;
	k = 2;
	ret = findKthNumber(n, k);
	assert(ret == 10);
	cout << ret << endl;

	cout << "test case 11" << endl;
	n = 100;
	k = 3;
	ret = findKthNumber(n, k);
	assert(ret == 100);
	cout << ret << endl;
}


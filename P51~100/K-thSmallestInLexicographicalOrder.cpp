/*
 * K-thSmallestInLexicographicalOrder.cpp
 *
 *  Created on: 2016年11月3日
 *      Author: user
 */

#include "P51~100.h"

int findKthNumber(int n, int k) {
	vector<int> ruler{9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
	vector<int> counter{1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
	vector<int> num{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

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
	for(int i = height; k > 0 && i > 0; --i)
	{
		for(int j = 0; j < i; ++ j)
		{
			count += level[j];
		}
		curr = k / count;
		if(i == height)
		{
			digits.push_back(num[curr + 1]);
			if(curr == 0)
			{
				k = k - 1;
			}
			else
			{
				k = k - (curr) * counter[height - i];
			}
		}
		else
		{
			digits.push_back(num[curr - 1]);
			k = k - curr * counter[height - i];
		}
	}

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
}


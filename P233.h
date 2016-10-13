/*
 * P233.h
 *
 *  Created on: 2016年10月5日
 *      Author: LeoBrilliant
 */

#ifndef P233_H_
#define P233_H_

#include "Common.h"

vector<int> value{0, 1, 20, 300, 4000, 50000,
	600000, 7000000, 80000000, 900000000};

vector<int> pow_10{1, 10, 100, 1000, 10000,
	100000, 1000000, 10000000, 100000000, 1000000000};

void Num2Digits(int n, vector<int> & vi)
{
	int remainder = 0;
	while(n)
	{
		remainder = n % 10;
		n /= 10;
		vi.push_back(remainder);
	}
	return;
}

int Digits2Num(vector<int> & vi)
{
	int nums = 0;
	for(int i = vi.size() - 1; i >= 0; --i)
	{
		nums += vi[i] * 10;
	}
	return nums;
}

int Digits2Num(vector<int> & vi, size_t begin)
{
	int nums = 0;
	for(int i = begin - 1; i >= 0; --i)
	{
		nums = vi[i] + nums * 10;
	}
	return nums;
}

int countDigitOne(int n) {
	if(n < 0)
		return 0;
	vector<int> vi;
	Num2Digits(n, vi);

	int m = 0;
	long long count = 0;
	for(int i = vi.size() - 1; i >= 0; --i)
	{
		m = vi[i];
		if(m == 1)
		{
			count += Digits2Num(vi, i) + 1 + value[i];
		}
		else if(m > 1)
		{
			count += m * value[i] + pow_10[i];
		}
	}

	return count;
}

void CountDigitOneTest()
{
	int n = 13;
	//n = 24;
	int count = 0;
	count = countDigitOne(n);
	cout << count << endl;
}

#endif /* P233_H_ */

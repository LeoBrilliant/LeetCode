/*
 * P7.h
 *
 *  Created on: 2016年10月7日
 *      Author: LeoBrilliant
 */

#ifndef P7_H_
#define P7_H_

#include "Common.h"

void NumToDigits(long long n, vector<int> & vi)
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

long long ReverseDigitsToNum(vector<int> & vi)
{
	long long nums = 0;
	for(auto i : vi)
	{
		nums = nums * 10 + i;
	}
	return nums;
}

int reverse(int x) {
	int sign = x < 0 ? -1 : 1;
	long long ll = x;
	ll = abs(ll);
	vector<int> vi;
	NumToDigits(ll, vi);
	long long ret = ReverseDigitsToNum(vi);

	if(sign == -1)
	{
		if(ret > 2147483648)
			ret = 0;
	}
	else
	{
		if( ret > 2147483647)
			ret = 0;
	}

	ret *= sign;

	return ret;
}

void ReverseTest()
{
	int x = 2147483647;
	x = 123;
	x = -2147483648;
	int ret = reverse(x);

	cout << ret << endl;
}

#endif /* P7_H_ */

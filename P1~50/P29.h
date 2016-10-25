/*
 * P29.h
 *
 *  Created on: 2016年10月16日
 *      Author: LeoBrilliant
 */

#ifndef P29_H_
#define P29_H_

#include "Common.h"

int divide2(int dividend, int divisor) {
	if((dividend == -2147483648 && divisor == -1) ||
			divisor == 0)
		return 2147483647;

	int sdividend = 1, sdivisor = 1;

	if(dividend < 0)
	{
		sdividend = -1;
	}
	if(divisor < 0)
	{
		sdivisor = -1;
	}

	int sresult = sdividend == sdivisor ? 1 : -1;
	long long ndividend = sdividend == 1 ? dividend : abs(dividend);
	long long ndivisor = sdivisor == 1 ? divisor : abs(divisor);

	int result = 0;
	while(ndividend > 0)
	{
		ndividend -= ndivisor;
		if(ndividend >= 0)
		{
			if(sresult == 1)
				result ++;
			else
				result --;
		}
	}

	return result;
}

int divide(int dividend, int divisor) {
	if((dividend == -2147483648 && divisor == -1) ||
			divisor == 0)
		return 2147483647;

	int sdividend = 1, sdivisor = 1;

	if(dividend < 0)
	{
		sdividend = -1;
	}
	if(divisor < 0)
	{
		sdivisor = -1;
	}

	int sresult = sdividend == sdivisor ? 1 : -1;
	long long ndividend = sdividend == 1 ? dividend : llabs(dividend);
	long long ndivisor = sdivisor == 1 ? divisor : llabs(divisor);

	long long speedup[40];

	long long a = ndividend, b = ndivisor;
	int i = 0;
	int result = 0;

	// speedup[i] = 2 ** i * b
	while(a >= b)
	{
		speedup[i++] = b;
		b <<= 1;
	}

	a = 0;
	for(int j = i - 1; j >= 0; --j)
	{
		if(a + speedup[j] > ndividend)
			continue;
		else
		{
			a += speedup[j];
			result += pow(2, j);
		}
	}

	if(sresult == -1)
		return -result;
	return result;
}

void DivideTest()
{
	int a, b;

	a = 1, b = -1;
	a = 0, b = -1;
	a = 10, b = -2;
	//a = 3, b = 2;
	//a = -1, b = -2;
	//a = -3, b = -2;

	a = 2147483647, b = 1;

	a = -2147483648, b = 1;

	int c = divide(a, b);

	cout << c << endl;
}
#endif /* P29_H_ */

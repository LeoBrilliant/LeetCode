/*
 * NumberOf1Bits.cpp
 *
 *  Created on: 2016年11月11日
 *      Author: user
 */

#include "P51~100.h"

int hammingWeight(uint32_t n) {

	uint32_t flag = 3;
	int count = 0;
	uint32_t base = 1;
	int res = 0;
	for(int i = 0; i < 16; ++i)
	{
		res = flag & n;
		if(res == 3 * base)
		{
			count += 2;
		}
		else if(res == 2 * base || res == base)
		{
			count += 1;
		}
		flag <<= 2;
		base *= 4;
	}

	return count;
}

void NumberOf1BitsTest()
{
	uint32_t n;
	int ret;

	cout << "test case 1" << endl;
	n = 0;
	ret = hammingWeight(n);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	n = 1;
	ret = hammingWeight(n);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 3" << endl;
	n = 2;
	ret = hammingWeight(n);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 4" << endl;
	n = 3;
	ret = hammingWeight(n);
	assert(ret == 2);
	cout << ret << endl;

	cout << "test case 5" << endl;
	n = 11;
	ret = hammingWeight(n);
	assert(ret == 3);
	cout << ret << endl;

	cout << "test case 6" << endl;
	n = 7;
	ret = hammingWeight(n);
	assert(ret == 3);
	cout << ret << endl;

}

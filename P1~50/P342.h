/*
 * P342.h
 *
 *  Created on: 2016年10月4日
 *      Author: LeoBrilliant
 */

#ifndef P342_H_
#define P342_H_

#include <iostream>
#include <set>
using namespace std;

void PrintPowerOfN(int n, int power)
{
	int value = 1;
	cout << "{" ;
	for(int i = 1; i <= power && value <= 2147483647; ++ i)
	{
		value *= n;
		cout << value << ", " ;
	}
	cout << "}" << endl;
}


bool isPowerOfFour(int num)
{
	if(num <= 0) return false;

	if(num & (num - 1)) return false;
	if(num & 0x55555555) return true;
	return false;
}

bool isPowerOfFour3(int num)
{
	if(num <= 0) return false;

	int remainder = 0;
	while(num > 0 && num != 1 && !remainder)
	{
		remainder = num & 3;
		num >>= 2;
	}
	return !remainder;
}

bool isPowerOfFour2(int num)
{
	set<int> p4{4, 16, 64, 256, 1024, 4096,
		16384, 65536, 262144, 1048576,
		4194304, 16777216, 67108864,
		268435456, 1073741824, 1};

	bool ret = false;
	if(p4.find(num) != p4.end())
		ret = true;

	return ret;
}

void PowerOfFourTest()
{
	//PrintPowerOfN(4, 16);
	bool result = false;
	int num = 5;
	num = 4;
	num = 16;
	num = 1;
	num = 2;
	num = 17;
	result = isPowerOfFour(num);

	cout << result << endl;
}

#endif /* P342_H_ */

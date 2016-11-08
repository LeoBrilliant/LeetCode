/*
 * PlusOne.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

vector<int> plusOne(vector<int>& digits) {

	if(!digits.size())
		return digits;

	int carry = 0;
	int addend = 1;
	int sum = 0;
	for(int i = digits.size() - 1; i >= 0; --i)
	{
		sum = carry + addend + digits[i];
		carry = sum / 10;
		digits[i] = sum % 10;
		addend = 0;
	}

	if(carry)
	{
		digits.insert(digits.begin(), carry);
	}

	return digits;
}

void PlusOneTest()
{
	vector<int> digits;
	vector<int> ret;

	cout << "test case 1" << endl;
	digits = {};
	ret = plusOne(digits);
	DumpVector(ret);

	cout << "test case 2" << endl;
	digits = {0};
	ret = plusOne(digits);
	DumpVector(ret);

	cout << "test case 3" << endl;
	digits = {9};
	ret = plusOne(digits);
	DumpVector(ret);

	cout << "test case 4" << endl;
	digits = {4, 9};
	ret = plusOne(digits);
	DumpVector(ret);

	cout << "test case 5" << endl;
	digits = {9, 9};
	ret = plusOne(digits);
	DumpVector(ret);

	cout << "test case 6" << endl;
	digits = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
	ret = plusOne(digits);
	DumpVector(ret);
}

/*
 * AddBinary.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: user
 */

#include "P51~100.h"

string addBinary(string a, string b) {

	int alen = a.length();
	int blen = b.length();

	int len = alen > blen ? alen : blen;

	int augend = 0;
	int addend = 0;
	int carry = 0;
	int sum = 0;
	string rev, ret;
	for(int i = 1; i <= len; ++i)
	{
		if(i <= alen)
		{
			augend = a[alen - i] - '0';
		}
		else
		{
			augend = 0;
		}

		if(i <= blen)
		{
			addend = b[blen - i] - '0';
		}
		else
		{
			addend = 0;
		}

		sum = carry + augend + addend;
		carry = sum / 2;
		sum %= 2;
		rev.push_back(sum + '0');
	}

	if(carry != 0)
		rev.push_back(carry + '0');

	for(int i = rev.length() - 1; i >= 0; --i)
		ret.push_back(rev[i]);

	return ret;
}

void AddBinaryTest()
{
	string a;
	string b;
	string ret;

	cout << "test case 1" << endl;
	b = "1";
	ret = addBinary(a, b);
	cout << ret << endl;

	cout << "test case 2" << endl;
	a = "11";
	b = "1";
	ret = addBinary(a, b);
	cout << ret << endl;

	cout << "test case 3" << endl;
	a = "11";
	b = "11";
	ret = addBinary(a, b);
	cout << ret << endl;

	cout << "test case 4" << endl;
	a = "1";
	b = "1111111";
	ret = addBinary(a, b);
	cout << ret << endl;

	cout << "test case 5" << endl;
	a = "";
	b = "1111111";
	ret = addBinary(a, b);
	cout << ret << endl;
}

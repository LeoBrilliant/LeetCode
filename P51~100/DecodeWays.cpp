/*
 * DecodeWays.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"

void Decoding(string s, int posi, int & count, unordered_set<string> dic)
{
	if(posi >= s.length())
	{
		count ++;
		return;
	}

	string s1 = s.substr(posi, 1);

	if(dic.find(s1) != dic.end())
	{
		Decoding(s, posi + 1, count, dic);

		if(posi + 1 < s.length())
		{
			string s2 = s.substr(posi, 2);
			if(dic.find(s2) != dic.end())
			{
				Decoding(s, posi + 2, count, dic);
			}
		}
	}
}

// TLE
int AnumDecodings(string s) {

	if(!s.length())
		return s.length();

	unordered_set<string> dic = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
			"21", "22", "23", "24", "25", "26"};


	int count = 0;

	Decoding(s, 0, count, dic);

	return count;
}

int BnumDecodings(string s) {

	if(s.length() == 0)
		return s.length();

	unordered_set<string> dic = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
			"11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
			"21", "22", "23", "24", "25", "26"};


	int fn = 0;
	int fn_1 = 0;
	if(dic.find(s.substr(0, 1)) != dic.end())
		fn_1 = 1;

	fn = fn_1;

	int fn_2 = 1;

	for(int i = 1; i < s.length(); ++i)
	{
		fn = 0;
		if(dic.find(s.substr(i, 1)) != dic.end())
		{
			fn += fn_1;
		}

		if(dic.find(s.substr(i - 1, 2))  != dic.end())
		{
			fn += fn_2;
		}

		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}

bool find(string  s)
{
	if(s[0] == '0')
		return false;

	int curr = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		curr *= 10;
		curr += s[i] - '0';
	}

	if(curr > 0 && curr <= 26)
		return true;

	return false;
}

int numDecodings(string s) {

	if(s.length() == 0)
		return s.length();

	int fn = 0;
	int fn_1 = 0;
	if(find(s.substr(0, 1)))
		fn_1 = 1;

	fn = fn_1;

	int fn_2 = 1;

	for(int i = 1; i < s.length(); ++i)
	{
		fn = 0;
		if(find(s.substr(i, 1)))
		{
			fn += fn_1;
		}

		if(find(s.substr(i - 1, 2)))
		{
			fn += fn_2;
		}

		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}

void DecodeWaysTest()
{
	string s;
	int ret;

	cout << "test case 1" << endl;
	s = "";
	ret = numDecodings(s);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	s = "1";
	ret = numDecodings(s);
	assert(ret == 1);
	cout << ret << endl;

	cout << "test case 3" << endl;
	s = "12";
	ret = numDecodings(s);
	assert(ret == 2);
	cout << ret << endl;

	cout << "test case 4" << endl;
	s = "123";
	ret = numDecodings(s);
	assert(ret == 3);
	cout << ret << endl;

	cout << "test case 5" << endl;
	s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
	ret = numDecodings(s);
	assert(ret == 589824);
	cout << ret << endl;

	cout << "test case 6" << endl;
	s = "0";
	ret = numDecodings(s);
	assert(ret == 0);
	cout << ret << endl;
}

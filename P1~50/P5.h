/*
 * P5.h
 *
 *  Created on: 2016年10月6日
 *      Author: LeoBrilliant
 */

#ifndef P5_H_
#define P5_H_

#include "Common.h"

//有很大的局限性，很多情况处理不了
string longestPalindrome2(string s) {
	stack<pair<char, int>> sc;
	stack<pair<int, int>> si;
	pair<char, int> pc;
	pair<int, int> pold, pnew;

	int begin = 0 , end = 0;
	int length = 0;

	if(s.length() == 0 || s.size() == 1)
		return s;

	sc.push(make_pair(s[0], 0));
	for(size_t i = 1; i < s.size(); ++i)
	{
		char c = s[i];
		pc = sc.top();
		if(pc.first == c)
		{
			sc.pop();
			pnew = make_pair(pc.second, i);
			if(!si.empty()){
				pold = si.top();
				if(pold.first == pnew.first + 1 && pold.second == pnew.second - 1)
				{
					si.pop();
					si.push(pnew);
					if(pnew.second - pnew.first + 1 > length)
					{
						length = pnew.second - pnew.first + 1;
						begin = pnew.first;
						end = pnew.second;
					}
				}
			}
			else
			{
				si.push(pnew);
			}
		}
		else
		{
			sc.push(make_pair(c, i));
		}
	}
	string ret;
	for(int i = begin; i <= end; ++i)
		ret.push_back(s[i]);

	return ret;
}

string longestPalindrome(string s) {
	int begin = 0 , end = 0;
	int length = 0;

	if(s.length() == 0 || s.size() == 1)
		return s;

	length = 0;

	for(int i = 0; i < s.size(); ++i)
	{
		for(int j = i - 1, k = i + 1; j >= 0 && k < s.size(); --j, ++k)
		{
			if(s[j] == s[k])
			{
				if(k - j + 1 > length)
				{
					length = k - j + 1;
					begin = j;
					end = k;
				}
				continue;
			}
			else
				break;
		}

		for(int j = i, k = i + 1; j >= 0 && k < s.size(); --j, ++k)
		{
			if(s[j] == s[k])
			{
				if(k - j + 1 > length)
				{
					length = k - j + 1;
					begin = j;
					end = k;
				}
				continue;
			}
			else
				break;
		}
	}
	string ret;
	for(int i = begin; i <= end; ++i)
		ret.push_back(s[i]);

	return ret;
}
void LongestPalindromeTest()
{
	string s = "";
	//s = "1";
	//s = "21221";
	//s = "1212221";
	s = "1111";
	string ret;
	ret = longestPalindrome(s);

	cout << ret << endl;
}


#endif /* P5_H_ */

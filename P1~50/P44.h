/*
 * P44.h
 *
 *  Created on: 2016年10月23日
 *      Author: LeoBrilliant
 */

#ifndef P44_H_
#define P44_H_

#include "Common.h"

// 算法思路没问题，就是TLE，递归求解的代价太大
bool isMatchTLE(string s, string p) {
	if(s.length() == 0 && p.length() == 0)
		return true;

	if((s.length() == 0 && p.length() != 0))
	{
		bool ret = true;
		if(p.find_first_not_of('*') != string::npos)
			ret = false;
		return ret;
	}

	if((s.length() != 0 && p.length() == 0))
		return false;

	bool ret = false;
	if((s[0] == p[0]) || p[0] == '?')
		ret = isMatchTLE(s.substr(1), p.substr(1));
	else if(p[0] == '*')
	{
		// 去除连续的'*'
		int index = p.find_first_not_of('*');
		if(index == string::npos)
			index = 1;
		for(int i = 0; i <= s.length(); ++ i)
		{
			ret = isMatchTLE(s.substr(i), p.substr(index));
			if(ret)
				break;
		}
	}

	return ret;
}

bool isMatch(string s, string p) {
	int si = 0;
	int pi = 0;
	int sstar = -1, pstar = -1;
	while(si < s.length())
	{
		// 如果当前字符相等，或者是'?'通配符，匹配下一个字符
		if(pi < p.length() && (s[si] == p[pi] || p[pi] == '?'))
		{
			si++;
			pi++;
		}
		// 如果当前模式字符为'*'，记录模式字符与匹配字符的位置
		// 同时跳过连续的'*'
		else if(pi < p.length() && p[pi] == '*')
		{
			sstar = si;
			pstar = ++pi;
		}
		// 模式串中出现了'*'，并且前一次匹配不成功
		else if(pstar != -1 && pstar <= p.length())
		{
			si = ++sstar;
			pi = pstar;
		}
		else
		{
			return false;
		}
	}

	while(pi < p.length() && p[pi] == '*')
	{
		pi ++;
	}

	return pi == p.size();
}
void WildcardMatchingTest()
{
	string s, p;
	bool ret = false;
	static int count = 0;

	cout << "test case " << 1 << endl;
	s = "aa", p = "a";
	ret = isMatchTLE(s, p);
	assert(ret == false);

	cout << "test case " << 2 << endl;
	s = "aa", p = "aa";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 3 << endl;
	s = "aaa", p = "aa";
	ret = isMatchTLE(s, p);
	assert(ret == false);

	cout << "test case " << 4 << endl;
	s = "aa", p = "*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 5 << endl;
	s = "aa", p = "a*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 6 << endl;
	s = "aa", p = "?*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 7 << endl;
	s = "ab", p = "?*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 8 << endl;
	s = "aab", p = "c*a*b";
	ret = isMatchTLE(s, p);
	assert(!ret);

	cout << "test case " << 9 << endl;
	s = "", p = "*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 10 << endl;
	s = "c", p = "*?*";
	ret = isMatchTLE(s, p);
	assert(ret);

	cout << "test case " << 11 << endl;
	s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", p = "a*******b";
	ret = isMatchTLE(s, p);
	assert(!ret);

	cout << "test case " << 12 << endl;
	s = "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb";
	p = "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a";
	ret = isMatch(s, p);
	assert(!ret);

	cout << ret << endl;

	p = "";
	cout << p.size() << endl;
	s = p.substr(1);
	cout << s.size() << endl;
}


#endif /* P44_H_ */

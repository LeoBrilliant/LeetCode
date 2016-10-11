/*
 * P10.h
 *
 *  Created on: 2016年10月9日
 *      Author: LeoBrilliant
 */

#ifndef P10_H_
#define P10_H_

#include "Common.h"

bool isMatch(string s, string p) {
	if(s.length() == 0)
	{
		if(p.length() == 0 || (p[1] == '*' && isMatch(s, p.substr(2))))
			return true;
		else
			return false;
	}
	else if(p.length() == 0)
		return false;

	if(p[1] != '*')
	{
		if(s[0] == p[0] || p[0] == '.')
			return isMatch(s.substr(1), p.substr(1));
		else
			return false;
	}
	else // p[1] == '*'
	{
		if(s[0] != p[0] && p[0] != '.')
		{
			return isMatch(s, p.substr(2));
		}
		else //s[0] == p[0] || p[0] == '.',
		{
			if(isMatch(s, p.substr(2)))
				return true;

			int i = 0;
			while(s[i] == p[0] || p[0] == '.')
			{
				if(isMatch(s.substr(i + 1), p.substr(2)))
					return true;
				if(i+1 >= s.length())
					break;
				i++;
			}
			return false;
		}
	}
}

bool isMatch2(string s, string p)
{
	if(p.length() == 0)
		return s.length() == 0;

	if(p[1] != '*')
	{
		return ((p[0] == s[0]) || (p[0] == '.' && s.length())) && isMatch2(s.substr(1), p.substr(1));
	}

	int i = 0;
	while((p[0] == s[i]) || (p[0] == '.' && i < s.length()))
	{
		if(isMatch2(s.substr(i), p.substr(2)))
			return true;
		++i;
	}

	return isMatch2(s.substr(i), p.substr(2));
}


void IsMatchTest()
{
	string s = "";
	string p = "";

	s = "aa", p = "a";
	s = "aa", p = "aa";
	s = "aaa", p = "aa";
	s = "aa", p = "a*";
	s = "aa", p = ".*";
	s = "ab", p = ".*";
	s = "aab", p = "c*a*b";

	bool ret = isMatch(s, p);

	cout << ret << endl;

	s = "helloWorld";
	cout << s.substr(1) << endl;
}



#endif /* P10_H_ */

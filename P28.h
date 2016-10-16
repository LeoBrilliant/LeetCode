/*
 * P28.h
 *
 *  Created on: 2016年10月15日
 *      Author: LeoBrilliant
 */

#ifndef P28_H_
#define P28_H_

#include "Common.h"

int strStr1(string haystack, string needle)
{
	if(!haystack.size() && !needle.size())
			return 0;

	if(haystack.size() && !needle.size())
			return 0;

	if(!haystack.size() && needle.size())
		return -1;

	int index = -1;
	size_t length = 0;

	for(size_t i = 0; i < haystack.size(); ++i)
	{
		for(size_t j = 0; j < needle.size(); ++j)
		{
			if(needle[j] == haystack[i+j])
			{
				length++;
			}
			else
			{
				break;
			}
		}

		if(length == needle.size())
		{
			index = i;
			break;
		}
		else
		{
			length = 0;
		}
	}

	return index;
}

void getNext(string s, vector<size_t> & next)
{
	int len = s.length();
	int j = 0;

	next[0] = next[1] = 0;

	for(int i = 1; i < len; ++i)
	{
		while(j > 0 &&  s[i] != s[j]) j = next[j];
		if(s[i] == s[j]) ++j;
		next[i + 1] = j;
	}
}

int search(string s, string p, vector<size_t> & next)
{
	int j = 0;
	int index = -1;
	for(int i = 0; i < s.length(); ++i)
	{
		while(j > 0 && s[i] != p[j])
			j = next[j];
		if(s[i] == p[j])
			++j;
		if(j == p.length())
		{
			index = i - j + 1;
		}
	}
	return index;
}

vector<int> getNext(string p)
{
	int i = p.size();
	int j = 0;
	int k = -1;
	vector<int> next(i);
	//结束标志
	next[0] = -1;
	// i是模式串的长度，j是当前字符的下标，k是公共前缀后一个字符的下标
	// next[i-1]已经在循环结束前进行了初始化
	while(j < i - 1)
	{
		//如果没有找到公共的前缀和后缀，即k == -1时，则从模式串的头部开始寻找，即next[j] = 0;
		//如果有公共前缀，并且当前字符p[j]与公共前缀后一个字符p[k]相等，则next[j] = k;
		//如果有公共前缀，但是当前字符p[j]与公共前后一个字符p[k]不等，则继续寻找公共前缀。
		//next数组的下标表示当前比较的字符的下标，next数组中的值表示公共前缀的长度
		if(k == -1 || p[j] == p[k])
		{
			k++;
			j++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

int KMP(string s, string p)
{
	int i = 0;
	vector<int> next = getNext(p);

	int j = 0;
	int index = -1;
	while(i < s.size())
	{
		// 如果没有公共前缀，即取到next[0]，则从p[0]和s[i+1]开始比较
		// 或者当前比较的字符相等,同时比较下一个字符
		// 如果存在公共前缀，并且当前字符不相等，则寻找长度更短的公共前缀
		if(j == -1 || s[i] == p[j])
		{
			i ++;
			j ++;
		}
		else
		{
			j = next[j];
		}

		//已经找到第一次匹配
		if(j == p.size())
		{
			index = i - j;
			break;
		}
	}

	DumpVector(next);
	return index;
}

int strStr(string haystack, string needle)
{
	if(!haystack.size() && !needle.size())
			return 0;

	if(haystack.size() && !needle.size())
			return 0;

	if(!haystack.size() && needle.size())
		return -1;

	int index = KMP(haystack, needle);

	return index;
}

void StrStrTest()
{
	string s1, s2;

	s1 = "HelloWorld";
	s2 = "Hello";

	/*
	s2 = "World";
	s2 = "Fool";
	s2 = "";
*/

/*
	s1 = "a";
	s2 = "";
*/

/*
	s1 = "";
	s2 = "";
*/
	s1 = "abcdabcdabde";
	s2 = "abcdabd";

	int k =  strStr(s1, s2);

	cout << k << endl;
}



#endif /* P28_H_ */

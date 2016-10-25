/*
 * P32.h
 *
 *  Created on: 2016年10月5日
 *      Author: LeoBrilliant
 */

#ifndef P32_H_
#define P32_H_

#include "Common.h"

//只能识别很少的括号匹配
int longestValidParentheses2(string s) {
	vector<char> t;
	int max = 0;

	for(auto c : s)
	{
		if(!t.empty())
		{
			if(c == t.back()){
				t.clear();
				if(c == '(')
					t.push_back(c);
			}
			else
			{
				t.push_back(c);
			}
		}
		else
		{
			if(c == '(')
				t.push_back(c);
		}

		if(!t.empty() && t.back() == ')' && max < t.size())
		{
			max = t.size();
		}

	}

	return max;
}

template<typename t>
void PopAll(stack<t> s)
{
	while(!s.empty())
		s.pop();
}

//还是要用stack
int longestValidParentheses(string s)
{
	stack<pair<char, int> > sc;
	stack<pair<int, int> > si;
	pair<char, int> pc;
	pair<int, int> pnew, pold;

	int max = 0;
	int length = 0;

	for(size_t i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if(sc.empty())
		{
			if(c == '(')
			{
				sc.push(make_pair(c, i));
			}
			else
			{
				//栈里没有多余的'('，所以其中一个栈可以不用把字符也保存起来。
			}
		}
		else
		{
			if(c == '(')
			{
				sc.push(make_pair(c,i));
			}
			else
			{
				pc = sc.top();
				sc.pop();

				pnew = make_pair(pc.second, i);

				while(!si.empty()){
					pold = si.top();
					//如果本次匹配的子串与上次匹配的子串连续，生成新的匹配子串
					if(pnew.first == (pold.second + 1))
					{
						pnew = make_pair(pold.first, i);
						si.pop();
					}
					//如果本次匹配的子串包含上次匹配的子串，用新串代替上次的子串
					else if(pnew.first < pold.first)
					{
						pnew = make_pair(pc.second, i);
						si.pop();
					}
					//这是一个独立的子串
					else
					{
						break;
					}
				}
				si.push(pnew);
				//计算新子串的长度
				length = pnew.second - pnew.first + 1;
				if(length > max)
				{
					max = length;
				}
			}
		}
	}
	return max;
}

void LongestValidParenthesesTest()
{
	string s = "";
	s = "(";
	s = "(()";
	//s = ")()())";
	//s = "()(())";
	//s = "()(()";
	s = ")))))";
	s = "((((()";
	s = ")(()())(()";
	int max = 0;
	max = longestValidParentheses(s);

	cout << max << endl;
}


#endif /* P32_H_ */

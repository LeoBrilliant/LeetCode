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
				//expecting += 1;
				//length += 1;
			}
			else
			{
				//if(length > max)
				//	max = length;
				//length = 0;
				//expecting = 0;
			}
		}
		else
		{
			if(c == '(')
			{
				sc.push(make_pair(c,i));
				//expecting += 1;
				//length += 1;
			}
			else
			{
				pc = sc.top();
				//pi = make_pair(pc.second, i);
				//tmp_len += 2;
				//expecting -= 1;
				sc.pop();

				pnew = make_pair(pc.second, i);

				while(!si.empty()){
					pold = si.top();
					if(pnew.first == (pold.second + 1))
					{
						pnew = make_pair(pold.first, i);
						si.pop();
						//si.push(pnew);
					}
					else if(pnew.first < pold.first)
					{
						pnew = make_pair(pc.second, i);
						si.pop();
						//si.push(pnew);
					}
					else
					{
						//pnew = make_pair(pc.second, i);
						//si.push(pnew);
						break;
					}
				}
				si.push(pnew);
				length = pnew.second - pnew.first + 1;
				if(length > max)
				{
					max = length;
				}
			}
		}
	}

	//if(length > max)
	//	max = length;

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

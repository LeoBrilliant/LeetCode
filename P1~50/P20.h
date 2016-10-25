/*
 * P20.h
 *
 *  Created on: 2016年10月13日
 *      Author: user
 */

#ifndef P20_H_
#define P20_H_

#include "Common.h"

bool isValid(string s) {
	if(s.empty()) return true;

	bool ret = true;
	stack<char> sc;

	for(auto c : s)
	{
		if(c == '(' || c == '[' || c == '{')
		{
			sc.push(c);
		}
		else
		{
			if(sc.empty())
			{
				ret = false;
				break;
			}

			switch(c)
			{
			case ')':
				if(sc.top() == '(')
				{
					sc.pop();
				}
				else
				{
					ret = false;
					break;
				}
				break;
			case ']':
				if(sc.top() == '[')
				{
					sc.pop();
				}
				else
				{
					ret = false;
					break;
				}
				break;
			case '}':
				if(sc.top() == '{')
				{
					sc.pop();
				}
				else
				{
					ret = false;
					break;
				}
				break;
			default:
				ret = false;
			}

			if(ret == false)
				break;
		}
	}

	if(ret == true && !sc.empty())
		ret = false;

	return ret;
}


void IsValidTest()
{
	string s = "";
	s = "()";
	s = "()[]{}";

	s = "(";

	s = "()]";
	bool ret = isValid(s);

	cout << ret << endl;
}

#endif /* P20_H_ */

/*
 * P9.h
 *
 *  Created on: 2016年10月7日
 *      Author: LeoBrilliant
 */

#ifndef P9_H_
#define P9_H_

#include "Common.h"

//Accepted
bool isPalindrome2(int x) {
	list<int> li;
	int remainder = 0;
	bool ret = true;

	if(x == 0)
		ret = true;
	else if(x < 0)
		ret = false;
	else
	{
		while(x)
		{
			remainder = x % 10;
			x /= 10;
			li.push_back(remainder);
		}
		while(!li.empty())
		{
			if(li.front() != li.back())
			{
				ret = false;
				break;
			}
			else
			{
				li.pop_front();
				if(!li.empty())
					li.pop_back();
			}
		}
	}

	return ret;
}

bool isPalindrome(int x)
{
	bool ret = true;
	int len = 1;
	if(x < 0)
		ret = false;
	else if(x == 0)
		ret = true;
	else
	{
		int n = x;
		while(n/10)
		{
			n /= 10;
			len *= 10;
		}
		int head, tail;
		while(x)
		{
			tail = x % 10;
			head = x / len;
			if(tail != head)
			{
				ret = false;
				break;
			}
			else
			{
				x %= len;
				x /= 10;
				if(x >= 0)
					len /= 100;
			}
		}
	}

	return ret;
}
void IsPalindromeNumTest()
{
	int x = 12344321;
	x = 121;
	x = 101;
	x = 1;
	//x = -2147447412;
	bool ret = isPalindrome(x);

	cout << ret << endl;
}



#endif /* P9_H_ */

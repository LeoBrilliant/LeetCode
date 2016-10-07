/*
 * P8.h
 *
 *  Created on: 2016年10月7日
 *      Author: LeoBrilliant
 */

#ifndef P8_H_
#define P8_H_

#include "Common.h"


int myAtoi(string str) {
	bool started = false;
	bool end = false;
	int sign = 1;
	long long ret = 0;

	string val;

	for(auto s : str)
	{
		if(!end)
		switch(s)
		{
		case ' ':
		{
			if(!started)
			{
				continue;
			}
			else
			{
				end = true;
			}
			break;
		}
		case '+':
		{
			if(!started)
			{
				sign = 1;
				started = true;
			}
			else
			{
				end = true;
			}
			break;
		}
		case '-':
		{
			if(!started)
			{
				sign = -1;
				started = true;
			}
			else
			{
				end = true;
			}
			break;
		}
		default:
		{
			if('0' <= s && s <= '9')
			{
				//ret = ret * 10 + s - '0';
				val.push_back(s);
				if(!started)
				{
					started = true;
				}
			}
			else
			{
				end = true;
			}
		}
		}
		else
			break;
	}


	for(auto s: val) {
		ret = ret * 10 + s - '0';
		if(sign == -1)
		{
			if(ret > 2147483648)
			{
				ret = 2147483648;
				break;
			}
		}
		else
		{
			if( ret > 2147483647)
			{
				ret = 2147483647;
				break;
			}
		}
	}

	ret *= sign;

	return ret;
}

void MyAtoiTest()
{
	string s = "-11234";
	//s = "1-1";
	//s = "  -0012a42";
	//s = "9223372036854775809";
	int i = myAtoi(s);

	cout << i << endl;
}



#endif /* P8_H_ */

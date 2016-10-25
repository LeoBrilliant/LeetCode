/*
 * P13.h
 *
 *  Created on: 2016年10月11日
 *      Author: user
 */

#ifndef P13_H_
#define P13_H_

#include <iostream>

using namespace std;

int romanToInt(string s) {
	int n = 0;
	for(size_t i = 0; i < s.length(); ++i)
	{
		switch(s[i])
		{
		case 'I':
			if(i + 1 < s.length() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
			{
				n -= 1;
			}
			else
				n += 1;
			break;
		case 'V':
			n += 5;
			break;
		case 'X':
			if(i + 1 < s.length() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
			{
				n -= 10;
			}
			else
				n += 10;
			break;
		case 'L':
			n += 50;
			break;
		case 'C':
			if(i + 1 < s.length() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
			{
				n -= 100;
			}
			else
				n += 100;
			break;
		case 'D':
			n += 500;
			break;
		case 'M':
			n += 1000;
			break;
		}
	}

	return n;
}



#endif /* P13_H_ */

/*
 * P12.h
 *
 *  Created on: 2016年10月11日
 *      Author: user
 */

#ifndef P12_H_
#define P12_H_

#include <iostream>

using namespace std;

string intToRoman(int num) {
	string ronan;
	int n = num;
	while(n > 0 && n < 4000)
	{
		if(1 <= n && n < 5)
		{
			if(n <= 3)
			{
				ronan.push_back('I');
				n -= 1;
			}
			else if(n == 4)
			{
				ronan.append("IV");
				n -= 4;
			}
		}
		else if(5 <= n && n < 10)
		{
			if(n <= 8)
			{
				ronan.push_back('V');
				n -= 5;
			}
			else if(n == 9)
			{
				ronan.append("IX");
				n -= 9;
			}
		}
		else if(10 <= n && n < 50)
		{
			if(n < 40)
			{
				ronan.push_back('X');
				n -= 10;
			}
			else
			{
				ronan.append("XL");
				n -= 40;
			}
		}
		else if(50 <= n && n < 100)
		{
			if(n < 90)
			{
				ronan.push_back('L');
				n -= 50;
			}
			else
			{
				ronan.append("XC");
				n -= 90;
			}
		}
		else if(100 <= n && n < 500)
		{
			if(n < 400)
			{
				ronan.push_back('C');
				n -= 100;
			}
			else
			{
				ronan.append("CD");
				n -= 400;
			}
		}
		else if(500 <= n && n < 1000)
		{
			if(n < 900)
			{
				ronan.push_back('D');
				n -= 500;
			}
			else
			{
				ronan.append("CM");
				n -= 900;
			}
		}
		else
		{
			ronan.push_back('M');
			n -= 1000;
		}
	}

	return ronan;
}

void IntToRomanTest()
{
	int n = 3999;
	n = 1899;
	string s = intToRoman(n);

	cout << s << endl;
}


#endif /* P12_H_ */

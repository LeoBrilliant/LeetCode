/*
 * P43.h
 *
 *  Created on: 2016年10月19日
 *      Author: user
 */

#ifndef P43_H_
#define P43_H_

#include "Common.h"

string multiply(string num1, string num2) {
	if(!num1.size() || !num2.size())
		return "";

	string num("0123456789");

	string product;

	for(auto i = num1.rbegin(); i != num1.rend(); ++i)
	{
		string tmp = "";
		int carry = 0;
		for(auto j = num2.rbegin(); j != num2.rend(); ++j)
		{
			int result = (*i - '0') * (*j - '0') + carry;
			carry = result / 10;
			result %= 10;
			tmp.push_back(num[result]);
		}

		if(carry)
			tmp.push_back(num[carry]);

		int dist = distance(num1.rbegin(), i);

		for(int k = 0; k < dist; ++k)
			tmp.insert(tmp.begin(), '0');

		int length = tmp.size() > product.size() ? tmp.size() : product.size();

		string curr = "";
		carry = 0;
		for(int k = 0; k < length; ++ k)
		{
			int c1, c2;
			if(k < tmp.size())
				c1 = tmp[k] - '0';
			else
				c1 = 0;

			if(k < product.size())
				c2 = product[k] - '0';
			else
				c2 = 0;

			int sum = c1 + c2 + carry;
			carry = sum / 10;
			sum %= 10;
			curr.push_back(num[sum]);
		}

		if(carry)
			curr.push_back(num[carry]);

		product = curr;
	}

	string rev  = "";

	bool begin = false;
	for(auto i = product.rbegin(); i != product.rend(); ++i)
	{
		if(!begin && *i != '0')
		{
			begin = true;
		}

		if(begin)
			rev.push_back(*i);
	}

	if(!rev.size())
		rev = "0";

	return rev;
}


void MultiplyTest()
{
	string s1, s2;

	s1 = "1";
	s2 = "2";

	s1 = "1";
	s2 = "123456789";

	s1 = "123456789";
	s2 = "1";

	s1 = "123000";
	s2 = "3000";

	s1 = "10000";
	s2 = "0";

	string ret = multiply(s1, s2);

	cout << ret << endl;
}


#endif /* P43_H_ */

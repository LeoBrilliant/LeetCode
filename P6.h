/*
 * P6.h
 *
 *  Created on: 2016年10月6日
 *      Author: LeoBrilliant
 */

#ifndef P6_H_
#define P6_H_

#include "Common.h"

string convert(string s, int numRows) {
	if(numRows == 1)
		return s;

	vector<string> vs;

	for(int i = 0; i < numRows; ++i)
	{
		string t;
		vs.push_back(t);
	}

	int direction = 1;
	for(size_t i = 0, j = 0; i < s.size(); ++i)
	{
		if(j == 0)
		{
			direction = 1;
		}
		else if(j == numRows - 1)
		{
			direction = -1;
		}

		vs[j].push_back(s[i]);
		j += direction;
	}

	string ret;
	for(auto i : vs)
	{
		ret.append(i);
	}

	return ret;
}

void ConvertTest()
{
	string s = "PAYPALISHIRING";
	int n = 3;

	s = "AB";
	n = 1;
	string ret = convert(s, n);

	cout << ret << endl;
}



#endif /* P6_H_ */

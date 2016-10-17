/*
 * P38.h
 *
 *  Created on: 2016年10月17日
 *      Author: user
 */

#ifndef P38_H_
#define P38_H_

#include "Common.h"

string countAndSay(int n) {
	if(n <= 0) return "";

	vector<string> vs{"1", "2", "3", "4", "5", "6", "7", "8", "9"};

	string s = "1";
	int count = 0;
	for(int i = 1; i < n; ++i)
	{
		string tmp;
		for(int j = 0; j < s.length(); ++j)
		{
			count ++;
			if(j == s.length() - 1 || s[j] != s[j + 1])
			{
				tmp.append(vs[count - 1]);
				tmp.push_back(s[j]);
				count = 0;
			}
		}
		s = tmp;
	}

	return s;
}

void CountAndSayTest()
{
	int n;

	n = 1;

	n = 2;

	for(n = 1; n < 37; ++n){
	string s = countAndSay(n);

	cout << s << endl;
	}
}


#endif /* P38_H_ */

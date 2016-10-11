/*
 * P14.h
 *
 *  Created on: 2016年10月11日
 *      Author: user
 */

#ifndef P14_H_
#define P14_H_

#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

	string s;
	if(!strs.empty())
	for(size_t i = 0; i < strs[0].length(); ++i)
	{
		bool found = true;
		for(size_t j = 1; j < strs.size(); ++j)
		{
			if(i >= strs[j].length() || strs[j][i] != strs[0][i])
			{
				found = false;
				break;
			}
		}
		if(found)
		{
			s.push_back(strs[0][i]);
		}
		else
			break;
	}

	return s;
}

void LongestCommonPrefixTest()
{
	vector<string> vs{"123", "12"};
	string s = longestCommonPrefix(vs);

	cout << s << endl;
}


#endif /* P14_H_ */

/*
 * P17.h
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#ifndef P17_H_
#define P17_H_

#include "Common.h"

vector<string> letterCombinations(string digits) {
	/*map<char, string> nums {
		{'0', " "},
		{'1', "" },
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"},
	};
	*/
	vector<string> nums {" ", "", "abc", "def", "ghi",
		"jkl", "mno", "pqrs", "tuv", "wxyz"};

	vector<string> ret;
	for(auto c : digits)
	{
		string s = nums[c - '0'];
		if(ret.empty())
		{
			for(auto ch : s)
			{
				string tmp(1, ch);
				ret.push_back(tmp);
			}
		}
		else
		{
			vector<string> vs;
			for(auto ts : ret)
			{
				for(size_t i = 0; i < s.size(); ++i)
				{
					char ch = s[i];
					if(i != 0)
						ts.erase(ts.length() - 1, 1);
					ts.push_back(ch);
					vs.push_back(ts);
				}
			}
			ret = vs;
		}
	}

	return ret;
}

void LetterCombinationsTest()
{
	string digits = "23";
	digits = "";

	vector<string> ret = letterCombinations(digits);

	cout << '[' ;
	for(auto s : ret)
	{
		cout << s ;
		cout << ", " ;
	}
	cout << ']' << endl;
}


#endif /* P17_H_ */

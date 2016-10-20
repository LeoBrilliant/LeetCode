/*
 * P49.h
 *
 *  Created on: 2016年10月20日
 *      Author: user
 */

#ifndef P49_H_
#define P49_H_

#include "Common.h"

vector<vector<string>> groupAnagrams(vector<string>& strs) {

	vector<vector<string>> ret;
	map<string, size_t> words;
	int size = 0;
	for(auto s : strs)
	{
		string w = s;
		sort(w.begin(), w.end());

		if(words.find(w) != words.end())
		{
			int index = words[w];
			ret[index].push_back(s);
		}
		else
		{
			words[w] = size ++;
			vector<string> vs{s};
			ret.push_back(vs);
		}
	}

	return ret;
}

void GroupAnagramsTest()
{
	vector<string> vs;

	vs = {"eat", "tea", "tan", "ate", "nat", "bat"};

	vs = {};

	vector<vector<string>> ret = groupAnagrams(vs);

	DumpVectorOfVector(ret);
}



#endif /* P49_H_ */

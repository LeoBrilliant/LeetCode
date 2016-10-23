/*
 * P30.h
 *
 *  Created on: 2016年10月23日
 *      Author: LeoBrilliant
 */

#ifndef P30_H_
#define P30_H_

#include "Common.h"

vector<int> findSubstring(string s, vector<string>& words) {

	vector<int> ret;
	if(!words.size())
		return ret;
	int wlen = words[0].size();

	if(s.size() < wlen)
		return ret;

	map<string, int> dict;
	for(size_t i = 0; i < words.size(); ++i)
	{
		dict[words[i]] = i;
	}

	vector<int> excp(words.size(), 0);
	for(size_t i = 0; i < words.size(); ++i)
	{
		excp[dict[words[i]]]++;
	}

	//vector<int> w(s.size() - wlen, -1);
	size_t wsize = s.size() - wlen + 1;
	int w[wsize];
	for(size_t i = 0; i < wsize; ++i)
	{
		string word = s.substr(i, wlen);
		if(dict.find(word) != dict.end())
		{
			w[i] = dict[word];
		}
		else
		{
			w[i] = -1;
		}
	}

	int count = 0;
	for(size_t i = 0; i < wsize; ++i)
	{
		vector<int> con(words.size(), 0);
		count = 0;
		if(w[i] < 0)
		{
			//count = 0;
			//for(size_t k = 0; k < con.size(); ++k)
			//	con[k] =  0;
			continue;
		}
		else
		{
			for(size_t j = i; j < wsize; j += wlen)
			{
				if(w[j] < 0)
					break;

				con[w[j]]++;
				count ++;
				if(count == words.size())
				{
					bool same = true;
					for(size_t k = 0; k < words.size(); ++k)
					{
						if(con[k] != excp[k])
						{
							same = false;
							break;
						}
					}
					if(same)
						ret.push_back(i);

					count = 0;
					for(size_t k = 0; k < con.size(); ++k)
						con[k] =  0;

					break;
				}
			}
		}
	}

	return ret;
}

void FindSubstringTest()
{
	string s;
	vector<string> words;
	vector<int> ret;

	cout << "test case 1" << endl;
	s = "barfoothefoobarman";
	words = {"foo", "bar"};
	ret = findSubstring(s, words);
	DumpVector(ret);

	cout << "test case 2" << endl;
	s = "wordgoodgoodgoodbestword";
	words = {"word","good","best","good"};
	ret = findSubstring(s, words);
	DumpVector(ret);

}

#endif /* P30_H_ */

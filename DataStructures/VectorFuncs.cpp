/*
 * VectorFuncs.cpp
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#include "VectorFuncs.h"

void DumpVectorOfVectorOfStringByChar(vector<vector<string>> & vvs)
{
	int count = 0;
	cout << "[" << endl;
	for(auto vs : vvs)
	{
		cout << ++ count << endl;
		DumpVectorOfStringByChar(vs);
	}
	cout << "]" << endl;
}

void DumpVectorOfStringByChar(vector<string> & vs)
{
	cout << "[" << endl;
	for(auto s : vs)
	{
		cout << "[ " ;
		for(auto c : s)
		{
			cout << c << ", " ;
		}
		cout << " ]" << endl;
	}
	cout << "]" << endl;
}

void VectorStringToVectorOfVectorOfChar(vector<string> & vs, vector<vector<char>> & vvc)
{
	if(vs.size() == 0)
		return;

	for(size_t i = 0; i < vs.size(); ++ i)
	{
		vector<char> vc;
		vvc.push_back(vc);
		for(size_t j = 0; j < vs[i].size(); ++j)
		{
			vvc[i].push_back(vs[i][j]);
		}
	}
}

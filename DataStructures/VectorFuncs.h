/*
 * VectorFuncs.h
 *
 *  Created on: 2016年11月14日
 *      Author: user
 */

#ifndef VECTORFUNCS_H_
#define VECTORFUNCS_H_

#include "BasicHeaders.h"

template<typename T>
void DumpVector(vector<T> & vt)
{
	cout << '[';
	for(auto t : vt)
	{
		cout << t << ", ";
	}
	cout << "]" << endl;
}

template<typename T>
void DumpVectorOfVector(vector<vector<T>> & vvt)
{
	cout << "[" << endl;
	for(auto vt : vvt)
	{
		DumpVector(vt);
	}
	cout << "]" << endl;
}

template<typename T>
bool IsSame(vector<T> & vt1, vector<T> & vt2)
{
	size_t m = vt1.size();
	size_t n = vt2.size();

	if(m != n)
	{
		return false;
	}

	bool ret = true;

	for(size_t i = 0; i < m; ++ i)
	{
		if(vt1[i] != vt2[i])
		{
			ret = false;
			break;
		}
	}

	return ret;
}

template<typename T>
int CmpVector(vector<T> & vt1, vector<T> & vt2)
{
	size_t m = vt1.size();
	size_t n = vt2.size();

	size_t len = m < n ? m : n;

	int ret = 0;
	for(size_t i = 0; i < len; ++i)
	{
		if(vt1[i] == vt2[i])
		{
			continue;
		}
		else if(vt1[i] > vt2[i])
		{
			ret = 1;
			break;
		}
		else if(vt1[i] < vt2[i])
		{
			ret = -1;
			break;
		}
	}

	return ret;
}

void DumpVectorOfStringByChar(vector<string> & vs);
void DumpVectorOfVectorOfStringByChar(vector<vector<string>> & vvs);

void VectorStringToVectorOfVectorOfChar(vector<string> & vs, vector<vector<char>> & vvc);

#endif /* VECTORFUNCS_H_ */

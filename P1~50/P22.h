/*
 * P22.h
 *
 *  Created on: 2016年10月14日
 *      Author: user
 */

#ifndef P22_H_
#define P22_H_

#include "Common.h"

void AssembleParenthesis(vector<string> & vs, int left, int right, string s)
{
	if(left == 0 && right == 0)
	{
		//string * res = new string(s);
		//vs.push_back(*res);
		vs.push_back(s);
		//return true;
	}

	string ts = s;
	if(left > 0 && left <= right)
	{
		//ts.push_back('(');
		AssembleParenthesis(vs, left - 1, right, ts + "(");
		//left--;
	}

	if(right > 0 && right > left)
	{
		//ts.push_back(')');
		AssembleParenthesis(vs, left, right - 1, ts + ")");
		//right --;
	}
}

vector<string> generateParenthesis(int n) {
	vector<string> vs;
	string s = "";
	AssembleParenthesis(vs, n, n, s);

	return vs;
}

void GeneratParenthesisTest()
{
	int n;

	vector<string> vs;
	string str = "";
	n = 0;
	n = 1;
	//n = 2;
	n = 3;
	AssembleParenthesis(vs, n, n, str);

	cout << "[" ;
	for(auto s : vs)
	{
		cout << s << ", ";
	}
	cout << "]" << endl;
}


#endif /* P22_H_ */

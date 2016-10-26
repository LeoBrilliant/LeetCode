/*
 * PermutationSequence.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "P51~100.h"

void PermuteRecursiveK(string & all, vector<char> & curr, vector<char> & left, int & count, int k)
{
	if(left.size() == 0)
	{
		if(++count == k)
		{
			for(auto c : curr)
				all.push_back(c);
		}
		return;
	}

	for(auto i : left)
	{
		curr.push_back(i);
		vector<char> nleft;
		for(auto j : left)
		{
			if(i != j)
				nleft.push_back(j);
		}
		PermuteRecursiveK(all, curr, nleft, count, k);
		if(k == count)
			return;
		curr.pop_back();
	}
}

string AgetPermutation(int n, int k) {
	vector<char> all = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	string s;
	vector<char> curr;
	int count = 0;

	vector<char> p;
	for(int i = 0; i < n; i++)
		p.push_back(all[i]);

	if(k <= 1)
	{
		for(auto c : p)
			s.push_back(c);
	}
	else
		PermuteRecursiveK(s, curr, p, count, k);

	return s;
}

int GetFactorial(int n)
{
	int ret = 1;
	for(int i = 1; i <= n; ++i)
		ret *= i;

	return ret;
}

string getPermutation(int n, int k) {
	vector<char> all{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	string s;
	vector<int> fac{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

	int f = fac[n];


	int curr;
	int i;

	vector<char> t, tmp;
	for(i = 0; i < n; ++i)
		t.push_back(all[i]);

	for(i = n; i > 0; --i)
	{
		if(k >= fac[i - 1])
		{
			int j = k / fac[i - 1];
			s.push_back(t[j]);
			k = k - fac[i - 1] * j;
			for(int m = 0; m < t.size(); ++ m)
			{
				if(m == j)
					continue;
				tmp.push_back(t[m]);
			}
			t = tmp;
		}
		else
		{
			s.push_back(t[0]);
			t.erase(t.begin());
		}
		if(k >= fac[i])
			break;
	}

	return s;
}

void GetPermutationTest()
{
	string s;
	int n;
	int k;

	cout << "test case 1" << endl;
	n = 0;
	k = 0;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 2" << endl;
	n = 1;
	k = 0;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 3" << endl;
	n = 1;
	k = 1;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 4" << endl;
	n = 2;
	k = 1;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 5" << endl;
	n = 2;
	k = 2;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 6" << endl;
	n = 3;
	k = 5;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 7" << endl;
	n = 6;
	k = 500;
	s = getPermutation(n, k);
	cout << s << endl;

	cout << "test case 8" << endl;
	n = 9;
	k = 300000;
	s = getPermutation(n, k);
	cout << s << endl;
}

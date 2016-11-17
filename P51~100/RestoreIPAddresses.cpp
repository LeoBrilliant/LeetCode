/*
 * RestoreIPAddresses.cpp
 *
 *  Created on: 2016年11月11日
 *      Author: user
 */

#include "P51~100.h"

bool isValidNumber(string  s)
{
	if(s.length() > 1 && s[0] == '0')
		return false;

	int curr = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		curr *= 10;
		curr += s[i] - '0';
	}

	if(curr >= 0 && curr <= 255)
		return true;

	return false;
}

void GetIPAddress(string s, int posi, int section, string curr, vector<string> & ret)
{
	int n = s.length();

	if(n == posi && section == 0)
	{
		ret.push_back(curr);
		//DumpVector(ret);
		return;
	}

	if((n - posi) > (section) * 3)
		return;

	if(n - posi < section)
		return;

	for(int i = 1; i <= 3; ++i)
	{
		if(i + posi > n)
			break;

		string tmp = s.substr(posi, i);
		if(isValidNumber(tmp))
		{
			//cout << tmp << endl;
			string st;
			if(curr.size())
			{
				st = curr + ("." + tmp);
			}
			else
			{
				st = tmp;
			}
			//cout << st << endl;
			GetIPAddress(s, posi + i, section - 1, st, ret);
		}
		else
		{
			break;
		}
	}
}

vector<string> restoreIpAddresses(string s) {

	vector<string> vs;
	string tmp;

	if(s.length() < 4)
		return vs;

	GetIPAddress(s, 0, 4, tmp, vs);

	return vs;
}

void RestoreIPAddressesTest()
{
	string ip;
	vector<string> allips;

	cout << "test case 1" << endl;
	ip = "";
	allips = restoreIpAddresses(ip);
	assert(allips.size() == 0);
	DumpVector(allips);

	cout << "test case 2" << endl;
	ip = "1111";
	allips = restoreIpAddresses(ip);
	assert(allips.size() == 1);
	DumpVector(allips);

	cout << "test case 3" << endl;
	ip = "25525511135";
	allips = restoreIpAddresses(ip);
	assert(allips.size() == 2);
	DumpVector(allips);

	map<int, int> mii = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};

	for(auto m : mii)
	{
		cout << "(" << m.first << ", " << m.second << "), ";
	}
	cout << endl;

	mii = {{5, 5}, {1, 1}, {0, 0}, {3, 3}, {4, 4}, {2, 2}};

	for(auto m : mii)
	{
		cout << "(" << m.first << ", " << m.second << "), ";
	}
	cout << endl;
}

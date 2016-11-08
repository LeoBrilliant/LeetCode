/*
 * SimplifyPath.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

string simplifyPath(string path) {
	string ret;
	char last;
	int counter = 0;

	path += "/";

	for(int i = 0; i < path.length(); ++i)
	{
		if(path[i] == '.')
		{
			counter++;
		}
		else
		{
			if((counter == 1 || counter == 2) && path[i] == '/')
			{
				if(counter == 1)
				{

				}
				else if(counter == 2)
				{
					// 回溯
					if(ret.size() > 1)
					{
						ret.erase(ret.size() - 1, 1);
					}
					char c = ret[ret.size() - 1];
					while(c != '/')
					{
						ret.erase(ret.size() - 1, 1);
						c = ret[ret.size() - 1];
					}

					if(ret.size() > 1)
					{
						ret.erase(ret.size() - 1, 1);
						last = ret[ret.size() - 1];
					}
					else
					{
						last = '/';
					}
				}
				counter = 0;
			}
			else //if(path[i] != '/')
			{
				for(int j = 0; j < counter; ++j)
					ret.push_back('.');
				counter = 0;
			}

			if(path[i] == '/')
			{
				if(!ret.empty() && i == path.size() - 1)
					continue;

				if(last != '/')
				{
					ret.push_back(path[i]);
					last = path[i];
				}
			}
			else
			{
				ret.push_back(path[i]);
				last = path[i];
			}
		}
	}

	if(ret.size() > 1 && ret[ret.size() - 1] == '/')
	{
		ret.erase(ret.size() - 1, 1);
	}

	return ret;
}


string AsimplifyPath(string path) {
	string ret;
	char last;
	for(int i = 0; i < path.length(); ++i)
	{
		if(path[i] == '.')
		{
			if(i != path.length() - 1)
			{
				if(path[i + 1] == '/')
				{
					i ++;
				}
				else if(path[i + 1] == '.')
				{
					// 回溯
					if(ret.size() > 1)
					{
						ret.erase(ret.size() - 1, 1);
					}
					char c = ret[ret.size() - 1];
					while(c != '/')
					{
						ret.erase(ret.size() - 1, 1);
						c = ret[ret.size() - 1];
					}

					if(ret.size() > 1)
					{
						ret.erase(ret.size() - 1, 1);
						last = ret[ret.size() - 1];
					}
					else
					{
						last = '/';
					}
					i++;
				}
			}
		}
		else if(path[i] == '/')
		{
			if(!ret.empty() && i == path.size() - 1)
				continue;

			if(last != '/')
			{
				ret.push_back(path[i]);
				last = path[i];
			}
		}
		else
		{
			ret.push_back(path[i]);
			last = path[i];
		}
	}

	return ret;
}

static bool isSlash(char c)
{
	return c == '/';
}

static bool notSlash(char c)
{
	return !isSlash(c);
}

vector<string> split(string str)
{
	vector<string> ret;
	string::iterator it = str.begin();

	while(it != str.end())
	{
		it = find_if(it, str.end(), notSlash);
		string::iterator it2 = find_if(it, str.end(), isSlash);
		if(it != str.end()){
			ret.push_back(string(it, it2));
		}
		it = it2;
	}
	return ret;
}

string CsimplifyPath(string path)
{
	vector<string> v = split(path);
	stack<string> stk;

	string ret = "";

	for(int i = 0; i < v.size(); ++i)
	{
		if(v[i] == ".")
			continue;
		else if(v[i] == "..")
		{
			if(!stk.empty())
				stk.pop();
		}
		else
		{
			stk.push(v[i]);
		}
	}

	while(!stk.empty())
	{
		ret = "/" + stk.top() + ret;
		stk.pop();
	}

	if(ret == "")
		ret += "/";

	return ret;
}
void SimplifyPathTest()
{
	string path;
	string ret;

	cout << "test case 1" << endl;
	path = "/";
	ret = simplifyPath(path);
	assert(ret.compare("/") == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	path = "/.";
	ret = simplifyPath(path);
	assert(ret.compare("/") == 0);
	cout << ret << endl;

	cout << "test case 3" << endl;
	path = "/..";
	ret = simplifyPath(path);
	assert(ret.compare("/") == 0);
	cout << ret << endl;

	cout << "test case 4" << endl;
	path = "/../";
	ret = simplifyPath(path);
	assert(ret.compare("/") == 0);
	cout << ret << endl;

	cout << "test case 5" << endl;
	path = "/../a";
	ret = simplifyPath(path);
	assert(ret.compare("/a") == 0);
	cout << ret << endl;

	cout << "test case 6" << endl;
	path = "/../a/./../../";
	ret = simplifyPath(path);
	assert(ret.compare("/") == 0);
	cout << ret << endl;

	cout << "test case 7" << endl;
	path = "/a/./b/../../c/";
	ret = simplifyPath(path);
	assert(ret.compare("/c") == 0);
	cout << ret << endl;

	cout << "test case 8" << endl;
	path = "/home/";
	ret = simplifyPath(path);
	assert(ret.compare("/home") == 0);
	cout << ret << endl;

	cout << "test case 9" << endl;
	path = "/.../";
	ret = simplifyPath(path);
	assert(ret.compare("/...") == 0);
	cout << ret << endl;

	cout << "test case 10" << endl;
	path = "/...";
	ret = simplifyPath(path);
	assert(ret.compare("/...") == 0);
	cout << ret << endl;

	cout << "test case 11" << endl;
	path = "/...////";
	ret = simplifyPath(path);
	assert(ret.compare("/...") == 0);
	cout << ret << endl;

	cout << "test case 12" << endl;
	path = "/..honey/";
	ret = simplifyPath(path);
	assert(ret.compare("/..honey") == 0);
	cout << ret << endl;

}



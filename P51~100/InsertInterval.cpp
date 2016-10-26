/*
 * InsertInterval.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "P51~100.h"

bool Comp(Interval & a, Interval & b)
{
	return a.start == b.start ? a.end <= b.end : a.start < b.start ;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	int n = intervals.size();

	if(n < 1)
	{
		intervals.push_back(newInterval);
		return intervals;
	}

	vector<Interval> ret;

	bool merged = false;
	for(size_t k = 0; k < intervals.size() || !merged;)
	{
		Interval i;
		if(!merged)
		{
			if(k < intervals.size())
			{
				if(Comp(intervals[k], newInterval))
					i = intervals[k++];
				else
				{
					i = newInterval;
					//k --;
					merged = true;
				}
			}
			else
			{
				i = newInterval;
				merged = true;
			}
		}
		else
		{
			i = intervals[k++];
		}

		if(ret.empty())
		{
			ret.push_back(i);
		}
		else
		{
			auto j = ret.back();
			if(i.start == j.start && i.end >= j.end)
			{
				ret.pop_back();
				ret.push_back(i);
			}
			else if(i.start <= j.end && i.end >= j.end)
			{
				ret.pop_back();
				struct Interval k(j.start, i.end);
				ret.push_back(k);
			}
			else if(i.start > j.end)
			{
				ret.push_back(i);
			}
		}
	}
	return ret;
}

void InsertIntervalTest()
{
	vector<Interval> vi;
	Interval n;
	vector<Interval> ret;

	cout << "test case 1" << endl;
	vi = {{1, 3}, {6, 9}};
	n = {2, 5};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 2" << endl;
	vi = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	n = {4, 9};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 3" << endl;
	vi = {{1,5}};
	n = {2, 7};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 4" << endl;
	vi = {{3,5}};
	n = {2, 7};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 5" << endl;
	vi = {{3,5}};
	n = {2, 2};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 6" << endl;
	vi = {{3,5}};
	n = {2, 3};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	cout << "test case 7" << endl;
	vi = {{3,5}};
	n = {6, 8};
	DumpVectorOfInterval(vi);
	DumpInterval(n); cout << endl;
	ret = insert(vi, n);
	DumpVectorOfInterval(ret);

	vi = {{1,3},{2,6},{8,10},{15,18}};
}


/*
 * MergeIntervals.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "P51~100.h"

static bool Comp(Interval & a, Interval & b)
{
	return a.start == b.start ? a.end <= b.end : a.start < b.start ;
}

void ReverseInterval(Interval & i)
{
	if(i.start > i.end)
	{
		int t = i.start;
		i.start = i.end;
		i.end = t;
	}
}

void SwapIntervals(Interval & a, Interval & b)
{
	Interval t = a;
	a = b;
	b = t;
}

void QuickSortInterval(vector<Interval> & vi, int begin, int end)
{
	if(begin >= end)
		return;

	Interval pivot = vi[begin];

	int i = begin;
	int j = end;

	while(i < j)
	{
		while(Comp(pivot, vi[j]) && i < j)
			j -= 1;
		vi[i].start = vi[j].start;
		vi[i].end = vi[j].end;

		while(Comp(vi[i], pivot) && i < j)
			i += 1;

		vi[j].start = vi[i].start;
		vi[j].end = vi[i].end;
	}

	vi[i].start = pivot.start;
	vi[i].end = pivot.end;

	QuickSortInterval(vi, begin, i - 1);
	QuickSortInterval(vi, i + 1, end);
}

vector<Interval> merge(vector<Interval>& intervals) {
	int n = intervals.size();

	for(auto & i : intervals)
	{
		if(i.start > i.end)
			ReverseInterval(i);;
	}

	if(n <= 1) return intervals;

	vector<Interval> ret;

	//sort(intervals.begin(), intervals.end(), Comp);

	QuickSortInterval(intervals, 0, intervals.size() - 1);

	for(auto & i : intervals)
	{
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


void MergeIntervalsTest()
{
	vector<Interval> vi;
	vector<Interval> ret;

	vi = {{1,3},{2,6},{8,10},{15,18}};
	DumpVectorOfInterval(vi);

	vi = {{1,3},{8,10},{15,18},{2,6}};
	DumpVectorOfInterval(vi);
	//sort(vi.begin(), vi.end(), Comp);
	QuickSortInterval(vi, 0, vi.size() - 1);
	DumpVectorOfInterval(vi);

	vi = {{1,3},{8,10},{2, 7},{15,18},{2,6}};
	DumpVectorOfInterval(vi);
	//sort(vi.begin(), vi.end(), Comp);
	QuickSortInterval(vi, 0, vi.size() - 1);
	DumpVectorOfInterval(vi);

	cout << "test case 1" << endl;
	vi = {{1,3},{2,6},{8,10},{15,18}};
	DumpVectorOfInterval(vi);
	ret = merge(vi);
	DumpVectorOfInterval(ret);
}

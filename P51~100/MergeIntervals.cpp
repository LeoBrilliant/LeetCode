/*
 * MergeIntervals.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "P51~100.h"

bool Comp(Interval & a, Interval & b)
{
	return a.start == b.start ? a.end <= b.end : a.start < b.start ;
}


vector<Interval> merge(vector<Interval>& intervals) {

}


void MergeIntervalsTest()
{
	vector<Interval> vi;

	vi = {{1,3},{2,6},{8,10},{15,18}};

	DumpVectorOfInterval(vi);

	vi = {{1,3},{8,10},{15,18},{2,6}};
	DumpVectorOfInterval(vi);
	sort(vi.begin(), vi.end(), Comp);
	DumpVectorOfInterval(vi);

	vi = {{1,3},{8,10},{2, 7},{15,18},{2,6}};
	DumpVectorOfInterval(vi);
	sort(vi.begin(), vi.end(), Comp);
	DumpVectorOfInterval(vi);
}

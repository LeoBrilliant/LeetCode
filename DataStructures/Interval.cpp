/*
 * Interval.cpp
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#include "Interval.h"

void DumpInterval(Interval & i)
{
	cout << "[" << i.start << ", " << i.end << "]";
}

void DumpVectorOfInterval(vector<Interval> & vi)
{
	cout << "[" ;
	for(auto i : vi)
	{
		DumpInterval(i);
		cout << ", " ;
	}
	cout << "]" << endl;
}

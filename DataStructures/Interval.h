/*
 * Interval.h
 *
 *  Created on: 2016年10月26日
 *      Author: user
 */

#ifndef INTERVAL_H_
#define INTERVAL_H_

#include "BasicHeaders.h"

//struct Interval;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

typedef struct Interval Interval;

void DumpInterval(Interval & i);

void DumpVectorOfInterval(vector<Interval> & vi);

#endif /* INTERVAL_H_ */

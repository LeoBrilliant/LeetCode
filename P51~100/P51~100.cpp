/*
 * P51~100.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: user
 */

#include "P51~100.h"

// P55
void MergeIntervalsTest();
#ifdef ACCEPTED
// P54
void SpiralOrderTest();
// P52
void MaxSubArrayTest();
// P51
void SolveNQueensTest();
// P52
void TotalNQueensTest();
#endif

void P51_100()
{
	MergeIntervalsTest();
#ifdef ACCEPTED
	SpiralOrderTest();
	MaxSubArrayTest();
	TotalNQueensTest();
	SolveNQueensTest();
#endif
}


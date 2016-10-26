/*
 * P51~100.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: user
 */

#include "P51~100.h"

// P57
void InsertIntervalTest();
#ifdef ACCEPTED
// P56
void MergeIntervalsTest();
// P54
void SpiralOrderTest();
// P53
void MaxSubArrayTest();
// P51
void SolveNQueensTest();
// P52
void TotalNQueensTest();
#endif

void P51_100()
{
	InsertIntervalTest();

}

void Accepted()
{
#ifdef ACCEPTED
	MergeIntervalsTest();
	SpiralOrderTest();
	MaxSubArrayTest();
	TotalNQueensTest();
	SolveNQueensTest();
#endif
}

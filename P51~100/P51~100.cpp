/*
 * P51~100.cpp
 *
 *  Created on: 2016年10月25日
 *      Author: user
 */

#include "P51~100.h"
// P64
void MinPathSumTest();
// P63
void UniquePathsIITest();
// P62
void UniquePathsTest();
// P61
void RotateRightTest();
// P440
void FindKthNumberTest();
// P85
void MaximalRectangleTest();
// P84
void LargestRectangleAreaTest();
// P70
void ClimbStairsTest();
#ifdef ACCEPTED
// P60
void GetPermutationTest();
// P59
void GenerateMatrixTest();
// P55
void CanJumpTest();
// P57
void InsertIntervalTest();
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
	MinPathSumTest();
}

void Accepted()
{
#ifdef ACCEPTED
	UniquePathsIITest();
	UniquePathsTest();
	RotateRightTest();
	MaximalRectangleTest();
	FindKthNumberTest();
	LargestRectangleAreaTest();
	ClimbStairsTest();
	GetPermutationTest();
	GenerateMatrixTest();
	CanJumpTest();
	InsertIntervalTest();
	MergeIntervalsTest();
	SpiralOrderTest();
	MaxSubArrayTest();
	TotalNQueensTest();
	SolveNQueensTest();
#endif
}

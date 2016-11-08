/*
 * SetMatrixZeroes.cpp
 *
 *  Created on: 2016年11月8日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

void setZeroes(vector<vector<int>>& matrix) {

	int row = matrix.size();
	if(!row)
		return;

	int col = matrix[0].size();
	if(!col)
		return;

	int rowflag = 1;
	for(int i = 0; i < row; ++i)
	{
		if(matrix[i][0] == 0)
		{
			rowflag = 0;
			break;
		}
	}

	int colflag = 1;
	for(int j = 0; j < col; ++j)
	{
		if(matrix[0][j] == 0)
		{
			colflag = 0;
			break;
		}
	}

	for(int i = 0; i < row; ++ i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i < col; ++i)
	{
		if(matrix[0][i] == 0)
		{
			for(int j = 1; j < row; ++j)
			{
				matrix[j][i] = 0;
			}
		}
	}

	for(int i = 1; i < row; ++i)
	{
		if(matrix[i][0] == 0)
		{
			for(int j = 1; j < col; ++j)
			{
				matrix[i][j] = 0;
			}
		}
	}

	if(!rowflag)
	{
		for(int i = 0; i < row; ++i)
		{
			matrix[i][0] = 0;
		}
	}

	if(!colflag)
	{
		for(int i = 0; i < col; ++i)
		{
			matrix[0][i] = 0;
		}
	}
}

void SetZeroesTest()
{
	vector<vector<int>> vvi;

	cout << "test case 1" << endl;
	vvi = {};
	setZeroes(vvi);
	DumpVectorOfVector(vvi);

	cout << "test case 2" << endl;
	vvi = {{0}};
	setZeroes(vvi);
	DumpVectorOfVector(vvi);

	cout << "test case 3" << endl;
	vvi = {{1}};
	setZeroes(vvi);
	DumpVectorOfVector(vvi);

	cout << "test case 4" << endl;
	vvi = {{7,0,0,5},{9,2,0,8},{2,6,5,1},{1,9,3,8},{5,3,4,6},{5,2,0,2},{4,3,5,1},{5,2,4,4}};
	setZeroes(vvi);
	DumpVectorOfVector(vvi);
}


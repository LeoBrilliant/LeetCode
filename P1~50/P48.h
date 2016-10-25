/*
 * P48.h
 *
 *  Created on: 2016年10月19日
 *      Author: user
 */

#ifndef P48_H_
#define P48_H_

#include "Common.h"

void rotate2(vector<vector<int>>& matrix) {
	vector<vector<int>> image;

	for(size_t i = 0; i < matrix.size(); ++i)
	{
		vector<int> vi;
		image.push_back(vi);
	}

	for(auto i = matrix.rbegin(); i != matrix.rend(); ++i)
	{
		for(size_t j = 0; j < (*i).size(); ++j)
		{
			image[j].push_back((*i)[j]);
		}
	}

	matrix = image;
}

void MoveRight(int & row, int & col, int step, int bound, int & value, vector<vector<int>> & matrix)
{
	if(col + step >= bound)
	{
		int tmp = row + col + step - bound;
		row = tmp;
		col = bound;

		tmp = matrix[row][col];
		matrix[row][col] = value;
		value = tmp;
	}
}

void MoveDown(int & row, int & col, int step, int bound, int & value, vector<vector<int>> & matrix)
{
	if(row + step >= bound)
	{
		col = bound + (bound - row - step);
		row = bound;

		int tmp = matrix[row][col];
		matrix[row][col] = value;
		value = tmp;
	}
}

void MoveLeft(int & row, int & col, int step, int bound, int & value, vector<vector<int>> & matrix)
{
	if(col - step <= bound)
	{
		int tmp = row - step + col - bound;
		row = tmp;
		col = bound;

		tmp = matrix[row][col];
		matrix[row][col] = value;
		value = tmp;
	}
}

void MoveUp(int & row, int & col, int step, int bound, int & value, vector<vector<int>> & matrix)
{
	if(row - step <= bound)
	{
		int tmp = col - row + step + bound;
		col = tmp;
		//col = step - row + bound;
		row = bound;

		tmp = matrix[row][col];
		matrix[row][col] = value;
		value = tmp;
	}
}

void rotate(vector<vector<int>> & matrix)
{
	int step;
	int right, down, left, up;
	int value = -1;
	for(int i = 0; i < matrix.size() / 2; ++i)
	{
		step = matrix.size() - 1 - i * 2;
		right = matrix.size() - i - 1;
		down = matrix.size() - i - 1;
		left = i;
		up = i;

		for(int j = i; j < right; ++j)
		{
			int row = i;
			int col = j;

			value = matrix[i][j];
			MoveRight(row, col, step, right, value, matrix);
			//DumpVectorOfVector(matrix);
			MoveDown(row, col, step, down, value, matrix);
			//DumpVectorOfVector(matrix);
			MoveLeft(row,col, step, left, value, matrix);
			//DumpVectorOfVector(matrix);
			MoveUp(row, col, step, up, value, matrix);
			//DumpVectorOfVector(matrix);
		}
	}
}

void RotageTest()
{
	vector<vector<int>> m;

	vector<int> vi;

	vi = {1};

	m.push_back(vi);

	m = {{1, 2}, {3, 4}};

	m = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

	m = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

	m = {{1, 2, 3, 4, 5}, {16, 17, 18, 19, 6}, {15, 24, 25, 20, 7}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}};

	DumpVectorOfVector(m);

	rotate(m);

	DumpVectorOfVector(m);
}


#endif /* P48_H_ */

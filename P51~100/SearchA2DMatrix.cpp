/*
 * SearchA2DMatrix.cpp
 *
 *  Created on: 2016年11月9日
 *      Author: user
 */

#include "P51~100.h"

bool BSearchVector(vector<int> & vi, int target)
{
	int m = vi.size();
	if(!m)
		return false;

	int begin = 0;
	int end = m - 1;
	int middle;
	bool ret = false;
	while(begin <= end)
	{
		middle = (begin + end) / 2;
		if(vi[middle] == target)
		{
			ret = true;
			break;
		}
		else if(vi[middle] > target)
		{
			end = middle - 1;
		}
		else if(vi[middle] < target)
		{
			begin = middle + 1;
		}
	}
	return ret;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

	int m = matrix.size();
	if(!m)
		return false;

	int n = matrix[0].size();
	if(!n)
		return false;

	int begin = 0;
	int end = m - 1;
	int middle;
	bool ret = false;

	while(begin <= end)
	{
		middle = (begin + end) / 2;
		if(matrix[middle][0] == target)
		{
			ret = true;
			break;
		}
		else if(matrix[middle][0] < target)
		{
			if(middle == m - 1)
			{
				ret = BSearchVector(matrix[middle], target);
				break;
			}
			else if(matrix[middle + 1][0] > target)
			{
				ret = BSearchVector(matrix[middle], target);
				break;
			}
			else
			{
				begin = middle + 1;
			}
		}
		else if(matrix[middle][0] > target)
		{
			if(middle == 0)
			{
				ret = false;
				break;
			}
			else if(matrix[middle - 1][0] < target)
			{
				ret = BSearchVector(matrix[middle - 1], target);
				break;
			}
			else
			{
				end = middle - 1;
			}
		}
	}
	return ret;
}

void SearchMatrixTest()
{
	vector<vector<int>> vvi;
	int target;
	bool ret;

	cout << "test case 1" << endl;
	vvi = {};
	target = 0;
	ret = searchMatrix(vvi, target);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vvi = {{}, {}, {}};
	target = 0;
	ret = searchMatrix(vvi, target);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vvi = {{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}};
	target = 3;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vvi = {{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}};
	target = 1;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 5" << endl;
	vvi = {{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}};
	target = 23;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vvi = {{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}};
	target = 50;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 7" << endl;
	vvi = {{1,   3,  5,  7}};
	target = 7;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 8" << endl;
	vvi = {{1}};
	target = 7;
	ret = searchMatrix(vvi, target);
	assert(ret == false);
	cout << ret << endl;

	cout << "test case 9" << endl;
	vvi = {{1}};
	target = 1;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;

	cout << "test case 10" << endl;
	vvi = {{1,   3,  5,  7},
			{10, 11, 16, 20},
			{23, 30, 34, 50}};
	target = 11;
	ret = searchMatrix(vvi, target);
	assert(ret == true);
	cout << ret << endl;
}


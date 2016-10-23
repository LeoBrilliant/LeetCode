/*
 * P37.h
 *
 *  Created on: 2016年10月23日
 *      Author: LeoBrilliant
 */

#ifndef P37_H_
#define P37_H_

#include "Common.h"

bool CheckRows2(vector<vector<char>> & board)
{
	bool ret = true;
	for(auto s : board)
	{
		vector<int> vi(9, 0);
		for(auto c : s)
		{
			if(c == '.')
				continue;

			int index = c - '1';
			if(vi[index] == 0)
			{
				vi[index] ++;
			}
			else
			{
				ret = false;
				break;
			}
		}
		if(!ret)
			break;
	}
	return ret;
}

bool CheckColumns2(vector<vector<char>> & board)
{
	bool ret = true;
	for(size_t i = 0; i < board[0].size(); ++i)
	{
		vector<int> vi(9, 0);
		vector<char> vc;
		for(size_t j = 0; j < board.size(); ++j)
		{
			char c = board[j][i];
			vc.push_back(c);
			if(board[j][i] == '.')
				continue;

			int index = board[j][i] - '1';
			if(vi[index] == 0)
			{
				vi[index] ++;
			}
			else
			{
				ret = false;
				break;
			}
		}
		if(!ret)
			break;
	}

	return ret;
}

bool CheckGrids2(vector<vector<char>> & board)
{
	bool ret = true;
	for(size_t i = 0; i < 3; i ++)
	{
		for(size_t j = 0; j < 3; j ++)
		{
			vector<int> vi(9, 0);
			for(size_t k = 0; k < 9; ++ k)
			{
				int row = i * 3 + k / 3;
				int col = j * 3 + k % 3;

				if(board[row][col] == '.')
					continue;

				int index = board[row][col] - '1';

				if(vi[index] == 0)
				{
					vi[index] ++;
				}
				else
				{
					ret = false;
					break;
				}
			}
			if(!ret)
				break;
		}
		if(!ret)
			break;
	}

	return ret;
}

vector<vector<int>> PreprocessRows(vector<vector<char>> & board)
{
	vector<vector<int>> ret;
	for(auto s : board)
	{
		vector<int> vi(9, 0);
		for(auto c : s)
		{
			if(c == '.')
				continue;

			int index = c - '1';
			if(vi[index] == 0)
			{
				vi[index] ++;
			}
		}

		vector<int> tmp;
		for(size_t i = 0 ; i < vi.size(); ++i)
		{
			if(vi[i] == 0)
				tmp.push_back(i + 1);
		}
		ret.push_back(tmp);
	}
	return ret;
}

vector<vector<int>> PreprocessColumns(vector<vector<char>> & board)
{
	vector<vector<int>> ret;
	for(size_t i = 0; i < board[0].size(); ++i)
	{
		vector<int> vi(9, 0);
		vector<char> vc;
		for(size_t j = 0; j < board.size(); ++j)
		{
			char c = board[j][i];
			vc.push_back(c);
			if(board[j][i] == '.')
				continue;

			int index = board[j][i] - '1';
			if(vi[index] == 0)
			{
				vi[index] ++;
			}
		}

		vector<int> tmp;
		for(size_t i = 0 ; i < vi.size(); ++i)
		{
			if(vi[i] == 0)
				tmp.push_back(i + 1);
		}
		ret.push_back(tmp);
	}

	return ret;
}

vector<vector<int>> PreprocessGrids(vector<vector<char>> & board)
{
	vector<vector<int>> ret;
	for(size_t i = 0; i < 3; i ++)
	{
		for(size_t j = 0; j < 3; j ++)
		{
			vector<int> vi(9, 0);
			for(size_t k = 0; k < 9; ++ k)
			{
				int row = i * 3 + k / 3;
				int col = j * 3 + k % 3;

				if(board[row][col] == '.')
					continue;

				int index = board[row][col] - '1';

				if(vi[index] == 0)
				{
					vi[index] ++;
				}
			}
			vector<int> tmp;
			for(size_t i = 0 ; i < vi.size(); ++i)
			{
				if(vi[i] == 0)
					tmp.push_back(i + 1);
			}
			ret.push_back(tmp);
		}
	}

	return ret;
}

void solveSudoku(vector<vector<char>>& board) {

	vector<vector<int>> rows = PreprocessRows(board);
	vector<vector<int>> cols = PreprocessColumns(board);
	vector<vector<int>> grids = PreprocessGrids(board);

	pair<int, int> xy;
	vector<int> eles;
	pair<pair<int, int>, pair<int, vector<int>>> node;
	vector<pair<pair<int, int>, pair<int, vector<int>>>> lists;

	for(int x = 0; x < 9; x ++)
	{
		for(int y = 0; y < 9; ++ y)
		{
			if(board[x][y] == '.')
			{
				xy = make_pair(x, y);
				int gridno = x / 3 * 3 + y / 3 ;

				vector<int> rc;
				set_intersection(rows[x].begin(), rows[x].end(),
						cols[y].begin(), cols[y].end(), back_inserter(rc));
				vector<int> rcg;
				set_intersection(rc.begin(), rc.end(),
						grids[gridno].begin(), grids[gridno].end(), back_inserter(rcg));

				node = make_pair(xy, make_pair(0, rcg));
				lists.push_back(node);
			}
		}
	}

	DumpVectorOfVector(rows);
	DumpVectorOfVector(cols);
	DumpVectorOfVector(grids);
}

void SolveSudokuTest()
{
	vector<string> vs;
	vs = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};

	vector<vector<char>> vvc;

	for(auto s : vs)
	{
		vector<char> vc;
		for(auto c : s)
		{
			vc.push_back(c);
		}
		vvc.push_back(vc);
	}

	DumpVectorOfVector(vvc);

	solveSudoku(vvc);
}
#endif /* P37_H_ */

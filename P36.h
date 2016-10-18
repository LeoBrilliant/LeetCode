/*
 * P36.h
 *
 *  Created on: 2016年10月18日
 *      Author: LeoBrilliant
 */

#ifndef P36_H_
#define P36_H_

#include "Common.h"

bool CheckRows(vector<vector<char>> & board)
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

bool CheckColumns(vector<vector<char>> & board)
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

bool CheckGrids(vector<vector<char>> & board)
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
bool isValidSudoku(vector<vector<char>>& board) {
	bool ret = true;
	//ret = CheckRows(board) && CheckColumns(board) && CheckGrids(board);

	bool ret1 = CheckRows(board);
	bool ret2 = CheckColumns(board);
	bool ret3 = CheckGrids(board);
	ret = ret1 && ret2 && ret3;
	return ret;
}

void IsValidSudokuTest()
{
	vector<string> vs;
	vs = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};

	vs = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};

	vs = {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
	DumpVector(vs);

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

	bool ret = isValidSudoku(vvc);

	cout << ret << endl;
}


#endif /* P36_H_ */

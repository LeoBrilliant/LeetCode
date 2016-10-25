/*
 * P37.h
 *
 *  Created on: 2016年10月23日
 *      Author: LeoBrilliant
 */

#ifndef P37_H_
#define P37_H_

#include "Common.h"

/*
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

		vector<int> tmp(10, 0);
		for(size_t i = 0 ; i < vi.size(); ++i)
		{
			if(vi[i] == 0)
				tmp[i] = 1;
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

		vector<int> tmp(10, 0);
		for(size_t i = 0 ; i < vi.size(); ++i)
		{
			if(vi[i] == 0)
				tmp[i] = 0;
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

typedef struct sNode{
	int x;
	int y;
	int curr;
	vector<int> currset;
	vector<int> searched;
} sNode;

int GetGridNo(int x, int y)
{
	return  x / 3 * 3 + y / 3 ;
}
*/
// 本来想通过缩小可选择范围来加速，后来发现维护这个可选择集合实在是太难了。。。
// 忍不住去网上看了解法，发现就是暴力破解。。。好吧，重新写
/*
void solveSudoku(vector<vector<char>>& board) {

	// 获取行、列、小格的剩余元素
	vector<vector<int>> rows = PreprocessRows(board);
	vector<vector<int>> cols = PreprocessColumns(board);
	vector<vector<int>> grids = PreprocessGrids(board);

	sNode * node;
	vector<sNode *> lists;

	for(int x = 0; x < 9; x ++)
	{
		for(int y = 0; y < 9; ++ y)
		{
			if(board[x][y] == '.')
			{
				node =  new sNode;
				node->x = x;
				node->y = y;
				int gridno = GetGridNo(x, y);

				vector<int> rc;
				set_intersection(rows[x].begin(), rows[x].end(),
						cols[y].begin(), cols[y].end(), back_inserter(rc));
				vector<int> rcg;
				set_intersection(rc.begin(), rc.end(),
						grids[gridno].begin(), grids[gridno].end(), back_inserter(rcg));

				node->curr = 0;
				node->currset = rcg;
				lists.push_back(node);
			}
		}
	}

	for(size_t i = 0; i < lists.size(); ++i)
	{
		for(size_t j = 0; j < lists[i]->currset.size(); ++ j)
		{
			lists[i]->curr = lists[i]->currset[j];
			lists[i]->currset;
		}
	}



	DumpVectorOfVector(rows);
	DumpVectorOfVector(cols);
	DumpVectorOfVector(grids);
}
*/

bool CheckXY(vector<vector<char>> & board, int x, int y)
{
	bool ret = true;
	// Check Row
	char c;
	char t = board[x][y];
	for(int i = 0; i < 9; ++i)
	{
		c = board[x][i];
		if(i != y && c == t)
			return false;
	}

	for(size_t j = 0; j < board.size(); ++j)
	{
		c = board[j][y];
		if(j != x && c == t)
			return false;
	}

	int r = x / 3 * 3;
	int col = y / 3 * 3;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++ j)
		{
			c = board[r + i][col + j];
			if(x != r +i && y != col + j && c == t)
				return false;
		}
	}
	return ret;
}
bool CheckXY2(vector<vector<char>> & board, int x, int y)
{
	bool ret = true;
	// Check Row
	vector<int> vr(9, 0);
	vector<int> vc(9, 0);
	vector<int> vg(9, 0);
	for(auto c : board[x])
	{
		if(c == '.')
			continue;

		int index = c - '1';
		if(vr[index] == 0)
		{
			vr[index] ++;
		}
		else
		{
			return false;
		}
	}

	for(size_t j = 0; j < board.size(); ++j)
	{
		char c = board[j][y];
		if(board[j][y] == '.')
			continue;

		int index = board[j][y] - '1';
		if(vc[index] == 0)
		{
			vc[index] ++;
		}
		else
		{
			return false;
		}
	}

	int r = x / 3 * 3;
	int c = y / 3 * 3;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++ j)
		{
			if(board[r + i][c + j] == '.')
				continue;

			int index = board[r + i][c + j] - '1';
			if(vg[index] == 0)
			{
				vg[index] ++;
			}
			else
			{
				return false;
			}
		}
	}
	return ret;
}

void solveSudoku(vector<vector<char>> & board)
{
	pair<int, int> xy;
	pair<pair<int, int>, char> node;
	stack<pair<pair<int, int>, char>> mem;
	bool ret = false;
	bool reset = false;
	char c;

	for(int x = 0; x < 9; x++)
	{
		for(int y = 0; y < 9;)
		{
			if(board[x][y] == '.')
			{
				xy = make_pair(x, y);
				node = make_pair(xy, '.');
				mem.push(node);

				node = mem.top();
				ret = false;
				for(c = '1'; c <= '9'; ++c)
				{
					node.second = c;
					board[x][y] = c;

					ret = CheckXY(board, x, y);
					if(ret)
					{
						mem.top().second = c;
						break;
					}
				}
				if(c > '9' && ! ret)
				{
					board[x][y] = '.';
					mem.pop();
					while(!mem.empty())
					{
						x = mem.top().first.first;
						y = mem.top().first.second;
						c = mem.top().second;
						if(c >= '9')
						{
							board[x][y] = '.';
							mem.pop();
						}
						else
						{
							mem.top().second++;
							reset = true;
							break;
						}
					}
				}
			}
			else
			{
				if(mem.empty())
				{
					y++;
					continue;
				}

				node = mem.top();
				if(node.first.first == x && node.first.second == y)
				{
					ret = false;
					for(c = node.second; c <= '9'; ++c)
					{
						board[x][y] = c;

						ret = CheckXY(board, x, y);
						if(ret)
						{
							mem.top().second = c;
							break;
						}
					}
					if(c > '9' && ! ret)
					{
						board[x][y] = '.';
						mem.pop();
						while(!mem.empty())
						{
							x = mem.top().first.first;
							y = mem.top().first.second;
							c = mem.top().second;
							if(c >= '9')
							{
								board[x][y] = '.';
								mem.pop();
							}
							else
							{
								mem.top().second++;
								reset = true;
								break;
							}
						}
					}
				}
			}
			if(!reset)
				y++;
			else
				reset = false;
			//if(x == 8 && y == 8)
			//	cout << "81" << endl;
			//cout << '[' << x << ", "  << y << " ] ->" << board[x][y] << endl;
		}
	}
}

void SolveSudokuTest()
{
	vector<string> vs;
	vs = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};

	vs = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};

	vs = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};

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

	DumpVectorOfVector(vvc);
}
#endif /* P37_H_ */

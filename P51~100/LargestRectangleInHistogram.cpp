/*
 * LargestRectangleInHistogram.cpp
 *
 *  Created on: 2016年10月27日
 *      Author: user
 */

#include "P51~100.h"

// TLE
int AlargestRectangleArea(vector<int>& heights) {
	pair<int, int> curr;
	vector<pair<int, int>> rect;
	int minheight = 0, maxarea = 0;

	for(size_t i = 0; i < heights.size(); ++i)
	{
		curr.first = heights[i];
		curr.second = 1;
		if(rect.empty())
		{
			rect.push_back(curr);
			minheight = curr.first;
			maxarea = curr.first * curr.second;
		}
		else
		{
			minheight = heights[i];
			int area2 = 0;
			for(int j = i; j >= 0; --j)
			{
				if(heights[j] < minheight)
					minheight = heights[j];
				int area1 = minheight * (i - j + 1);
				if(area2 < area1)
				{
					area2 = area1;
				}
			}

			if(area2 > maxarea)
			{
				maxarea = area2;
			}
			/*
			int h = (curr.first < rect[i - 1].first ? curr.first : rect[i - 1].first);
			int w = rect[i - 1].second + 1;
			int area2 = h * w;
			minheight = (minheight < curr.first ? minheight : curr.first);
			int area3 = minheight * (i + 1);

			if(area1 < area2)
			{
				curr.first = h;
				curr.second = w;
			}
			else if(area1 < area3)
			{
				curr.first = minheight;
				curr.second = i + 1;
			}

			area1 = curr.first * curr.second;
			maxarea = (maxarea > area1 ? maxarea : area1);
			rect.push_back(curr);
			*/
		}
	}
	return maxarea;
}

struct Seq{
	int begin;
	int end;
	int max;
	Seq(): begin(0), end(0), max(0){}
	Seq(int b, int e, int m) :  begin(b), end(e), max(m){}
	Seq(Seq & s): begin(s.begin), end(s.end), max(s.max){}
	void Dump(){
		cout << "[" << begin << ", " << max << ", " << end << "]";
	}
};

struct Area{
	int index;
	int begin;
	int end;
	int height;
	int area;
	Area(): index(0), begin(0), end(0), height(0), area(0) {}
	Area(int i, int b, int e, int h, int a): index(i), begin(b), end(e), height(h), area(a){}
	Area(Area & a): index(a.index), begin(a.begin), end(a.end), height(a.height), area(a.area) {}

	int GetArea()
	{
		return (end - begin + 1) * height;
	}
	void CalArea()
	{
		area = (end - begin + 1) * height;
	}
	void Dump()
	{
		cout << "[" << index;
		cout << ", <" << begin << ", " << end << ">, ";
		cout << height << ", " << area << "]";
	}
};


void ALargestRectangleAreaTest()
{
	vector<int> vi;
	int ret;

	cout << "test case 1" << endl;
	vi = {};
	ret = AlargestRectangleArea(vi);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {4};
	ret = AlargestRectangleArea(vi);
	assert(ret == 4);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {2,1,5,6,2,3};
	ret = AlargestRectangleArea(vi);
	assert(ret == 10);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {1, 2, 3, 4, 5};
	ret = AlargestRectangleArea(vi);
	assert(ret == 9);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vi = {};
	for(int i = 0; i < 20000; ++i)
		vi.push_back(i);
	ret = AlargestRectangleArea(vi);
	assert(ret == 100000000);
	cout << ret << endl;
}

// 这个方法写不下去了，因为觉得还是太复杂，没法达到O(n)的要求
/*
int BlargestRectangleArea(vector<int>& heights)
{
	bool desc = true;
	int max = 0;
	int left = 0, right = -1;
	vector<Seq> seq;
	// 计算分段
	for(int i = 0; i < heights.size(); ++i)
	{
		if(desc)
		{
			if(i == heights.size() || heights[i] < heights[i + 1])
			{
				if(i)
				{
					right = i;
					Seq s(left, right, max);
					seq.push_back(s);
					left = right + 1;
					max = 0;
				}
				desc = false;
			}
			else
			{
				if(heights[i] > heights[max])
					max = i;
			}
		}
		else
		{
			if(right == i - 1)
				left = i;

			if(i == heights.size() || heights[i] > heights[i + 1])
			{
				desc = true;
				if(heights[i] > max)
					max = i;
			}
		}
	}

	if(right != heights.size() - 1)
	{
		right = heights.size() - 1;
		if(heights[right] > heights[max])
			max = right;
		Seq s(left, right, max);
		seq.push_back(s);
	}

	for(auto s : seq)
	{
		s.Dump();
	}
	cout << endl;


	vector<Area> area;
	// 计算面积
	Area MaxArea;
	MaxArea.begin = MaxArea.end = 0;
	MaxArea.height = heights[0];
	MaxArea.index = 0;
	MaxArea.CalArea();
	Area MaxRightWidthArea(MaxArea);
	//vector<Area> MaxRightHeightArea;
	for(int i = 0; i < seq.size(); ++i)
	{
		Seq currseq = seq[i];
		Area maxarea;
		maxarea.begin = maxarea.end = currseq.max;
		maxarea.height = heights[currseq.max];
		maxarea.CalArea();
		maxarea.index = currseq.max;

		Area currarea;
		int currindex;
		int left, right;
		int count = currseq.end - currseq.begin + 1;
		left = right = currseq.max;
		bool walkleft = true, walkright = true;
		for(int j = 0; j < count; ++j)
		{
			if(left == currseq.begin)
			{
				walkleft = false;
			}
			if(right == currseq.end)
			{
				walkright = false;
			}

			if(walkleft && !walkright)
			{
				currindex = --left;
				currarea = (right - left + 1) * heights[currindex];
			}
			else if(!walkleft && walkright)
			{
				currindex = ++right;
				currarea = (right - left + 1) * heights[currindex];
			}
			else if(walkleft && walkright)
			{
				if(heights[left - 1] >= heights[right + 1])
				{
					currindex = --left;
				}
				else
				{
					currindex = ++ right;
				}
				currarea = (right - left + 1) * heights[currindex];
			}
			// 单边搜索、左右两边搜索
			if(i == 0)
			{
				currindex = currseq.max;
				currarea = heights[currseq.max] * (right - left + 1);
				if(currindex != currseq.begin)
				{
					left = currindex - 1;
				}
				else
				{
					left = currindex;
				}

				if(currindex != currseq.end)
				{
					right = currindex + 1;
				}
				else
				{
					right = currindex;
				}
			}
			else
			{
				if(right != currseq.end)
				{
					if(heights[right] >= heights[left])
					{
						currindex = right++;
					}
					else
					{
						currindex = left--;
					}
				}
				else if(left != currseq.begin)
				{
					if(heights[left] >= heights[right])
					{
						currindex = left--;
					}
					else
					{
						currindex = right++;
					}
				}
			}

			if(heights[left] > heights[right])
			{
				currindex = left;
				currarea = heights[currindex] * (currindex - right + 1);
			}
		}
	}
	return 0;
}
*/

int largestRectangleArea(vector<int>& heights)
{
	int ret  = 0;
	stack<int> si;
	for(int i = 0; i < heights.size(); ++i)
	{
		while(!si.empty() && heights[si.top()] >= heights[i])
		{
			int h = heights[si.top()];
			si.pop();

			int area = h * (si.empty() ? i : (i - si.top() - 1));
			ret = max(ret, area);
		}

		si.push(i);
	}

	while(!si.empty())
	{
		int h = heights[si.top()];
		si.pop();
		int area = h * (si.empty() ? heights.size() : (heights.size() - si.top() - 1));
		ret = max(ret, area);
	}

	return ret;
}

void BLargestRectangleAreaTest()
{
	vector<int> vi;
	int ret;

	cout << "test case 1" << endl;
	vi = {};
	ret = largestRectangleArea(vi);
	assert(ret == 0);
	cout << ret << endl;

	cout << "test case 2" << endl;
	vi = {4};
	ret = largestRectangleArea(vi);
	//assert(ret == 4);
	cout << ret << endl;

	cout << "test case 3" << endl;
	vi = {2,1,5,6,2,3};
	ret = largestRectangleArea(vi);
	//assert(ret == 10);
	cout << ret << endl;

	cout << "test case 4" << endl;
	vi = {1, 2, 3, 4, 5};
	ret = largestRectangleArea(vi);
	//assert(ret == 9);
	cout << ret << endl;

	cout << "test case 5" << endl;
	vi = {5, 4, 3, 2, 1};
	ret = largestRectangleArea(vi);
	//assert(ret == 9);
	cout << ret << endl;

	cout << "test case 6" << endl;
	vi = {1, 2, 1, 4, 2};
	ret = largestRectangleArea(vi);
	//assert(ret == 9);
	cout << ret << endl;

	cout << "test case 7" << endl;
	vi = {3, 2, 1, 2, 3, 4, 3, 5, 6, 4, 3, 4, 2, 1};
	ret = largestRectangleArea(vi);
	//assert(ret == 9);
	cout << ret << endl;

}

void LargestRectangleAreaTest()
{
	BLargestRectangleAreaTest();
}

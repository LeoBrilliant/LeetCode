/*
 * DataStruct.h
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#ifndef DATASTRUCT_H_
#define DATASTRUCT_H_

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * GenListFromVector(vector<int> & nums);

void DumpListNode(ListNode * head);

void DumpListNode(ListNode * head, ListNode * tail);

template<typename T>
void DumpVector(vector<T> & vt)
{
	cout << '[';
	for(auto t : vt)
	{
		cout << t << ", ";
	}
	cout << "]" << endl;
}

template<typename T>
void DumpVectorOfVector(vector<vector<T>> & vvt)
{
	cout << "[" << endl;
	for(auto vt : vvt)
	{
		DumpVector(vt);
	}
	cout << "]" << endl;
}

#endif /* DATASTRUCT_H_ */

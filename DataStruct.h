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
#include "DataStructures/VectorFuncs.h"
#include "DataStructures/Interval.h"
#include "DataStructures/Tree.h"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode * GenListFromVector(vector<int> & nums);

void DumpListNode(ListNode * head);

void DumpListNode(ListNode * head, ListNode * tail);

#endif /* DATASTRUCT_H_ */

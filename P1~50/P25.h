/*
 * P25.h
 *
 *  Created on: 2016年10月15日
 *      Author: LeoBrilliant
 */

#ifndef P25_H_
#define P25_H_

#include "Common.h"

// 翻转[head, tail]之间的结点
pair<ListNode *, ListNode *> ReverseList(ListNode * head, ListNode * tail)
{
	pair<ListNode *, ListNode *> ret;
	if(head == NULL || head->next == NULL || head == tail)
	{
		ret = make_pair(head, head);
	}
	else
	{
		if(tail == NULL)
		{
			tail = head;
			while(tail->next)
				tail = tail->next;
		}
		ListNode * prev = head;
		ListNode * curr = prev->next;
		ListNode * next = curr ? curr->next : NULL;
		for(; curr && prev != tail; )
		{
			if(prev == head)
				prev->next = tail->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			if(next)
				next = next->next;
		}

		ret = make_pair(tail, head);
	}

	return ret;
}

//获取从head开始的k个结点
pair<ListNode *, ListNode *> GetKNodes(ListNode * l, int k)
{
	pair<ListNode*, ListNode *> ret;
	ListNode * head = l;
	ListNode * tail = l;
	while(k > 1 && tail)
	{
		tail = tail->next;
		k --;
	}

	ret = make_pair(head, tail);

	return ret;

}

ListNode* reverseKGroup(ListNode* head, int k) {
	pair<ListNode *, ListNode *> ret;
	ListNode * h = NULL, * tail;
	while(head)
	{
		ret = GetKNodes(head, k);
		if(ret.second)
		{
			ret = ReverseList(ret.first, ret.second);
			if(!h)
			{
				h = ret.first;
			}
			else
			{
				tail->next = ret.first;
			}
			head = ret.second->next;
			tail = ret.second;
		}
		else
		{
			if(!h)
				h = head;
			tail->next = ret.first;
			break;
		}
	}

	return h;
}

void GetKNodesTest()
{
	vector<int> vi;
	int k;

	vi = {1, 3};
	k = 1;

	vi = {1};
	k = 1;

	vi = {1, 3, 5, 7, 9};
	k = 3;

	vi = {1, 3, 5};
	k = 4;

	ListNode * l = GenListFromVector(vi);

	DumpListNode(l);

	pair<ListNode *, ListNode *> ret = GetKNodes(l, k);

	DumpListNode(ret.first, ret.second);

}


void ReverseListTest()
{
	vector<int> vi;

	vi = {1, 3};

	vi = {1, 3, 5};

	//vi = {};

	//vi = {1};

	//vi = {1, 3, 5, 7, 9};
	ListNode * l = GenListFromVector(vi);

	DumpListNode(l);

	ListNode * l1 = ReverseList(l, NULL).first;

	DumpListNode(l1);

	l1 = ReverseList(l1, l1->next).first;

	DumpListNode(l1);
}

void ReverseKGroupTest()
{
	//GetKNodesTest();

	vector<int> vi;
	int k;

	vi = {1, 3, 5, 7, 9};
	k = 3;

	vi = {1, 3, 5, 7, 9};
	k = 2;

	vi = {1, 3, 5, 7, 9};
	k = 1;

	vi = {1, 3, 5, 7, 9};
	k = 4;

	vi = {1, 3, 5, 7, 9};
	k = 5;

	vi = {1, 3, 5, 7, 9};
	k = 6;

	vi = {};
	k = 1;
	ListNode * l = GenListFromVector(vi);

	DumpListNode(l);

	l = reverseKGroup(l, k);

	DumpListNode(l);
}

#endif /* P25_H_ */

/*
 * PartitionList.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"

ListNode* partition(ListNode* head, int x) {
	if(!head || !head->next)
		return head;

	ListNode * l, * li, * g, * gi;
	l = li = g = gi = NULL;

	while(head)
	{
		if(head->val < x)
		{
			if(li)
			{
				li->next = head;
				li = li->next;
			}
			else
			{
				l = li = head;
			}
			head = head->next;
			li->next = NULL;
		}
		else
		{
			if(gi)
			{
				gi->next = head;
				gi = gi->next;
			}
			else
			{
				g = gi = head;
			}
			head = head->next;
			gi->next = NULL;
		}
	}

	if(!l) return g;

	li->next = g;
	return l;
}

void PartitionListTest()
{
	ListNode * head;
	vector<int> vi;
	int x;
	ListNode * ret;

	cout << "test case 1" << endl;
	vi = {};
	head = GenListFromVector(vi);
	x = 1;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 2" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 3;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 3" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 0;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 4" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 6;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 5" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 1;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 6" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 2;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);

	cout << "test case 6" << endl;
	vi = {1, 4, 3, 2, 5, 2};
	head = GenListFromVector(vi);
	x = 4;
	DumpListNode(head);
	ret = partition(head, x);
	DumpListNode(ret);
}

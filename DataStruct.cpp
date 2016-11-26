/*
 * DataStruct.cpp
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#include "DataStruct.h"
/*
ListNode * GenListFromVector(vector<int> & nums)
{
	if(nums.empty())
		return NULL;

	ListNode * head = NULL;
	ListNode * prev = head;
	for(auto v : nums)
	{
		ListNode * n = new ListNode(v);

		if(!prev)
		{
			head = n;
			prev = head;
		}
		else
		{
			prev->next = n;
			prev = n;
		}
	}

	return head;
}

void DumpListNode(ListNode * head)
{
	cout << '[' ;
	while(head)
	{
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << "^]" << endl;
}

void DumpListNode(ListNode * head, ListNode * tail)
{
	cout << '[' ;
	while(head)
	{
		cout << head->val << " -> ";

		if(head == tail)
			break;

		head = head->next;
	}
	cout << "^]" << endl;
}*/

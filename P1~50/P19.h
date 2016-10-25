/*
 * P19.h
 *
 *  Created on: 2016年10月12日
 *      Author: user
 */

#ifndef P19_H_
#define P19_H_

#include "Common.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {

	if(!head) return head;

	ListNode * prev = head;
	ListNode * second = head;
	int count = 0;
	for(int i = 0; prev != NULL; ++i)
	{
		prev = prev->next;
		if(i > n)
		{
			second = second->next;
		}
		count ++;
	}

	if(count == n)
	{
		head = second->next;
	}
	else
	{
		prev = second;
		second = second->next;
		prev->next = second->next;
	}


	delete second;
	second = NULL;

	return head;
}

void RemoveNthFromEndTest()
{
	vector<int> nums{1, 2, 3, 4, 5};
	ListNode * head = GenListFromVector(nums);
	int n = 2;
	n = 4;
	//n = 5;
	n = 1;
	DumpListNode(head);

	head = removeNthFromEnd(head, n);

	DumpListNode(head);
}

#endif /* P19_H_ */

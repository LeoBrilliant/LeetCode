/*
 * P24.h
 *
 *  Created on: 2016年10月14日
 *      Author: user
 */

#ifndef P24_H_
#define P24_H_

#include "Common.h"

ListNode* swapPairs(ListNode* head) {

	if(!head) return head;

	ListNode * curr = head;
	ListNode * tail = NULL;
	ListNode * first = head->next;
	ListNode * second = head;
	while(first)
	{
		curr = curr->next;
		if(curr)
			curr = curr->next;
		else
			break;

		if(head == second)
		{
			tail = head;
			head = first;
			first->next = second;
			second->next = curr;
		}
		else
		{

			tail->next = first;
			first->next = second;
			second->next = curr;
			tail = second;
		}

		second = second->next;
		if(second)
			first = second->next;
		else
			break;
	}

	return head;
}

void SwapPairsTest()
{
	vector<int> vi1 { 1, 3, 5, 7, 9};

	vi1 = {};

	vi1 = {1};

	vi1 = {1, 3};
	ListNode * l1 = GenListFromVector(vi1);

	DumpListNode(l1);

	l1 = swapPairs(l1);

	DumpListNode(l1);
}


#endif /* P24_H_ */

/*
 * P23.h
 *
 *  Created on: 2016年10月14日
 *      Author: user
 */

#ifndef P23_H_
#define P23_H_

#include "Common.h"

ListNode* mergeTwoListsCpy(ListNode* l1, ListNode* l2) {
	ListNode * head = NULL, * curr = NULL;
	while(l1 && l2)
	{
		if(l1->val <= l2->val)
		{
			if(!curr)
			{
				curr = l1;
				l1 = l1->next;
			}
			else {
				curr->next = l1;
				l1 = l1->next;
				curr = curr->next;
			}
			curr->next = NULL;
		}
		else
		{
			if(!curr)
			{
				curr = l2;
				l2 = l2->next;
			}
			else{
				curr->next = l2;
				l2 = l2->next;
				curr = curr->next;
			}
			curr->next = NULL;
		}
		if(!head)
			head = curr;
	}

	if(curr)
	{	//curr = curr->next;

		if(l1 && curr->next == NULL)
			curr->next = l1;
		if(l2 && curr->next == NULL)
			curr->next = l2;
	}
	else
	{
		head = l1 ? l1 : l2;
	}

	return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {

	ListNode * head = NULL;
	for(auto l : lists)
	{
		head = mergeTwoListsCpy(head, l);
	}

	return head;
}

ListNode* mergeKLists2(vector<ListNode*>& lists) {

	ListNode * head = NULL;
	while(!lists.empty())
	{
		if(lists.size() >= 2)
		{
			ListNode * l1 = lists[0];
			ListNode * l2 = lists[1];
			head = mergeTwoListsCpy(l1, l2);
			lists.erase(lists.begin());
			lists.erase(lists.begin());
			lists.push_back(head);
		}
		else
		{
			head = lists[0];
			lists.erase(lists.begin());
		}
	}
	return head;
}

void MergeKListsTest()
{
	vector<int> vi1 { 1, 3, 5, 7, 9};
	vector<int> vi2 { 2, 4, 6, 8, 10};
	vector<int> vi3 {};

	vi1 = {};
	vi2 = {};

	vi1 = {1, 2 , 3};
	vi2 = {};

	vi1 = {1, 5};
	//vi2 = {3, };

	vi3 = {2, 6, 7};

	ListNode * l1 = GenListFromVector(vi1);
	ListNode * l2 = GenListFromVector(vi2);
	ListNode * l3 = GenListFromVector(vi3);

	DumpListNode(l1);
	DumpListNode(l2);
	DumpListNode(l3);

	vector<ListNode *> lists{l1, l2};

	lists.push_back(l3);

	ListNode * l = mergeKLists2(lists);

	DumpListNode(l);
}



#endif /* P23_H_ */

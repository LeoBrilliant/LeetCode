/*
 * RemoveDuplicatesFromSortedListII.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"


static ListNode* deleteDuplicates(ListNode* head) {
	if(!head)
		return head;

	ListNode * Insert = NULL, * Scan, *curr, * ret = NULL;
	Scan = head;

	while(Scan)
	{
		curr = Scan;
		Scan = Scan->next;
		while(Scan && curr->val == Scan->val)
			Scan = Scan->next;

		if(curr->next == Scan)
		{
			if(!Insert)
			{
				Insert = curr;
				ret = curr;
			}
			else
			{
				Insert->next = curr;
			}
			Insert = curr;
			Scan = Insert->next;
			Insert->next = NULL;
		}
		else
		{
			continue;
		}
	}

	return ret;
}

void DeleteDuplicatesTest()
{
	ListNode * head;
	vector<int> vi;
	ListNode * ret;

	cout << "test case 1" << endl;
	vi = {};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	assert(ret == head);
	DumpListNode(ret);

	cout << "test case 2" << endl;
	vi = {1, 2, 3, 3, 4, 4, 5};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	assert(ret == head);
	DumpListNode(ret);

	cout << "test case 3" << endl;
	vi = {1, 1, 1, 2, 3};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	//assert(ret == head);
	DumpListNode(ret);


	cout << "test case 4" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	assert(ret == head);
	DumpListNode(ret);

	cout << "test case 5" << endl;
	vi = {1, 2, 3, 3, 3, 4, 4, 5, 6, 6};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	assert(ret == head);
	DumpListNode(ret);

	cout << "test case 6" << endl;
	vi = {1, 2, 3, 3, 3, 4, 4, 5, 6, 6, 7, 8, 8};
	head = GenListFromVector(vi);
	DumpListNode(head);
	ret = deleteDuplicates(head);
	assert(ret == head);
	DumpListNode(ret);
}

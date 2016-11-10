/*
 * RemoveDuplicatesFromSortedList.cpp
 *
 *  Created on: 2016年11月10日
 *      Author: user
 */

#include "P51~100.h"


ListNode* deleteDuplicates(ListNode* head) {
	if(!head)
		return head;

	ListNode * Scan;
	Scan = head;

	while(Scan)
	{
		if(Scan->next)
		{
			if(Scan->val == Scan->next->val)
			{
				Scan->next = Scan->next->next;
			}
			else
			{
				Scan = Scan->next;
			}
		}
		else
		{
			break;
		}
	}

	return head;
}

void DeleteDuplicatesTestII()
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





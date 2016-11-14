/*
 * ReverseLinkedListII.cpp
 *
 *  Created on: 2016年11月11日
 *      Author: user
 */

#include "P51~100.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
	if(m == n)
		return head;

	ListNode * prev, * curr, * next, * revhead, * revtail;
	int counter = 0;
	prev = curr = next = revhead = revtail = NULL;
	curr = head;
	while(curr && counter < n)
	{
		counter ++;
		next = curr->next;

		if(counter == m - 1)
		{
			prev = curr;
		}

		if(counter >= m && counter <= n)
		{
			if(!revtail)
			{
				revtail = revhead = curr;
				revtail->next = NULL;
			}
			else
			{
				curr->next = revhead;
				revhead = curr;
			}
		}
		curr = next;
	}

	if(m != 1)
	{
		prev->next = revhead;
	}
	else
	{
		head = revhead;
	}
	revtail->next = next;

	return head;
}

void ReverseLinkedListIITest()
{
	vector<int> vi;
	ListNode * head, * ret;
	int m;
	int n;

	cout << "test case 1" << endl;
	vi = {1};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 1;
	n = 1;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);

	cout << "test case 2" << endl;
	vi = {1, 2};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 1;
	n = 2;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);

	cout << "test case 3" << endl;
	vi = {1, 2, 3, 4, 5};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 1;
	n = 2;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);

	cout << "test case 4" << endl;
	vi = {1, 2, 3, 4, 5};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 2;
	n = 4;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);

	cout << "test case 5" << endl;
	vi = {1, 2, 3, 4, 5};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 4;
	n = 5;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);

	cout << "test case 6" << endl;
	vi = {1, 2, 3, 4, 5};
	head = GenListFromVector(vi);
	DumpListNode(head);
	m = 1;
	n = 5;
	ret = reverseBetween(head, m, n);
	DumpListNode(ret);
}

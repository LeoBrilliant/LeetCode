/*
 * RotateList.cpp
 *
 *  Created on: 2016年11月7日
 *      Author: LeoBrilliant
 */

#include "P51~100.h"

int GetListNodeCount(ListNode * head)
{
	int count = 0;
	while(head)
	{
		head = head->next;
		count ++;
	}
	return count;
}

ListNode* rotateRight(ListNode* head, int k) {

	int n = GetListNodeCount(head);

	if(n <= 1 || k % n == 0)
		return head;

	k = k % n;

	ListNode * fast, * slow;
	int i = 0;
	fast = head;
	while(fast->next)
	{
		fast = fast->next;
		i++;
		if(i == k)
		{
			slow = head;
		}
		else if(i > k)
		{
			slow = slow->next;
		}
	}

	fast->next = head;
	head = slow->next;
	slow->next = NULL;

	return head;
}

void RotateRightTest()
{
	vector<int> nums;
	ListNode * head ;
	int k;

	cout << "test case 1" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 2;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 2" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 0;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 3" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 5;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 4" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 4;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 5" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 1;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 6" << endl;
	nums = 	{1, 2, 3, 4, 5};
	k = 0;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 7" << endl;
	nums = 	{1};
	k = 2;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);

	cout << "test case 8" << endl;
	nums = 	{};
	k = 2;
	head = GenListFromVector(nums);
	head = rotateRight(head, k);
	DumpListNode(head);
}

/*
 * P21.h
 *
 *  Created on: 2016年10月13日
 *      Author: user
 */

#ifndef P21_H_
#define P21_H_

#include "Common.h"

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
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

void MergeTwoListsTest()
{
	vector<int> vi1 { 1, 3, 5, 7, 9};
	vector<int> vi2 { 2, 4, 6, 8, 10};

	//vi1 = {};
	//vi2 = {};

	//vi1 = {1, 2 , 3};
	//vi2 = {};

	//vi1 = {1, 5};
	//vi2 = {3, };
	ListNode * l1 = GenListFromVector(vi1);
	ListNode * l2 = GenListFromVector(vi2);

	DumpListNode(l1);
	DumpListNode(l2);

	ListNode * l = mergeTwoLists(l1, l2);

	DumpListNode(l);

	string s = "cba";

	sort(s.begin(), s.end());

	cout << s << endl;
}



#endif /* P21_H_ */

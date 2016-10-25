/*
 * P234.h
 *
 *  Created on: 2016年10月5日
 *      Author: LeoBrilliant
 */

#ifndef P234_H_
#define P234_H_

#include <iostream>
#include <list>
#include "Common.h"

using namespace std;

/*
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
*/
//这里想错了，不是判断单链表中有没有环，而是看是不是回文单链表
/*
bool isPalindrome(ListNode* head) {
	ListNode * slow = head, * fast = head;
	bool ret = false;
	while(slow && fast)
	{
		if(slow->next)
		{
			slow = slow->next;
			if(fast->next && fast->next->next)
			{
				fast = fast->next->next;
			}
			else
			{
				ret = false;
				break;
			}
		}
		else
		{
			ret = false;
			break;
		}
		if(slow == fast)
		{
			ret = true;
			break;
		}
	}
	return ret;
}
*/

bool isPalindromeList(list<int> & ln)
{
	bool ret = false;
	int h, t;
	{
		while(ln.size() > 1)
		{
			h = ln.front();
			t = ln.back();
			if(h != t)
			{
				break;
			}
			ln.pop_back();
			ln.pop_front();
		}

		if(ln.empty() || ln.size() == 1)
		{
			ret = true;
		}
	}
	return ret;
}

//算法有点慢，但是accepted，不容易错
bool isPalindrome(ListNode* head) {
	bool ret = false;
	list<ListNode*> ln;
	ListNode * h, * t;
	h = head;
	while(h)
	{
		ln.push_back(h);
		h = h->next;
	}

	if(ln.empty() || ln.size() == 1)
	{
		ret = true;
	}
	else
	{
		while(ln.size() > 1)
		{
			h = ln.front();
			t = ln.back();
			if(h->val != t->val)
			{
				break;
			}
			ln.pop_back();
			ln.pop_front();
		}
		ret = true;
	}
	return ret;
}

void IsPalindromeTest()
{
	list<int> li{1, 2};
	bool result = false;
	result = isPalindromeList(li);

	cout << result << endl;
}
#endif /* P234_H_ */

/*
 * AddTwoNumbers.h
 *
 *  Created on: 2016Äê6ÔÂ22ÈÕ
 *      Author: user
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

#include <vector>
#include <map>
#include <assert.h>
#include <memory.h>
#include <string>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode * result, *lastbit, *bit;
		int addend, augend;
		int carry, sum;
		carry = sum = 0;
		result = lastbit = bit = NULL;
		while(l1 != NULL || l2 != NULL)
		{
			if(l1)
			{
				addend = l1->val;
				l1 = l1->next;
			}
			else
			{
				addend = 0;
			}

			if(l2)
			{
				augend = l2->val;
				l2 = l2->next;
			}
			else
			{
				augend = 0;
			}

			sum = (addend + augend + carry) % 10;
			carry = (addend + augend + carry) / 10;

			bit = new ListNode(sum);
			if(result == NULL){
				result = bit;
				lastbit = bit;
			}
			else
			{
				lastbit->next = bit;
				lastbit = bit;
			}
		}

		if(carry){
			bit = new ListNode(carry);
			lastbit->next = bit;
			lastbit = bit;
		}

		return result;
	}

	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {

		ListNode * result, *lastbit, *bit;
		int addend, augend;
		int carry, sum;
		carry = sum = 0;
		result = lastbit = bit = NULL;
		result = l1;
		while(l1 != NULL || l2 != NULL)
		{
			if(l1)
			{
				addend = l1->val;
				//l1 = l1->next;
			}
			else
			{
				addend = 0;
			}

			if(l2)
			{
				augend = l2->val;
				//l2 = l2->next;
			}
			else
			{
				augend = 0;
			}

			sum = (addend + augend + carry) % 10;
			carry = (addend + augend + carry) / 10;

			//bit = new ListNode(sum);
			l1->val = sum;
			lastbit = l1;

			if(l1->next){
				l1 = l1->next;
			}
			else
			{
				if(l2){
				l1->next = l2->next;
				l1 = l1->next;
				l2 = NULL;
				}
				else
				{
					break;
				}
			}

			if(l2)
			{
				l2 = l2->next;
			}
		}

		if(carry){
			bit = new ListNode(carry);
			lastbit->next = bit;
			lastbit = bit;
		}



		return result;
	}

	void AddTwoSumTest()
	{
		vector<int> nums1 {2, 7, 3, 9};
		vector<int> nums2 {1}; //, 3, 6, 0, 2, 4


		ListNode * l1, *l2, *result, *node, *last;
		//vector<int> nums {3,2,4};
		//vector<int> nums {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};

		l1 = l2 = NULL;
		for(auto &p : nums1)
		{
			node = new ListNode(p);
			if(l1 == NULL)
			{
				l1 = node;
				last = node;
			}
			else
			{
				last->next = node;
				last = node;
			}
		}
		for(auto &p : nums2)
		{
			node = new ListNode(p);
			if(l2 == NULL)
			{
				l2 = node;
				last = node;
			}
			else
			{
				last->next = node;
				last = node;
			}
		}

		result = this->addTwoNumbers2(l1, l2);

		node = result;
		while(node)
		{
			cout << node->val << "->";
			node = node->next;
		}
		cout << endl;
		//
		//		assert(result.size() == 2);
		//		assert(result[0] == 1);
		//		assert(result[1] == 2);



		std::cout << "Done" << std::endl;
	}
};

#endif /* ADDTWONUMBERS_H_ */

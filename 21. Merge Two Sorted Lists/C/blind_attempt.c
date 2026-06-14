/*
 * Time Complexity: O(n^2)
 * Space Complexity: O(log(n))
 * */

#include "shared.h"

struct ListNode* getTail(struct ListNode* curr) {
	while(curr != NULL && curr->next != NULL)
		curr = curr->next;
	return curr;
}

struct ListNode* partition(struct ListNode* head, struct ListNode* tail) {
	struct ListNode* pivot = head;

	struct ListNode* pre = head;
	struct ListNode* curr = head;

	while(curr != tail->next) {
		if(curr->val < pivot->val) {
			int temp = curr->val;
			curr->val = pre->next->val;
			pre->next->val = temp;

			pre = pre->next;
		}
		curr = curr->next;
	}

	int currData = pivot->val;
	pivot->val = pre->val;
	pre->val = currData;

	return pre;
}

void helper(struct ListNode* head, struct ListNode* tail) {
	if(head == NULL || head == tail) return;

	struct ListNode* pivot = partition(head, tail);

	helper(head, pivot);
	helper(pivot->next, tail);
}


struct ListNode* quicksort(struct ListNode* head) {
	struct ListNode* tail = getTail(head);
	helper(head, tail);
	return head;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;

	struct ListNode* result = list1;

	int size = 0;
	struct ListNode* prev = NULL;
	struct ListNode* curr = list1;
	while(curr != NULL) {
		++size;
		prev = curr;
		curr = curr->next;
	}
	prev->next = list2;

	quicksort(result);

	return result;
}

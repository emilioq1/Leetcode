/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */

#include "shared.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	struct ListNode* dummy = calloc(1, sizeof(struct ListNode));
	struct ListNode* curr = dummy;

	while(list1 != NULL && list2 != NULL) {
		if(list1->val > list2->val) {
			curr->next = list2;
			list2 = list2->next;
		}
		else {
			curr->next = list1;
			list1 = list1->next;
		}
		curr = curr->next;
	}
	curr->next = (list1 != NULL) ? list1 : list2;

	struct ListNode* head = dummy->next;
	free(dummy);
	return head;
}

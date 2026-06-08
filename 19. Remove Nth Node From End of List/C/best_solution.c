/*
 * Time complexity: O(N)
 * Space complexity: O(1)
 * */

#include "shared.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode dummy = {0, head};
	struct ListNode* fast = &dummy;
	struct ListNode* slow = &dummy;

	// Advance fast by n+1 steps
	for(int i = 0; i <= n; ++i) {
		fast = fast->next;
	}

	// Move both until fast hits the end
	while(fast != NULL) {
		fast = fast->next;
		slow = slow->next;
	}

	// slow is now the node before the target
	struct ListNode* to_free = slow->next;
	slow->next = to_free->next;
	free(to_free);

	return dummy.next;
}

#include "shared.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	if(head->next == NULL) return NULL;
	// if(n < 1) return NULL;
	struct ListNode* first = head;


	int sz = 0;
	while(head != NULL) {
		++sz;
		struct ListNode* next = head->next;
		if(next == NULL) break;
		head = next;
	}

	printf("sz: %d\n", sz);

	struct ListNode* prev = NULL;
	struct ListNode* curr = first;
	// struct ListNode* next = NULL;


	for(int i = 0; i < sz - n; ++i) {
		prev = curr;
		curr = curr->next;
		if(curr == NULL) return NULL;
	}

	struct ListNode* next = curr->next;
	free(curr);
	prev->next = next;

	return first;
}

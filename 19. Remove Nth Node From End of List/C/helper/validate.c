#include "../shared.h"

bool isCorrect(struct ListNode* a, struct ListNode* b) {
	while(a != NULL && b != NULL) {
		if(a->val != b->val) return false;
		a = a->next;
		b = b->next;
	}

	return a == NULL && b == NULL;
}

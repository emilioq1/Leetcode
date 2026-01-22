#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void printLinkedList(struct ListNode* l);

int getArraySize(int* arr) {
    int i = 0;

    while(arr[i] != -1) {
        ++i;
    }

    return i;
}

struct ListNode* createLinkedListFromArray(int* arr) {
    int size = getArraySize(arr) - 1;

    struct ListNode* result = NULL;
    struct ListNode* curr = NULL;
    for(int i = 0; i < size + 1; ++i) {
        struct ListNode* new_node = calloc(1, sizeof(struct ListNode));
        new_node->val = arr[i];
        new_node->next = NULL;

        if(result == NULL) {
            result = new_node; // first node
        }
        else {
            curr->next = new_node;
        }

        curr = new_node;
    }
    
    return result;
}

void printLinkedList(struct ListNode* l) {
    struct ListNode* temp = l;
    while(temp != NULL) {
        printf("%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = NULL;
    struct ListNode* curr = NULL;

    int sum = 0;
    int carry = 0;

    struct ListNode* l1_curr = l1;
    struct ListNode* l2_curr = l2;
    
    while(l1_curr != NULL || l2_curr != NULL || carry > 0) {
        struct ListNode* new_node = calloc(1, sizeof(struct ListNode));
        if(l1_curr == NULL && l2_curr == NULL && carry > 0) {
            new_node->val = carry;
            new_node->next = NULL;
            curr->next = new_node;
            break;
        }
        else if(l1_curr == NULL) {
            sum = l2_curr->val + carry;
        }
        else if(l2_curr == NULL) {
            sum = l1_curr->val + carry;
        }
        else {
            sum = l1_curr->val + l2_curr->val + carry;
        }
        
        new_node->val = sum % 10;
        carry = 0;

        if(sum > 9) {
            carry = sum / 10;
        }
        new_node->next = NULL;

        if(result == NULL) {
            result = new_node;
        }
        else {
            curr->next = new_node;
        }
            
        curr = new_node;
        
        if(l1_curr != NULL) {
            l1_curr = l1_curr->next;
        }
        if(l2_curr != NULL) {
            l2_curr = l2_curr->next;
        }
    }
 


    return result;
}



int main(void) {
    //int l1_int[] = {2, 4, 3, -1};
    //int l2_int[] = {5, 6, 4, -1};
    //int l1_int[] = {9, 9, 9, 9, 9, 9, 9, -1};
    //int l2_int[] = {9, 9, 9, 9, -1};
    int l1_int[] = {2, 4, 9, -1};
    int l2_int[] = {5, 6, 4, 9, -1};
    struct ListNode* l1 = createLinkedListFromArray(l1_int);
    struct ListNode* l2 = createLinkedListFromArray(l2_int);

    struct ListNode* result = addTwoNumbers(l1, l2);

    while(l1 != NULL) {
        struct ListNode* temp = l1;
        l1 = temp->next;
        free(temp);
    }

    while(l2 != NULL) {
        struct ListNode* temp = l2;
        l2 = temp->next;
        free(temp);
    }


    printLinkedList(result);

    while(result != NULL) {
        struct ListNode* temp = result;
        result = temp->next;
        free(temp);
    }


    return 0;
}

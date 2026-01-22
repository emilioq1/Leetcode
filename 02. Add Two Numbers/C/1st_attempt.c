#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int getArraySize(int* arr) {
    int i = 0;

    while(arr[i] != -1) {
        ++i;
    }

    return i;
}


int* convertNodesToIntArrays(struct ListNode* l) {
    int* l_numbers = calloc(1, sizeof(int));
    int i = 0;
    struct ListNode* prev;

    while(l != NULL) {
        l_numbers[i] = l->val;
        prev = l;
        l = l->next;

        free(prev);
        
        i++;
        l_numbers = realloc(l_numbers, sizeof(int) * (i + 1));
    }

    l_numbers = realloc(l_numbers, sizeof(int) * (i + 1));
    l_numbers[i] = -1;

    return l_numbers;
}

struct ListNode* createLinkedListFromArray(int* arr) {
    int size = getArraySize(arr);

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

void printIntArray(int* arr) {
    int i = 0;

    while(arr[i] != -1) {
        printf("%d", arr[i]);
        ++i;
    }
    printf("\n");
}

void printLinkedList(struct ListNode* l) {
    struct ListNode* temp = l;
    while(temp != NULL) {
        printf("%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int* addIntArrays(int* arr1, int* arr2) {
    int arr1_size = getArraySize(arr1);
    int arr2_size = getArraySize(arr2);
    int result_size = 0;

    if((arr1_size > arr2_size) || (arr1_size == arr2_size)) {
        result_size = arr1_size;
    }
    else {
        result_size = arr2_size;
    }

    int* result = calloc(1, sizeof(int));
    char sum_str[3] = {0};

    int sum = 0;
    int carry = 0;
    int i = 0;
    int j = 0;

    for(i = 0; i < result_size + 1; ++i) {
        result = realloc(result, sizeof(int) * (i + 1));

        if(arr1_size < (i + 1)) { // when array1 is smaller than array2
            if(arr2_size < (i + 1)) {
                result[i] = carry;
                break;
            }
            else {
                sum = arr2[j] + carry;
            }
        }
        else if(arr2_size < (i + 1)) { // when array2 is smaller than array1
            if(arr1_size < (i + 1)) {
                result[i] = carry;
                break;
            }
            else {
                sum = arr1[j] + carry;
            }
        }
        else { // normal case
            sum = arr1[j] + arr2[j] + carry;
        }


        if(snprintf(sum_str, 3, "%d", sum) == -1) {
            free(result);
            return NULL;
        }

        if(sum > 9) {
            carry = sum_str[0] - '0';
            result[i] = sum_str[1] - '0';
        }
        else {
            carry = 0;
            result[i] = sum_str[0] - '0';
        }
        
        ++j;
    }
    
    if(result[i] == 0) {  // when there is no carry at the end
        result[i] = -1;
    }
    else {  // when there is a carry at the end
        ++i;
        result = realloc(result, sizeof(int) * (i + 1));
        result[i] = -1;
    }

    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int* l1_int = convertNodesToIntArrays(l1);
    int* l2_int = convertNodesToIntArrays(l2);

    int* result_int = addIntArrays(l1_int, l2_int);
    if(result_int == NULL) {
        free(l1_int);
        free(l2_int);
        return NULL;
    }
    
    struct ListNode* result = createLinkedListFromArray(result_int);

    free(result_int);
    free(l1_int);
    free(l2_int);

    return result;
}



int main(void) {
    //int l1_int[] = {9, 9, 9, 9, 9, 9, 9, -1};
    //int l2_int[] = {9, 9, 9, 9, -1};
    int l1_int[] = {2, 4, 3, -1};
    int l2_int[] = {5, 6, 4, -1};
    //int l1_int[] = {2, 4, 9, -1};
    //int l2_int[] = {5, 6, 4, 9, -1};
    struct ListNode* l1 = createLinkedListFromArray(l1_int);
    struct ListNode* l2 = createLinkedListFromArray(l2_int);

    struct ListNode* result = addTwoNumbers(l1, l2);

    while(result != NULL) {
        struct ListNode* temp = result;
        result = temp->next;
        free(temp);
    }


    return 0;
}

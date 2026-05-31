#include "../shared.h"

int** convertToDoublePointer(int arr[TEST_CASES][MAX_SIZE], int sizes[]) {
	int** result = calloc(TEST_CASES, sizeof(int*));
	for(int i = 0; i < TEST_CASES; ++i) {
		result[i] = calloc(sizes[i], sizeof(int));
		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = arr[i][j];
		}
	}

	return result;
};

int*** convertToTriplePointer(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE],
							  int sizes[TEST_CASES],
							  int columnSizes[TEST_CASES][MAX_SIZE]) {
	int*** result = calloc(TEST_CASES, sizeof(int**));

	for(int i = 0; i < TEST_CASES; ++i) {
		result[i] = calloc(sizes[i], sizeof(int*));
		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = calloc(columnSizes[i][j], sizeof(int));
			for(int k = 0; k < columnSizes[i][j]; ++k) {
				result[i][j][k] = arr[i][j][k];
			}
		}
	}

	return result;
};

void free2dArray(void** array, int size) {
	for(int i = 0; i < size; ++i) {
		free(array[i]);
	}
	free(array);
}

void free3dArray(void*** array, int* sizes, int size) {
	for(int i = 0; i < size; ++i) {
		free2dArray(array[i], sizes[i]);
	}
	free(array);
}

bool inArray(int* array, int size, int item) {
	for(int i = 0; i < size; ++i) {
		if(array[i] == item) {
			return true;
		}
	}
	return false;
}


struct ListNode* allocateNode(int* items, int size, int offset) {
	if(offset >= size) return NULL;

	struct ListNode* node = malloc(sizeof(struct ListNode));
	node->val = items[offset];
	node->next = allocateNode(items, size, offset + 1);

	return node;
}


void printNode(struct ListNode* node) {
	printf("[");
	while(node != NULL) {
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("]");
}

void freeNode(struct ListNode* node) {
	if(node == NULL) return;
	struct ListNode* next = node->next;
	free(node);
	freeNode(next);
}

void freeNodes(struct ListNode* node[], int size) {
	for(int i = 0; i < size; ++i) {
		freeNode(node[i]);
	}
}

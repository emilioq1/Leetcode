#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

#define MAX_LENGTH 100000

#define PRINT(x) x ? x : 'N'

int maxArea(int* height, int heightSize) { return 0; }

#define TEST_CASES 2

void printArray(int* arr, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i + 1 == size) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}
	printf("]\n");
}

int main() {
	int cases[TEST_CASES][MAX_LENGTH] = {{1, 8, 6, 2, 5, 4, 8, 3, 7}, {1, 1}};
	int sizes[TEST_CASES] = {9, 2};
	int results[TEST_CASES] = {49, 1};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: ", i);
		printArray(cases[i], sizes[i]);

		int result = maxArea(cases[i], sizes[i]);
		printf("result: %d\n\n", result);

		if(results[i] != result) {
			printf(
				"---------------------TEST CASE FAILED---------------------\n");
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	return 0;
}

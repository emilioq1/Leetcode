#include "shared.h"

// unsigned long long factorial(int n) {
unsigned int factorial(int n) { return n <= 1 ? 1 : n * factorial(n - 1); }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize,
			  int** returnColumnSizes) {
	if(nums == NULL || numsSize <= 0) {
		return NULL;
	}

	// n!/r!(n-r)!
	unsigned int combinations =
		factorial(numsSize) / (factorial(4) * factorial(numsSize - 4));
	printf("combinations: %d\n", combinations);

	// int** result = (int**)malloc(sizeof(int*));
	int** result = (int**)malloc(combinations * sizeof(int*));
	result[0] = calloc(4, sizeof(int));
	*returnColumnSizes = calloc(1, sizeof(int*));
	*returnColumnSizes[0] = 4;
	*returnSize = 1;

	return result;
}

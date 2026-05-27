/*
 * Time complexity: O(N^3)
 * Space complexity: O(1)
 * */

#include "shared.h"
#include <stdlib.h>

int int_cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

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

	int capacity = 16;
	int** result = (int**)malloc(capacity * sizeof(int*));
	*returnColumnSizes = calloc(capacity, sizeof(int*));
	*returnSize = 0;

	if(numsSize < 4) {
		return result;
	}

	qsort(nums, numsSize, sizeof(int), int_cmp);

	printIntArray(nums, numsSize);
	printf("\n");

	// Every item is bigger than the target, thus there is no unique quadruplets
	// that add up to the target
	if(nums[0] > target && nums[0] >= 0) return result;

	for(int i = 0; i < numsSize - 3; ++i) {
		if(i > 0 && nums[i] == nums[i - 1]) continue;

		for(int j = i + 1; j < numsSize - 2; ++j) {
			if(j > i + 1 && nums[j] == nums[j - 1]) continue;

			int left = j + 1;
			int right = numsSize - 1;

			while(left < right) {
				long long sum =
					(long long)(nums[i] + nums[j] + nums[left] + nums[right]);

				if(sum == target) {
					if(*returnSize == capacity) {
						capacity *= 2;
						result =
							(int**)realloc(result, capacity * sizeof(int*));
						*returnColumnSizes = (int*)realloc(
							*returnColumnSizes, capacity * sizeof(int));
					}

					result[*returnSize] = (int*)malloc(4 * sizeof(int));

					result[*returnSize][0] = nums[i];
					result[*returnSize][1] = nums[j];
					result[*returnSize][2] = nums[left];
					result[*returnSize][3] = nums[right];

					(*returnColumnSizes)[*returnSize] = 4;
					*returnSize = *returnSize + 1;

					++left;
					--right;

					// Skip duplicate j values
					while(left < right && nums[left] == nums[left - 1])
						++left;

					// Skip duplicate k values
					while(left < right && nums[right] == nums[right + 1])
						--right;
				}
				else if(sum < target) {
					++left;
				}
				else {
					--right;
				}
			}
		}
	}

	return result;
}

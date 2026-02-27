/**
 * I looked at solutions in Leetcode to come up with this code.
 * My blind attempt is the optimal solution, so the changes are mostly for clarity.
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 * */
#include "shared.h"

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int capacity = 16;
	int** result = (int**)calloc(capacity, sizeof(int*));
	*returnColumnSizes = (int*)calloc(capacity, sizeof(int));
	*returnSize = 0;

	qsort(nums, numsSize, sizeof(int), cmp);

	for(int i = 0; i < numsSize - 2; ++i) {
		// skip duplicate anchor values
		if(i > 0 && nums[i] == nums[i - 1]) continue;

		int left = i + 1;
		int right = numsSize - 1;

		while(left < right) {
			int sum = nums[i] + nums[left] + nums[right];

			if(sum == 0) {
				if(*returnSize == capacity) {
					capacity *= 2;
					result = (int**)realloc(result, capacity * sizeof(int*));
					*returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
				}

				result[*returnSize] = (int*)malloc(3 * sizeof(int));

				result[*returnSize][0] = nums[i];
				result[*returnSize][1] = nums[left];
				result[*returnSize][2] = nums[right];

				(*returnColumnSizes)[*returnSize] = 3;
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
			else if(sum < 0) {
				++left;
			}
			else {
				--right;
			}
		}
	}

	return result;
}

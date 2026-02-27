/**
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 * */
#include "shared.h"

int partition(int* arr, int low, int high) {
	int pivot = arr[low];

	int i = low - 1;
	int j = high + 1;

	while(true) {
		do {
			++i;
		} while(arr[i] < pivot);

		do {
			--j;
		} while(arr[j] > pivot);

		if(i >= j) return j;

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void quicksort(int* arr, int low, int high) {
	if(low >= 0 && high >= 0 && low < high) {
		int p = partition(arr, low, high);
		quicksort(arr, low, p);
		quicksort(arr, p + 1, high);
	}
}

int* duplicateIntArray(int* arr, int numsSize) {
	int* result = malloc(numsSize * sizeof(int));

	for(int i = 0; i < numsSize; ++i) {
		result[i] = arr[i];
	}

	return result;
}


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

	if(numsSize == 3) {
		int sum = nums[0] + nums[1] + nums[2];

		if(sum == 0) {
			result[0] = (int*)malloc(3 * sizeof(int));

			result[0][0] = nums[0];
			result[0][1] = nums[1];
			result[0][2] = nums[2];

			*returnColumnSizes[0] = 3;
			*returnSize = 1;
		}

		return result;
	}

	quicksort(nums, 0, numsSize - 1);

	for(int i = 0; i < numsSize - 2; ++i) {
		// skip duplicate anchor values
		if(i > 0 && nums[i] == nums[i - 1]) continue;

		int j = i + 1;
		int k = numsSize - 1;

		while(j < k) {
			int sum = nums[i] + nums[j] + nums[k];

			if(sum == 0) {
				if(*returnSize == capacity) {
					capacity *= 2;
					result = (int**)realloc(result, capacity * sizeof(int*));
					*returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
				}

				result[*returnSize] = (int*)malloc(3 * sizeof(int));

				result[*returnSize][0] = nums[i];
				result[*returnSize][1] = nums[j];
				result[*returnSize][2] = nums[k];

				(*returnColumnSizes)[*returnSize] = 3;
				*returnSize = *returnSize + 1;

				++j;
				--k;

				// Skip duplicate j values
				while(j < k && nums[j] == nums[j - 1])
					++j;

				// Skip duplicate k values
				while(j < k && nums[k] == nums[k + 1])
					--k;
			}
			else if(sum < 0) {
				++j;
			}
			else {
				--k;
			}
		}
	}

	return result;
}

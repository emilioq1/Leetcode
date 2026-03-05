/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * */

#include "shared.h"

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int threeSumClosest(int* nums, int numsSize, int target) {
	if(numsSize == 3) {
		return nums[0] + nums[1] + nums[2];
	}

	int result = 0;

	int currentBestDiff = (MAX_TARGET_LENGTH - (MAX_NUM_LENGTH * 3)) + 1;
	int currentBestSum = (MAX_TARGET_LENGTH - (MAX_NUM_LENGTH * 3)) + 1;

	qsort(nums, numsSize, sizeof(int), cmp);
	printIntArray(nums, numsSize);
	printf("\n");

	for(int i = 0; i < numsSize - 2; ++i) {
		// skip duplicate anchor values
		// if(i > 0 && nums[i] == nums[i - 1]) continue;

		int left = i + 1;
		int right = numsSize - 1;


		while(left < right) {
			printf("i: %d\n", i);
			// printf("left: %d\n", left);
			// printf("right: %d\n", right);
			// printf("nums[i]: %d\n", nums[i]);
			// printf("nums[left]: %d\n", nums[left]);
			// printf("nums[right]: %d\n", nums[right]);

			int sum = nums[i] + nums[left] + nums[right];
			int diff = 0;
			if(sum > target) diff = sum - target;
			else diff = target - sum;

			printf("target: %d\n", target);
			printf("sum: %d\n", sum);
			printf("diff: %d\n\n", diff);
			printf("currentBestDiff: %d\n", currentBestDiff);


			if(diff < currentBestDiff) {
				if(diff == 0) return sum;

				currentBestDiff = diff;
				currentBestSum = sum;

				printf("currentBestDiff: %d\n", currentBestDiff);
				printf("currentBest: %d\n", currentBestSum);

				//++left;
				//--right;

				// Skip duplicate j values
				// while(left < right && nums[left] == nums[left - 1])
				//	++left;

				//// Skip duplicate k values
				// while(left < right && nums[right] == nums[right + 1])
				//	--right;
			}
			if(sum < target) {
				++left;
			}
			else {
				--right;
			}

			// printf("\n\n");
		}
	}
	printf("currentBestDiff: %d\n", currentBestDiff);
	printf("currentBest: %d\n", currentBestSum);

	result = currentBestSum;

	return result;
}

/**
 * Created by looking at solutions in leetcode
 * Basically the same implementation as my blind attempt, just cleaned up
 *
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * */

#include "shared.h"

int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int threeSumClosest(int* nums, int numsSize, int target) {
	if(numsSize == 3) {
		return nums[0] + nums[1] + nums[2];
	}

	qsort(nums, numsSize, sizeof(int), cmp);

	// Initial best guess
	int result = nums[0] + nums[1] + nums[2];

	for(int i = 0; i < numsSize - 2; ++i) {
		int left = i + 1;
		int right = numsSize - 1;

		while(left < right) {
			int sum = nums[i] + nums[left] + nums[right];

			int diff = 0;
			if(sum > target) diff = sum - target;
			else diff = target - sum;

			int bestDiff = 0;
			if(result > target) bestDiff = result - target;
			else bestDiff = target - result;

			if(diff < bestDiff) result = sum;

			if(sum == target) return target;
			else if(sum < target) ++left;
			else --right;
		}
	}

	return result;
}

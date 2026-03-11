#include "shared.h"
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	char letters[10][4] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	size_t digitsSize = strlen(digits);

	// Calculate result size and allocate memory for result
	size_t threeSize = digitsSize;
	size_t fours = 1;

	char* seven = strchr(digits, '7');
	if(seven != NULL) {
		fours *= 4;
		--threeSize;
	}

	char* nine = strchr(digits, '9');
	if(nine != NULL) {
		fours *= 4;
		--threeSize;
	}

	*returnSize = (int)pow((double)3, (double)threeSize) * fours;
	char** result = (char**)calloc(*returnSize, sizeof(char*));

	int* nums = (int*)malloc(digitsSize * sizeof(int));
	for(int i = 0; i < digitsSize; ++i) {
		nums[i] = digits[i] - '0';
	}

	int rIndex = 0;
	int rrIndex = 0;
	int cIndex = 0;

	char* first = letters[nums[0]];
	int fIndex = 0;

	// Each loop creates 1 combination
	while(rIndex < *returnSize) {
		result[rIndex] = (char*)calloc(MAX_LENGTH + 1, sizeof(char));
		result[rIndex][rrIndex] = first[fIndex];

		printf("result[%d][%d] = %c\n\n", rIndex, rrIndex, first[fIndex]);
		printf("cIndex: %d\n", cIndex);

		++rrIndex;

		for(int j = 1; j < digitsSize; ++j) {
			char* curr = letters[nums[j]];
			printf("curr: %s\n", curr);

			result[rIndex][rrIndex] = curr[cIndex];
			++rrIndex;
		}
		printf("\n");

		printf("result[%d]: %s\n\n\n", rIndex, result[rIndex]);

		++cIndex;
		++rIndex;
		rrIndex = 0;
		if((cIndex == 4 || cIndex == 3) || digitsSize == 1) {
			cIndex = 0;
			++fIndex;
		}
	}

	free(nums);

	return result;
}

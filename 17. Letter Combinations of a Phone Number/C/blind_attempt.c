#include "shared.h"
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	// char letters[10][4][1] = {{},
	//						  {},
	//						  {'a', 'b', 'c'},
	//						  {'d', 'e', 'f'},
	//						  {'g', 'h', 'i'},
	//						  {'j', 'k', 'l'},
	//						  {'m', 'n', 'o'},
	//						  {'p', 'q', 'r', 's'},
	//						  {'t', 'u', 'v'},
	//						  {'w', 'x', 'y', 'z'}};
	char letters[10][4] = {"",	  "",	 "abc",	 "def", "ghi",
						   "jkl", "mno", "pqrs", "tuv", "wxyz"};

	size_t digitsSize = strlen(digits);

	// Calculate result size and allocate memory for result
	size_t threeSize = digitsSize;
	// printf("digitsSize: %ld\n", digitsSize);

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
	// printf("returnSize: %d\n", *returnSize);

	char** result = (char**)calloc(*returnSize, sizeof(char*));

	for(int i = 0; i < *returnSize; ++i) {
		result[i] = (char*)calloc(MAX_LENGTH + 1, sizeof(char));
	}

	int* nums = (int*)malloc(digitsSize * sizeof(int));
	for(int i = 0; i < digitsSize; ++i) {
		nums[i] = digits[i] - '0';
		// printf("nums[%d]: %d\n", i, nums[i]);
	}

	int resultIndex = 0;
	int i = 0;
	int k = 0;

	char* first = letters[nums[0]];
	int firstIndex = 0;

	int l = 0;

	printf("BRO\n");

	// Each loop creates 1 combination
	// Increase i when letters[i] ends
	while(resultIndex < *returnSize) {
		// printf("HELLO\n");
		result[resultIndex][l] = first[firstIndex];
		printf("result[%d][%d] = %c\n\n", resultIndex, l, first[firstIndex]);
		++l;

		for(int j = 1; j < digitsSize; ++j) {
			char* curr = letters[nums[j]];
			printf("curr: %s\n", curr);

			result[resultIndex][l] = curr[k];
			++l;
		}
		printf("\n");

		printf("result[%d]: %s\n\n\n", resultIndex, result[resultIndex]);

		++k;
		++firstIndex;
		++resultIndex;
		l = 0;
		if(firstIndex == 4 || firstIndex == 3) {
			// result[resultIndex][l] = '\0';
			firstIndex = 0;
			// l = 0;
			k = 0;
		}
	}

	free(nums);

	return result;
}

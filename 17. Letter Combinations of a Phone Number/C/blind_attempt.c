#include "shared.h"
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	char* letters[10] = {"",	"",	   "abc",  "def", "ghi",
						 "jkl", "mno", "pqrs", "tuv", "wxyz"};
	size_t digitsSize = strlen(digits);
	if(digitsSize == 0) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = 1;
	for(int i = 0; i < digitsSize; ++i) {
		*returnSize *= strlen(letters[digits[i] - '0']);
	}

	char** result = (char**)calloc(*returnSize, sizeof(char*));

	for(int r = 0; r < *returnSize; ++r) {
		result[r] = calloc(digitsSize + 1, sizeof(char));
		int divisor = *returnSize;
		for(int j = 0; j < digitsSize; ++j) {
			char* curr = letters[digits[j] - '0'];
			int len = strlen(curr);
			divisor /= len;
			result[r][j] = curr[(r / divisor) % len];
		}
	}

	return result;
}

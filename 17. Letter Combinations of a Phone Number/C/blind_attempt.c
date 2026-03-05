#include "shared.h"

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
	size_t threeSize = digitsSize;
	printf("digitsSize: %ld\n", digitsSize);

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

	size_t allocSize = (int)pow((double)3, (double)threeSize) * fours;
	printf("resultSize: %ld\n", allocSize);

	char** result = (char**)calloc(allocSize, sizeof(char*));

	for(int i = 0; i < allocSize; ++i) {
		result[i] = (char*)calloc(MAX_LENGTH + 1, sizeof(char));
	}

	return result;
}

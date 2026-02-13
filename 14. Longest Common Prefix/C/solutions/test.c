/**
 * Used Divide and conquer approach
 *
 * Created from algorithm description
 *
 * Time complexity: O(n * m)
 *      n = number of strings
 *      m = length of shortest common prefix (at most length of first string)
 * Space complexity: O(1)
 * */

#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define TEST_CASES 3

void printArray(char** strs, int strsSize) {
	printf("[");
	for(int i = 0; i < strsSize; ++i) {
		if(i == strsSize - 1) {
			printf("%s", strs[i]);
		}
		else {
			printf("%s, ", strs[i]);
		}
	}
	printf("]\n");
}

int main() {
	char actualCases[TEST_CASES][MAX_LENGTH + 1][MAX_LENGTH + 1] = {
		{"flower", "flow", "flight"},
		{"dog", "racecar", "car"},
		{"flower", "flower", "flower", "flower"}};
	int sizes[TEST_CASES] = {3, 3, 4};

	char*** cases = calloc(TEST_CASES, sizeof(char**));
	for(int i = 0; i < TEST_CASES; ++i) {
		cases[i] = calloc(sizes[i], sizeof(char*));
		for(int j = 0; j < sizes[i]; ++j) {
			cases[i][j] = calloc(MAX_LENGTH + 1, sizeof(char));
			cases[i][j] = actualCases[i][j];
		}
	}

	char results[TEST_CASES][MAX_LENGTH + 1] = {"fl", "", "flower"};

	int i = 0;

	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: ", i);

		printArray(cases[i], sizes[i]);

		char* result = longestCommonPrefix(cases[i], sizes[i]);
		printf("result: %s\n\n", result);

		if(result == NULL || strncmp(results[i], result, MAX_LENGTH + 1)) {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
			// break;
		}
		else {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}
		free(result);

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	for(int i = 0; i < TEST_CASES; ++i) {
		free(cases[i]);
	}
	free(cases);

	return 0;
}

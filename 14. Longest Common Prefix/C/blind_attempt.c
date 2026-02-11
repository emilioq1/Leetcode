/**
 * Time complexity: O(N)
 * Space complexity: O(1)
 * */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define MAX_LENGTH 200

char* longestCommonPrefix(char** strs, int strsSize) { return NULL; }

#define TEST_CASES 2

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
	char actualCases[TEST_CASES][MAX_LENGTH + 1][MAX_LENGTH + 1] = {{"flower", "flow", "flight"},
																	{"dog", "racecar", "car"}};
	int sizes[TEST_CASES] = {3, 3};

	char*** cases = calloc(TEST_CASES, sizeof(char**));
	for(int i = 0; i < TEST_CASES; ++i) {
		cases[i] = calloc(sizes[i], sizeof(char*));
		for(int j = 0; j < sizes[i]; ++j) {
			cases[i][j] = calloc(MAX_LENGTH + 1, sizeof(char));
			cases[i][j] = actualCases[i][j];
		}
	}

	char results[TEST_CASES][MAX_LENGTH + 1] = {"fl", ""};

	int i = 0;

	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: ", i);

		printArray(cases[i], sizes[i]);

		char* result = longestCommonPrefix(cases[i], sizes[i]);
		printf("result: %s\n\n", result);

		if(result == NULL || strncmp(results[i], result, MAX_LENGTH + 1)) {
			printf(ANSI_COLOR_RED "---------------------TEST CASE "
								  "FAILED---------------------\n" ANSI_COLOR_RESET);
			// break;
		}
		else {
			printf(ANSI_COLOR_GREEN "-------------------TEST CASE "
									"SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	for(int i = 0; i < TEST_CASES; ++i) {
		free(cases[i]);
	}
	free(cases);

	return 0;
}

/**
 * Time complexity: O(S)? (I think its O(N))
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

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strsSize == 1) return strs[0];

	char* matchStr = strs[0];
	size_t matchStrSize = strnlen(matchStr, MAX_LENGTH);

	char* match = calloc(MAX_LENGTH + 1, sizeof(char));

	int matches = 0;
	int i = 0;

	for(i = 0; i < matchStrSize; ++i) {
		printf("matchStr[%d]: %c\n\n", i, matchStr[i]);
		for(int j = 0; j < strsSize; ++j) {
			printf("strs[%d][%d]: %c\n", j, i, strs[j][i]);
			if(matchStr[i] == strs[j][i]) {
				++matches;
			}
			else break;
		}
		printf("\n\n");
		if(matches == strsSize) {
			match[i] = matchStr[i];
			printf("match[%d]: %c\n\n", i, match[i]);
		}
		else {
			break;
		}
		matches = 0;
	}

	match[i] = '\0';


	printf("match: %s\n", match);
	printf("matchStr: %s\n", matchStr);

	return match;
}

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

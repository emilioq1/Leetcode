/**
 * My solution improved from looking at solutions in Leetcode.
 *
 * Time complexity: O(N)
 * Space complexity: O(1)
 * */

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define MAX_LENGTH 15

int romanToInt(char* s) {
	size_t sLen = strnlen(s, MAX_LENGTH);
	int result = 0;
	int current = 0;
	int prev = 0;

	for(int i = sLen - 1; i >= 0; --i) {
		switch(s[i]) {
			case 'I':
				current = 1;
				break;
			case 'V':
				current = 5;
				break;
			case 'X':
				current = 10;
				break;
			case 'L':
				current = 50;
				break;
			case 'C':
				current = 100;
				break;
			case 'D':
				current = 500;
				break;
			case 'M':
				current = 1000;
				break;
			default:
				break;
		}

		if(current < prev) {
			result -= current;
		}
		else {
			result += current;
		}

		prev = current;
	}

	return result;
}

#define TEST_CASES 3

int main() {
	char cases[TEST_CASES][MAX_LENGTH + 1] = {"III", "LVIII", "MCMXCIV"};
	int results[TEST_CASES] = {3, 58, 1994};

	int i = 0;

	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: %s\n\n", i, cases[i]);

		int result = romanToInt(cases[i]);
		printf("result: %d\n\n", result);

		if(results[i] != result) {
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


	return 0;
}

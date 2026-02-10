#define _GNU_SOURCE
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define MAX_LENGTH 15

int romanToInt(char* s) {
	size_t sLen = strnlen(s, MAX_LENGTH);
	int i = 0;
	int result = 0;

	for(int i = 0; i < sLen; ++i) {
		switch(s[i]) {
			case 'I':
				if(s[i + 1] == 'V') {
					result += 4;
					++i;
				}
				else if(s[i + 1] == 'X') {
					result += 9;
					++i;
				}
				else {
					result += 1;
				}
				break;
			case 'V':
				result += 5;
				break;
			case 'X':
				if(s[i + 1] == 'L') {
					result += 40;
					++i;
				}
				else if(s[i + 1] == 'C') {
					result += 90;
					++i;
				}
				else {
					result += 10;
				}
				break;
			case 'L':
				result += 50;
				break;
			case 'C':
				if(s[i + 1] == 'D') {
					result += 400;
					++i;
				}
				else if(s[i + 1] == 'M') {
					result += 900;
					++i;
				}
				else {
					result += 100;
				}
				break;
			case 'D':
				result += 500;
				break;
			case 'M':
				result += 1000;
				break;
			default:
				break;
		}
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

		printf("---------------------------------------------------------"
			   "\n\n");
	}


	return 0;
}

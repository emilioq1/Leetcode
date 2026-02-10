/**
 * My solution improved from looking at solutions in Leetcode.
 *
 * Time complexity: O(1)
 * Space complexity: O(1)
 * */

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L) &&              \
	!defined(__STRICT_ANSI__)
#define GNU11 1
#endif

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 3999

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

char* intToRoman(int num) {
	// Longest Roman numeral between 1 and 3999 is: 3888 = MMMDCCCLXXXVI
	char* result = calloc(16, sizeof(char));

	char romans[4][10][16] = {
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM"}};

	int temp = num;

	int thousands = (temp / 1000);
	temp -= thousands * 1000;
	int hundreds = (temp / 100);
	temp -= hundreds * 100;
	int tenths = (temp / 10);
	temp -= tenths * 10;
	int ones = temp;

	printf("thousands: %d\n", thousands);
	printf("hundreds: %d\n", hundreds);
	printf("tenths: %d\n", tenths);
	printf("ones: %d\n", ones);

	strcat(result, romans[3][thousands]);
	strcat(result, romans[2][hundreds]);
	strcat(result, romans[1][tenths]);
	strcat(result, romans[0][ones]);


	return result;
}

#define TEST_CASES 4

int main() {
	int cases[TEST_CASES] = {3749, 58, 1994, 1};
	char results[TEST_CASES][MAX_LENGTH] = {"MMMDCCXLIX", "LVIII", "MCMXCIV",
											"I"};

	int i = 0;


	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: %d\n\n", i, cases[i]);

		char* result = intToRoman(cases[i]);
		printf("result: %s\n\n", result);

		if(strncmp(results[i], result, MAX_LENGTH)) {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
			free(result);
			// break;
		}
		else {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
			free(result);
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}


	return 0;
}

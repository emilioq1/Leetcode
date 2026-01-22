#define _POSIX_C_SOURCE 200809L

// Solution derived from looking at solutions in Leetcode.

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_LENGTH 200

int myAtoi(char* s) {
	if(s[0] == '\0' || s == NULL) return 0;

	int i = 0;
	int sign = 1;

	// Skip leading whitespace
	printf("Skipping leading whitespace\n");
	while(s[i] == ' ')
		++i;
	printf("i at %d\n", i);

	// Check if at end
	if(s[i] == '\0') return 0;

	// Check for sign
	printf("Check for sign\n");
	if(s[i] == '+') ++i;
	else if(s[i] == '-') {
		sign = -1;
		++i;
	}
	printf("i at %d\n", i);
	// curr = s[i];

	long result = 0;
	// Parse digits
	printf("Parse digits\n;");
	for(int j = 0; s[i] != '\0' && isdigit(s[i]); ++j, ++i) {
		printf("i at %d\n", i);
		printf("j at %d\n", j);
		printf("curr: %c\n", s[i]);

		int digit = s[i] - '0';

		// Note: 9 digits is the length of INT32_MAX and INT32_MIN (excluding -)
		//
		// (j == 9 && s[i - j] > '2')
		//   - At length of the limits and the first digit is more than 2
		//   - Note: first digit of the limits is 2
		//
		// (j > 9 && s[i - j] != '0')
		//   - More than length of limits and the first digit is not zero
		//   - If first digit is zero, then the digits from the beginning to j
		//   are zeroes (leading zeroes which are ignored).
		//
		if((j == 9 && s[i - j] > '2') || (j > 9 && s[i - j] != '0')) {
			if(sign == -1) return INT32_MIN;
			else return INT32_MAX;
		}
		printf("digit: %d\n", digit);

		result = result * 10 + digit;
		printf("result: %ld\n\n", result);

		if(sign * result <= INT32_MIN) return INT32_MIN;
		if(sign * result >= INT32_MAX) return INT32_MAX;
	}

	return result * sign;
}

#define TEST_CASES 10

int main() {
	char* cases[TEST_CASES] = {"42",
							   "   -042",
							   "1337c0d3",
							   "0-1",
							   "words and 987",
							   "  0000000000012345678",
							   "+-12",
							   "    0000000000000   ",
							   "2147483800",
							   "-6147483648"};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("case: \"%s\"\n\n", cases[i]);
		int result = myAtoi(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

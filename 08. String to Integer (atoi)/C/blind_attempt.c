#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_LENGTH 200

int myAtoi(char* s) {
	// temp variable
	char curr = ' ';
	char prev = 0;

	// -1 -> negative
	// 0 -> unset
	// 1 -> positive
	int sign = 0;
	// true -> when you have parsed a digit
	// false -> when you haven't parsed a digit
	bool numParsed = false;
	// -1 -> indication to stop counting zeroes
	// - Counts the number of leading zeroes that are parsed
	// - Used as an offset to get rid of leading zeroes in fs
	int leadingZeroCount = 0;

	// Formatted string
	char fs[MAX_LENGTH] = {0};
	int fsLen = 0;

	int i = 0;
	while(curr != '\0') {
		// printf("curr[%d]: %c\n", i, curr);

		curr = s[i];

		if(curr == ' ') {
			// printf("is space\n");
			//  Stop parsing if a digit was parsed before
			if(numParsed || sign != 0) {
				break;
			}
		}
		if(curr == '-') {
			// printf("is negative\n");
			//  Stop parsing if a digit or sign was parsed before
			if(numParsed || sign != 0) {
				break;
			}
			sign = -1;
		}
		if(curr == '+') {
			// printf("is positive\n");
			// Stop parsing if a digit or sign was parsed before
			if(numParsed || sign != 0) {
				break;
			}
			sign = 1;
		}
		if(isdigit(curr)) {
			// printf("is digit\n");
			//  if(curr == '0' && leadingZeroCount != -1) ++leadingZeroCount;

			// Stop counting leading zeroes when you parse a digit
			// if(leadingZeroCount > 0 && curr != '0') {
			//	fsLen -= leadingZeroCount;
			//	leadingZeroCount = -1;
			//}
			//

			/**
			 * 1. prev == -1 && curr = digit =>  fs[fsLen] = curr;
			 * 2. leadZeroBlock && prev == '0' && curr == '0' => {
			 *      fsLen -= 1;
			 *      leadZeroBlock = true;
			 *    }
			 * 3. leadZeroBlock && prev == '' && curr == '0' => {
			 *      WOULD NEVER HAPPEN
			 *    }
			 * 4. leadZeroBlock && prev == '0' && curr == '' => {
			 *          fsLen -= 1;
			 *         leadZeroBlock = false;
			 *    }
			 *
			 * 5. !leadZeroBlock && prev == '0' && curr == '0' =>
			 *      nothing
			 * 6. !leadZeroBlock && prev == '' && curr == '0' =>
			 * 7. !leadZeroBlock && prev == '0' && curr == '' =>
			 * */

			// Cases:
			// - First two parsed digits are '0'.
			// - prev == '0' and curr == '0' in a leading zero block.
			if(prev == '0' && curr == '0' && leadingZeroCount != -1) {
				fsLen -= 1;
				++leadingZeroCount;
			}
			// Case: In a leading zero block, a non-zero digit is parsed.
			else if(prev == '0' && curr != '0' && leadingZeroCount != -1) {
				fsLen -= 1;
				leadingZeroCount = -1;
			}
			else if(curr != '0' && leadingZeroCount <= 0) {
				leadingZeroCount = -1;
			}

			fs[fsLen] = curr;
			numParsed = true;
			// printf("fs[%d]: %c\n", fsLen, fs[fsLen]);
			++fsLen;
		}
		if(isalpha(curr) || curr == '.') {
			// Always stop parsing if alphabetic character is parsed
			// printf("is alpha\n");
			break;
		}

		prev = s[i];
		++i;
	}

	if(sign == 0) sign = 1;

	printf("fs: %s\n", fs);
	printf("fsLen: %d\n", fsLen);
	// printf("leadingZeroCount: %d\n", leadingZeroCount);

	long result = 0;

	for(int i = 0; i < fsLen; ++i) {
		int32_t num = fs[i] - '0';
		int32_t power = fsLen - i - 1;

		if((power == 9 && num > 2) || power > 9) {
			return (sign == -1) ? INT32_MIN : INT32_MAX;
		}

		int32_t place = pow(10, power);
		long final = num * place;
		// printf("fs[%d]: %c\n", i, fs[i]);
		// printf("temp: %d\n", temp);
		// printf("powM: %d\n", powM);
		printf("final: %ld\n", final);
		result += final;

		if((result * sign) > INT32_MAX || (result * sign) < INT32_MIN) {
			return (sign == -1) ? INT32_MIN : INT32_MAX;
		}
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

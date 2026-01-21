#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define MAX_LENGTH 200

int myAtoi(char* s) {
	// temp variable
	char c = ' ';

	// -1 -> negative
	// 0 -> unset
	// 1 -> positive
	int sign = 0;
	// 1 when you have parsed a digit
	// 0 when you haven't parsed a digit
	int inNumBlock = 0;
	// counts the number of zeroes that are parsed
	// Used as an offset to get rid of leading zeroes in fs
	int zeroCounter = 0;

	// Formatted string
	char fs[MAX_LENGTH] = {0};
	int fsLen = 0;

	int i = 0;
	while(c != '\0') {
		printf("s[%d]: %c\n", i, c);
		c = s[i];

		if(c == ' ') {
			printf("is space\n");
			if(inNumBlock) {
				break;
			}
		}
		if(c == '-') {
			if(inNumBlock || sign != 0) {
				break;
			}
			printf("is negative\n");
			sign = -1;
		}
		if(c == '+') {
			if(inNumBlock || sign != 0) {
				break;
			}
			printf("is positive\n");
			sign = 1;
		}
		if(isdigit(c)) {
			printf("is digit\n");
			if(c == '0') ++zeroCounter;
			if(zeroCounter == fsLen && c != '0') {
				fsLen -= zeroCounter;
				zeroCounter = 0;
				fs[fsLen] = c;
				inNumBlock = 1;
				printf("fs[%d]: %c\n", fsLen, fs[fsLen]);
				++fsLen;
			}
			else {
				fs[fsLen] = c;
				printf("fs[%d]: %c\n", fsLen, fs[fsLen]);
				inNumBlock = 1;
				++fsLen;
			}
		}
		if(isalpha(c) || c == '.') {
			printf("is alpha\n");
			break;
		}

		++i;
	}
	fs[fsLen] = '\0';

	if(sign == 0) sign = 1;

	printf("fs: %s\n", fs);

	/*
	 * Oct   Dec   Hex   Char
	 * ───────────────────────
	 * 060   48    30    0
	 * 061   49    31    1
	 * 062   50    32    2
	 * 063   51    33    3
	 * 064   52    34    4
	 * 065   53    35    5
	 * 066   54    36    6
	 * 067   55    37    7
	 * 070   56    38    8
	 * 071   57    39    9
	 */

	long result = 0;

	if(fsLen > 10) {
		if(sign == -1) return INT32_MIN;
		else return INT32_MAX;
	}

	for(int i = 0; i < fsLen; ++i) {
		int32_t num = (fs[i] - '0');
		int32_t place = (int32_t)pow(10, (fsLen - i - 1));
		long final = num * place;
		// printf("fs[%d]: %c\n", i, fs[i]);
		// printf("temp: %d\n", temp);
		// printf("powM: %d\n", powM);
		printf("final: %ld\n", final);
		result += final;
		if(result * sign > INT32_MAX) {
			return INT32_MAX;
		}
		else if(result * sign < INT32_MIN) {
			return INT32_MIN;
		}
	}

	return result * sign;
}

#define TEST_CASES 8

int main() {
	char* cases[TEST_CASES] = {"42",
							   "   -042",
							   "1337c0d3",
							   "0-1",
							   "words and 987",
							   "  0000000000012345678",
							   "+-12",
							   "    0000000000000   "};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("case: \"%s\"\n\n", cases[i]);
		int result = myAtoi(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

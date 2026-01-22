#define _POSIX_C_SOURCE 200809L

#include <stdint.h>
#include <stdio.h>

/**
 * I looked at the solutions in Leetcode and implemented the best answer I
 * found.
 * */

int reverse(int x) {
	int32_t rev = 0;

	while(x != 0) {
		// pop
		int32_t pop = x % 10;
		x /= 10;

		if(rev > INT32_MAX / 10) {
			return 0;
		}
		if(rev < INT32_MIN / 10) {
			return 0;
		}

		// push
		rev = rev * 10 + pop;
	}

	return rev;
}

#define TEST_CASES 7

int main() {
	int cases[TEST_CASES] = {123,		  -123,		  120,		 1534236469,
							 -2147483412, 1563847412, -563847412};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE: %d\n\n", cases[i]);
		int result = reverse(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

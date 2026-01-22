/**
 * Solution improved from looking at solutions in Leetcode.
 *
 *
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 * */

#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool isPalindrome(int x) {
	if(x >= 0 && x < 10) return true;
	if(x < 0) return false;
	if(x % 10 == 0 && x != 0) return false;

	int xTemp = x;
	int reverse = 0;

	while(xTemp != 0) {
		int pop = xTemp % 10;
		xTemp /= 10;

		if(reverse > INT32_MAX / 10) return false;
		if(reverse < INT32_MIN / 10) return false;

		reverse = reverse * 10 + pop;
	}

	return (x == reverse);
}

#define TEST_CASES 3

int main() {
	int cases[TEST_CASES] = {121, -121, 10};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE: %d\n\n", cases[i]);
		int result = isPalindrome(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

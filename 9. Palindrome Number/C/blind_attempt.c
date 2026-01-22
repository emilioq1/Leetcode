#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(int x) {
	if(x < 10) return true;

	return false;
}

#define TEST_CASES 7

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

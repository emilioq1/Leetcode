/**
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 * */

#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool isMatch(char* s, char* p) { return false; }

#define TEST_CASES 3

int main() {
	char* s[TEST_CASES] = {"aa", "aa", "ab"};
	char* p[TEST_CASES] = {"a", "a*", ".*"};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\ts: \"%s\"\n", s[i]);
		printf("\tp: \"%s\"\n\n", p[i]);
		int result = isMatch(s[i], p[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* s) { return 0; }

#define TEST_CASES 5

int main() {
	char* cases[TEST_CASES] = {
		"42", "   -042", "1337c0d3", "0-1", "words and 987",
	};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("case: \"%s\"\n\n", cases[i]);
		int result = myAtoi(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

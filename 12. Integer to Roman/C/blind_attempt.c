#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L) &&              \
	!defined(__STRICT_ANSI__)
#define GNU11 1
#endif

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 3999

#define MIN(a, b) (((a) < (b)) ? (a) : (b))


char* intToRoman(int num) {
	char* result = calloc(MAX_LENGTH + 1, sizeof(char));

	return result;
}

#define TEST_CASES 3

int main() {
	int cases[TEST_CASES] = {3749, 58, 1994};
	char results[TEST_CASES][MAX_LENGTH] = {"MMMDCCXLIX", "LVIII", "MCMXCIV"};

	int i = 0;


	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: %d\n\n", i, cases[i]);

		char* result = intToRoman(cases[i]);
		printf("result: %s\n\n", result);

		if(strncmp(results[i], result, MAX_LENGTH)) {
			printf(
				"---------------------TEST CASE FAILED---------------------\n");
			free(result);
			break;
		}
		else {
			printf(
				"-------------------TEST CASE SUCCESS---------------------\n");
			free(result);
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}


	return 0;
}

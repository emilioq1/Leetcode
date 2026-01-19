#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 12

int reverse(int x) {
	char buffer[MAX_LENGTH + 1] = {0};

	int numChar = snprintf(buffer, MAX_LENGTH, "%d", x);
	if(numChar < 0) {
		return 0;
	}
	else if(numChar > MAX_LENGTH) {
		printf("String was truncated\n");
		return 0;
	}
	buffer[MAX_LENGTH] = '\0';

	printf("buffer: %s\n", buffer);

	char reverse[MAX_LENGTH + 1] = {0};
	int i = 0;
	int k = 0;

	if(buffer[0] == '-') {
		reverse[i++] = '-';
		++k;
	}

	for(int j = MAX_LENGTH; j >= k; --j) {
		printf("buffer[%d]: %c\n", j, buffer[j]);
		if(buffer[j] != 0) reverse[i++] = buffer[j];
	}
	buffer[MAX_LENGTH] = '\0';

	printf("reverse: %s\n", reverse);

	errno = 0;
	long result = strtoll(reverse, NULL, 10);
	if(errno == EINVAL) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	else if(errno == ERANGE) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}

	if(result < -2147483648 || result > 2147483647) {
		result = 0;
	}


	return result;
}

#define TEST_CASES 5

int main() {
	int cases[TEST_CASES] = {123, -123, 120, 1534236469, -2147483412};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		int result = reverse(cases[i]);
		printf("result: %d\n\n", result);

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

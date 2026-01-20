#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 12

int reverse(int x) {
	char buffer[MAX_LENGTH + 1] = {0};

	int32_t numChar = snprintf(buffer, MAX_LENGTH, "%d", x);
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
	int8_t i = 0;
	int8_t k = 0;

	if(buffer[0] == '-') {
		reverse[i++] = '-';
		++k;
	}

	for(int8_t j = MAX_LENGTH; j >= k; --j) {
		printf("buffer[%d]: %c\n", j, buffer[j]);
		if(buffer[j] != 0) reverse[i++] = buffer[j];
	}
	reverse[i] = '\0';

	int32_t length = strnlen(reverse, MAX_LENGTH + 1);
	printf("length: %d\n", length);

	printf("reverse: %s\n", reverse);

	int32_t result = 0;

	if(reverse[0] != '-') {
		if((int)reverse[0] > 50 && length > 10) {
			return result;
		}
	}
	else {
		if((int)reverse[1] > 50 && length > 10) {
			return result;
		}
	}

	char* endptr;

	/*
	 * 9646324351 base-10 = 10 00111110 11110111 00111010 01111111 base-2
	 * 1056389759 base-10 = 00 00111110 11110111 00111010 01111111 base-2
	 */

	errno = 0;
	result = strtol(reverse, &endptr, 10);
	printf("errno: %d\n", errno);
	if(errno == EINVAL) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	else if(errno == ERANGE) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", INT32_MAX);

	if(endptr == reverse) {
		printf("No digits were found.\n");
	}
	else if(*endptr != '\0') {
		printf("Invalid character: %c\n", *endptr);
	}
	else {
		printf("The number is: %d\n", result);
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

#define _POSIX_C_SOURCE 200809L

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * -2147483647
 * */
#define MAX_LENGTH 11

int reverse(int x) {
	char buffer[MAX_LENGTH + 1] = {0};

	int8_t len = snprintf(buffer, MAX_LENGTH + 1, "%d", x);
	if(len < 0) {
		return 0;
	}
	else if(len > MAX_LENGTH) {
		printf("String was truncated\n");
		return 0;
	}
	buffer[len] = '\0';

	printf("buffer: %s\n", buffer);
	printf("len: %d\n", len);

	char reverse[MAX_LENGTH + 1] = {0};
	int8_t start = 0;

	if(buffer[0] == '-') {
		reverse[start++] = '-';
	}

	char* maxIntString = "2147483647";
	if(start == 1) {
		maxIntString = "2147483648";
	}
	int isMaxLength = (len - start) >= (MAX_LENGTH - 1);

	for(int8_t j = len, k = start; j >= start; --j) {
		printf("buffer[%d]: %c\n", j, buffer[j]);
		if(buffer[j] != 0) {
			reverse[k] = buffer[j];
			if(isMaxLength) {
				if(reverse[k] < maxIntString[k - start]) {
					isMaxLength = 0;
				}
				else if(reverse[k] > maxIntString[k - start]) {
					return 0;
				}
			}

			printf("reverse[%d]: %c\n", k, reverse[k]);
			++k;
		}
	}
	reverse[len] = '\0';

	printf("reverse: %s\n", reverse);

	int32_t result = 0;

	// if(len - start >= MAX_LENGTH - 1) {
	//	char* maxIntString = "2147483647";
	//	if(start == 1) {
	//		maxIntString = "2147483648";
	//	}

	//	for(int8_t i = start; i < len; ++i) {
	//		printf("%c == %c\n", reverse[i], maxIntString[i - start]);
	//		if(reverse[i] < maxIntString[i - start]) {
	//			break;
	//		}
	//		else if(reverse[i] > maxIntString[i - start]) {
	//			return 0;
	//		}
	//	}
	//}

	char* endptr = NULL;

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

	if(endptr == reverse) {
		printf("No digits were found.\n");
	}
	else if(*endptr != '\0') {
		printf("Invalid character: %c\n", *endptr);
	}
	else {
		printf("The number is: %d\n", result);
	}

	if(result < INT32_MIN || result > INT32_MAX) {
		result = 0;
	}

	return result;
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

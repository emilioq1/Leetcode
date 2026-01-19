#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_ROWS 1000

char* convert(char* s, int numRows) {
	size_t sLength = strnlen(s, MAX_LENGTH + 1);

	if(sLength == 0) return NULL;
	if(numRows <= 0 || numRows > MAX_ROWS) return NULL;

	char* result = calloc(sLength + 1, sizeof(char));

	// If numRows is more than the string's length or numRows is 1,
	// then the same string would be returned.
	if(numRows == 1 || numRows >= sLength) {
		strncpy(result, s, sLength);
		return result;
	}

	size_t cycleLength = (2 * numRows) - 2;
	int i = 0;
	int currRow = 0;
	int currentRLen = 0;

	while(currentRLen < sLength) {
		int sIndex = (i * cycleLength) + currRow;
		int rIndex = currentRLen;

		if(sIndex < sLength) {
			result[rIndex] = s[sIndex];

			++currentRLen;
			sIndex = (i * cycleLength) + currRow;
			rIndex = currentRLen;

			int offset = cycleLength - (2 * currRow);

			// For the rows with single columns
			if(currRow > 0 && currRow < numRows - 1 &&
			   (sIndex + offset) < sLength) {
				result[rIndex] = s[sIndex + offset];

				++currentRLen;
			}

			++i;
		}
		else {
			++currRow;
			i = 0;
		}
	}

	result[currentRLen] = '\0';

	return result;
}

#define TEST_CASES 3

int main() {
	char stringTest[TEST_CASES][MAX_LENGTH + 1] = {
		{"PAYPALISHIRING"},
		{"PAYPALISHIRING"},
		{"A"},
	};

	int numTest[TEST_CASES] = {3, 4, 1};
	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("s: %s, numRows: %d\n", stringTest[i], numTest[i]);
		char* result = convert(stringTest[i], numTest[i]);
		printf("result: %s\n\n", result);

		printf("---------------------------------------------------------\n\n");

		if(result != NULL) free(result);
	}

	return 0;
}

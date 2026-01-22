#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_ROWS 1000

void printArray(char** arr, size_t numRows, size_t numCols) {
	for(int i = 0; i < numRows; ++i) {
		for(int j = 0; j < numCols; ++j) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
}

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

	size_t cycleLen = 2 * numRows - 2;

	size_t fullCycles = sLength / cycleLen;
	size_t rem = sLength % cycleLen;

	size_t numColumns = fullCycles * (numRows - 1);

	if(rem > 0) {
		if(rem <= (size_t)numRows) numColumns += 1;
		else numColumns += 1 + (rem - numRows);
	}


	int goingDown = 1;
	int row = 0;
	int col = 0;

	char** arr = calloc(numRows, sizeof(char*));
	for(int i = 0; i < numRows; ++i) {
		arr[i] = calloc(numColumns, sizeof(char));
	}

	for(int i = 0; i < sLength; ++i) {
		arr[row][col] = s[i];

		if(goingDown) {
			if(row == numRows - 1) {
				// Bounce at bottom; start going up diagonally
				goingDown = 0;
				--row; // move up
				++col; // and right
			}
			else {
				++row; // go down
			}
		}
		else {
			if(row == 0) {
				// Bounce at top; start going down
				goingDown = 1;
				++row; // go down
			}
			else {
				--row; // go up
				++col; // and right
			}
		}
	}

	int i = 0;
	int j = 0;
	int k = 0;

	while(i < numRows) {
		char curr = arr[i][j];
		if(curr != 0) {
			result[k] = curr;
			++k;
		}
		++j;
		if(j >= numColumns) {
			j = 0;
			++i;
		}
	}

	for(int i = 0; i < numRows; ++i) {
		free(arr[i]);
	}
	free(arr);

	return result;
}

#define TEST_CASES 4

int main() {
	char stringTest[TEST_CASES][MAX_LENGTH + 1] = {
		{"PAYPALISHIRING"},
		{"PAYPALISHIRING"},
		{"A"},
		{"ABC"},
	};

	int numTest[TEST_CASES] = {3, 4, 1, 2};
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

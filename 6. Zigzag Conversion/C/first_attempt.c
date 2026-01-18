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
	printf("sLength: %lu\n", sLength);

	if(sLength == 0) return NULL;
	if(numRows == 0) return NULL;

	char* result = calloc(sLength + 1, sizeof(char));

	// If numRows is more than the string's length or numRows is 1,
	// then the same string would be returned.
	if(numRows == 1 || numRows >= sLength) {
		strncpy(result, s, sLength);
		return result;
	}

	size_t betweenLength = 0;
	if(numRows > 1) {
		betweenLength = numRows - 2;
	}
	printf("betweenLength: %lu\n", betweenLength);

	// Count the inbetween numbers: (numColumns - 1) * betweenLength;
	size_t numFullColumns = (size_t)(floor((double)sLength / (double)numRows));
	size_t numSingleColumns = (numFullColumns - 1) * betweenLength;
	printf("numFullColumns: %lu\n", numFullColumns);
	printf("numSingleColumns: %lu\n", numSingleColumns);

	size_t numColumns = numFullColumns + numSingleColumns;
	printf("numColumns: %lu\n", numColumns);

	size_t offsetIndex = numRows + betweenLength;
	printf("offsetIndex: %lu\n\n", offsetIndex);

	size_t offset = 0;
	size_t j = 0;

	for(int i = 0; i < sLength; ++i) {
		printf("s[%d]:\t%c\n", i, s[i]);
	}
	printf("\n");

	// char** arr = calloc(numRows, sizeof(char*));
	// for(int i = 0; i < numRows; ++i) {
	//	arr[i] = calloc(numColumns, sizeof(char));
	//	for(int j = 0; j < numColumns; ++j) {
	//		int sIndex = (j * offset) + i;
	//		printf("sIndex: %d\n", sIndex);
	//		printf("s[%d]: %c\n", sIndex, s[sIndex]);
	//		if((j * 2) == sIndex) {
	//			arr[i][j] = s[sIndex];
	//		} else {
	//			arr[i][j] = '#';
	//		}
	//		printf("arr[%d][%d]: %c\n\n", i, j, arr[i][j]);
	//	}
	// }
	// printArray(arr, numRows, numColumns);
	// for(int i = 0; i < numRows; ++i) {
	//	free(arr[i]);
	// }
	// free(arr);

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

#include "../shared.h"
#include <string.h>

char***
converToTriplePointerChar(char arr[TEST_CASES][MAX_SIZE][MAX_LENGTH + 1],
						  int colSize[], int size) {
	char*** result = (char***)malloc(size * sizeof(char**));

	for(int i = 0; i < size; ++i) {
		result[i] = (char**)malloc(colSize[i] * sizeof(char*));

		for(int j = 0; j < colSize[i]; ++j) {
			result[i][j] = (char*)calloc((MAX_LENGTH + 1), sizeof(char));

			strncpy(result[i][j], arr[i][j], MAX_LENGTH + 1);
		}
	}

	return result;
}

int** convertToDoublePointerInt(int arr[TEST_CASES][MAX_SIZE], int sizes[]) {
	int** result = calloc(TEST_CASES, sizeof(int*));
	for(int i = 0; i < TEST_CASES; ++i) {
		result[i] = calloc(sizes[i], sizeof(int));
		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = arr[i][j];
		}
	}

	return result;
};

int*** convertToTriplePointerInt(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE],
								 int sizes[TEST_CASES],
								 int columnSizes[TEST_CASES][MAX_SIZE]) {
	int*** result = calloc(TEST_CASES, sizeof(int**));

	for(int i = 0; i < TEST_CASES; ++i) {
		result[i] = calloc(sizes[i], sizeof(int*));
		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = calloc(columnSizes[i][j], sizeof(int));
			for(int k = 0; k < columnSizes[i][j]; ++k) {
				result[i][j][k] = arr[i][j][k];
			}
		}
	}

	return result;
};

void free2dArray(void** array, int size) {
	for(int i = 0; i < size; ++i) {
		free(array[i]);
	}
	free(array);
}

void free3dArray(void*** array, int* sizes, int size) {
	for(int i = 0; i < size; ++i) {
		free2dArray(array[i], sizes[i]);
	}
	free(array);
}

bool inArray(int* array, int size, int item) {
	for(int i = 0; i < size; ++i) {
		if(array[i] == item) {
			return true;
		}
	}
	return false;
}

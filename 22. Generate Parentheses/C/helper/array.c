#include "../shared.h"

int** convertToDoublePointer(int arr[][MAX_SIZE], const int sizes[], int n) {
	int** result = calloc(n, sizeof(int*));
	if(!result) return NULL;

	for(int i = 0; i < n; ++i) {
		result[i] = calloc(sizes[i], sizeof(int));
		if(!result[i]) return NULL;
		memcpy(result[i], arr[i], sizes[i] * sizeof(int));
	}

	return result;
};

int*** convertToTriplePointer(int arr[][MAX_SIZE][MAX_SIZE], const int sizes[],
							  const int columnSizes[][MAX_SIZE], int n) {
	int*** result = calloc(n, sizeof(int**));
	if(!result) return NULL;

	for(int i = 0; i < n; ++i) {
		result[i] = calloc(sizes[i], sizeof(int*));
		if(!result[i]) return NULL;

		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = calloc(columnSizes[i][j], sizeof(int));
			if(!result[i][j]) return NULL;
			memcpy(result[i][j], arr[i][j], columnSizes[i][j] * sizeof(int));
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

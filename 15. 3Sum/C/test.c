#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"


void printArray(int* array, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i == size - 1) {
			printf("%d", array[i]);
		}
		else {
			printf("%d, ", array[i]);
		}
	}
	printf("]");
}

void print2dArray(int** array, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		printArray(array[i], sizes[i]);
		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]");
}

void print3dArray(int*** array, int** columnSizes, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		print2dArray(array[i], columnSizes[i], sizes[i]);

		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]\n");
}

#define TEST_CASES 3

int** convertToDoublePointer(int arr[TEST_CASES][MAX_SIZE], int sizes[]) {
	int** result = calloc(TEST_CASES, sizeof(int*));
	for(int i = 0; i < TEST_CASES; ++i) {
		result[i] = calloc(sizes[i], sizeof(int));
		for(int j = 0; j < sizes[i]; ++j) {
			result[i][j] = arr[i][j];
		}
	}

	return result;
};

int*** convertToTriplePointer(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE], int sizes[TEST_CASES],
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

bool isCorrect(int** a, int* aColumnSizes, int aSize, int** b, int* bColumnSizes, int bSize) {
	if(a == NULL || b == NULL) return false;
	if(aColumnSizes == NULL || bColumnSizes == NULL) return false;
	if(aSize != bSize) return false;

	for(int i = 0; i < aSize; ++i) {
		if(aColumnSizes[i] == bColumnSizes[i]) {
			for(int j = 0; j < aColumnSizes[i]; ++j) {
				if(a[i][j] != b[i][j]) {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}

	return true;
}

int main() {
	static int cases[TEST_CASES][MAX_SIZE] = {{-1, 0, 1, 2, -1, -4}, {0, 1, 1}, {0, 0, 0}};
	static int sizes[TEST_CASES] = {6, 3, 3};

	static int answersA[TEST_CASES][MAX_SIZE][MAX_SIZE] = {
		{{-1, -1, 2}, {-1, 0, 1}}, {}, {{0, 0, 0}}};
	static int answersColumnSizesA[TEST_CASES][MAX_SIZE] = {{3, 3}, {0}, {3}};
	static int answersSizes[TEST_CASES] = {2, 0, 1};


	int*** answers = convertToTriplePointer(answersA, answersSizes, answersColumnSizesA);
	int** answersColumnSizes = convertToDoublePointer(answersColumnSizesA, answersSizes);

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: ", i + 1);

		printArray(cases[i], sizes[i]);
		printf("\n");

		int returnSize = 0;
		int* returnColumnSizes = NULL;

		int** result = threeSum(cases[i], sizes[i], &returnSize, &returnColumnSizes);
		printf("result: ");
		print2dArray(result, returnColumnSizes, returnSize);
		printf("\n");
		printf("returnSize: %d\n", returnSize);
		printf("returnColumnSizes: ");
		printArray(returnColumnSizes, returnSize);
		printf("\n");


		if(result == NULL || isCorrect(result, returnColumnSizes, returnSize, answers[i],
									   answersColumnSizes[i], answersSizes[i])) {
			printf(ANSI_COLOR_RED "---------------------TEST CASE "
								  "FAILED---------------------\n" ANSI_COLOR_RESET);
			// break;
		}
		else {
			printf(ANSI_COLOR_GREEN "-------------------TEST CASE "
									"SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}
		free(result);

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	free3dArray((void***)answers, answersSizes, TEST_CASES);
	free2dArray((void**)answersColumnSizes, TEST_CASES);

	return 0;
}

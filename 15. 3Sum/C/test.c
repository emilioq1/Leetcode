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

#define TEST_CASES 4

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

bool inArray(int* array, int size, int item) {
	for(int i = 0; i < size; ++i) {
		if(array[i] == item) {
			return true;
		}
	}
	return false;
}

bool isCorrect(int** a, int* aColumnSizes, int aSize, int** b, int* bColumnSizes, int bSize) {
	if(a == NULL || b == NULL) return false;
	if(aColumnSizes == NULL || bColumnSizes == NULL) return false;
	if(aSize != bSize) return false;

	int* aKeys = calloc(aSize, sizeof(int));
	for(int i = 0; i < aSize; ++i) {
		aKeys[i] = a[i][0] ^ a[i][1] ^ a[i][2];
	}

	int* bKeys = calloc(aSize, sizeof(int));
	for(int i = 0; i < aSize; ++i) {
		bKeys[i] = b[i][0] ^ b[i][1] ^ b[i][2];
	}

	int* aMatchedIndexes = calloc(aSize, sizeof(int));
	int aMatchedSize = 0;
	int* bMatchedIndexes = calloc(aSize, sizeof(int));
	int bMatchedSize = 0;


	for(int i = 0; i < aSize; ++i) {
		for(int j = 0; j < bSize; ++j) {
			if(aKeys[i] == aKeys[j] && !inArray(aMatchedIndexes, aMatchedSize, i) &&
			   !inArray(bMatchedIndexes, bMatchedSize, j)) {
				aMatchedIndexes[aMatchedSize++] = i;
				bMatchedIndexes[bMatchedSize++] = j;
			}
		}
	}

	if(aMatchedSize == aSize && bMatchedSize == bSize) {
		free(aMatchedIndexes);
		free(bMatchedIndexes);
		free(aKeys);
		free(bKeys);
		return true;
	}


	return false;
}

int main() {
	static int cases[TEST_CASES][MAX_SIZE] = {
		{-1, 0, 1, 2, -1, -4},
		{0, 1, 1},
		{0, 0, 0},
		{2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10}};
	static int sizes[TEST_CASES] = {6, 3, 3, 17};

	static int answersA[TEST_CASES][MAX_SIZE][MAX_SIZE] = {
		{{-1, -1, 2}, {-1, 0, 1}},
		{},
		{{0, 0, 0}},
		{{-10, 5, 5}, {-5, 0, 5}, {-4, 2, 2}, {-3, -2, 5}, {-3, 1, 2}, {-2, 0, 2}}};
	static int answersColumnSizesA[TEST_CASES][MAX_SIZE] = {{3, 3}, {0}, {3}, {3, 3, 3, 3, 3, 3}};
	static int answersSizes[TEST_CASES] = {2, 0, 1, 6};


	int*** answers = convertToTriplePointer(answersA, answersSizes, answersColumnSizesA);
	int** answersColumnSizes = convertToDoublePointer(answersColumnSizesA, answersSizes);

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: ", i + 1);

		printArray(cases[i], sizes[i]);
		printf("\n\n");

		int returnSize = 0;
		int* returnColumnSizes = NULL;

		int** result = threeSum(cases[i], sizes[i], &returnSize, &returnColumnSizes);
		printf("Result:\n");
		printf("\tresult: ");
		print2dArray(result, returnColumnSizes, returnSize);
		printf("\n");
		printf("\treturnSize: %d\n", returnSize);
		printf("\treturnColumnSizes: ");
		printArray(returnColumnSizes, returnSize);
		printf("\n\n");
		printf("Should be: \n");
		printf("\tresult: ");
		print2dArray(answers[i], answersColumnSizes[i], answersSizes[i]);
		printf("\n");
		printf("\treturnSize: %d\n", answersSizes[i]);
		printf("\treturnColumnSizes: ");
		printArray(answersColumnSizes[i], answersSizes[i]);
		printf("\n");


		if(result == NULL || !isCorrect(result, returnColumnSizes, returnSize, answers[i],
										answersColumnSizes[i], answersSizes[i])) {
			printf(ANSI_COLOR_RED "---------------------TEST CASE "
								  "FAILED---------------------\n" ANSI_COLOR_RESET);
			break;
		}
		else {
			printf(ANSI_COLOR_GREEN "-------------------TEST CASE "
									"SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}
		free2dArray((void**)result, returnSize);
		free(returnColumnSizes);

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	free3dArray((void***)answers, answersSizes, TEST_CASES);
	free2dArray((void**)answersColumnSizes, TEST_CASES);

	return 0;
}

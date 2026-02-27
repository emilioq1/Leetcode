#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	int casesSize = 0;
	IntArray* cases = createCases("cases.txt", &casesSize);

	// static int cases[TEST_CASES][MAX_SIZE] = {
	//	{-1, 0, 1, 2, -1, -4},
	//	{0, 1, 1},
	//	{0, 0, 0},
	//	{2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10}};
	// static int sizes[TEST_CASES] = {6, 3, 3, 17};

	static int answersA[TEST_CASES][MAX_SIZE][MAX_SIZE] = {
		{{-1, -1, 2}, {-1, 0, 1}},
		{},
		{{0, 0, 0}},
		{{-10, 5, 5}, {-5, 0, 5}, {-4, 2, 2}, {-3, -2, 5}, {-3, 1, 2}, {-2, 0, 2}},
	};
	static int answersColumnSizesA[TEST_CASES][MAX_SIZE] = {{3, 3}, {0}, {3}, {3, 3, 3, 3, 3, 3}};
	static int answersSizes[TEST_CASES] = {2, 0, 1, 6};


	int*** answers = convertToTriplePointer(answersA, answersSizes, answersColumnSizesA);
	int** answersColumnSizes = convertToDoublePointer(answersColumnSizesA, answersSizes);

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: ", i + 1);

		printIntArray(cases[i].arr, cases[i].size);
		printf("\n\n");

		int returnSize = 0;
		int* returnColumnSizes = NULL;

		int** result = threeSum(cases[i].arr, cases[i].size, &returnSize, &returnColumnSizes);
		printf("Result:\n");
		printf("\tresult: ");
		print2dIntArray(result, returnColumnSizes, returnSize);
		printf("\n");
		printf("\treturnSize: %d\n", returnSize);
		printf("\treturnColumnSizes: ");
		printIntArray(returnColumnSizes, returnSize);
		printf("\n\n");
		printf("Should be: \n");
		printf("\tresult: ");
		print2dIntArray(answers[i], answersColumnSizes[i], answersSizes[i]);
		printf("\n");
		printf("\treturnSize: %d\n", answersSizes[i]);
		printf("\treturnColumnSizes: ");
		printIntArray(answersColumnSizes[i], answersSizes[i]);
		printf("\n");


		if(result == NULL || !isCorrect(result, returnColumnSizes, returnSize, answers[i],
										answersColumnSizes[i], answersSizes[i])) {
			printf(ANSI_COLOR_RED "---------------------TEST CASE "
								  "FAILED---------------------\n" ANSI_COLOR_RESET);
			// break;
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

	freeIntArrayArray(cases, casesSize);

	free3dArray((void***)answers, answersSizes, TEST_CASES);
	free2dArray((void**)answersColumnSizes, TEST_CASES);

	return 0;
}

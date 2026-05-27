#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"


int main() {
	static int cases[TEST_CASES][MAX_LENGTH] = {
		{1, 0, -1, 0, -2, 2},
		{2, 2, 2, 2, 2},
		{1, -2, -5, -4, -3, 3, 3, 5},
		{0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000}};
	static int targets[TEST_CASES] = {0, 8, -11, 1000000000};
	static int sizes[TEST_CASES] = {6, 5, 8, 7};

	static int answersS[TEST_CASES][MAX_LENGTH][MAX_LENGTH] = {
		{{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}},
		{{2, 2, 2, 2}},
		{{-5, -4, -3, 1}},
		{{0, 0, 0, 1000000000}}};
	static int answersColumnSizes[TEST_CASES][MAX_LENGTH] = {
		{4, 4, 4}, {4}, {4}, {4}};
	static int answersSizes[TEST_CASES] = {3, 1, 1, 1};

	int*** answers =
		convertToTriplePointerInt(answersS, answersSizes, answersColumnSizes);


	printf("---------------------------------------------------------\n\n");

	int start = 0;
	int end = TEST_CASES;
	for(int i = start; i < end; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: ", start + (i + 1));
		printIntArray(cases[i], sizes[i]);
		printf(", target = %d\n", targets[i]);
		printf("\n");

		int returnSize = 0;
		int* returnColumnSizes = NULL;
		int** result = fourSum(cases[i], sizes[i], targets[i], &returnSize,
							   &returnColumnSizes);

		printf("Result:\n\t");
		print2dIntArray(result, returnColumnSizes, returnSize);
		printf("\n");

		printf("Should be:\n\t");
		print2dIntArray(answers[i], answersColumnSizes[i], answersSizes[i]);
		printf("\n\n");


		// fourSum always return quadruplets so 4 as cols
		if(result != NULL &&
		   isCorrect(result, returnSize, answers[i], answersSizes[i], 4)) {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
			free2dArray((void**)result, returnSize);
			free(returnColumnSizes);
		}
		else {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
			if(result != NULL) {
				free2dArray((void**)result, returnSize);
				free(returnColumnSizes);
			}
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	free3dArray((void***)answers, answersSizes, TEST_CASES);

	return 0;
}

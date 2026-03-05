#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"


int main() {
	static char* cases[TEST_CASES] = {"23", "2"};

	static char answersS[TEST_CASES][MAX_SIZE][MAX_LENGTH + 1] = {
		{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"},
		{"a", "b", "c"}};
	static int answersSize[TEST_CASES] = {9, 3};

	char*** answers =
		converToTriplePointerChar(answersS, answersSize, TEST_CASES);


	printf("---------------------------------------------------------\n\n");

	int start = 0;
	int end = TEST_CASES;
	for(int i = start; i < end; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: \"%s\"", start + (i + 1), cases[i]);

		printf("\n\n");

		int returnSize = 0;
		char** result = letterCombinations(cases[i], &returnSize);

		printf("Result:\n");
		printStringArray(result, returnSize);
		printf("\n");


		printf("Should be: \n");
		printStringArray(answers[i], answersSize[i]);
		printf("\n");


		if(result != NULL &&
		   isCorrect(result, returnSize, answers[i], answersSize[i])) {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}
		else {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	free3dArray((void***)answers, answersSize, TEST_CASES);

	return 0;
}

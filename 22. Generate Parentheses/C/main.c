#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	static int cases[TEST_CASES] = {3, 1};
	static char* answers[TEST_CASES][256] = {
		{"((()))", "(()())", "(())()", "()(())", "()()()"}, {"()"}};
	static int answersSizes[TEST_CASES] = {5, 1};

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("case %d: \n\t", i + 1);

		printf("n = %d\n", cases[i]);

		int returnSize = 0;
		char** result = generateParenthesis(cases[i], &returnSize);

		printf("Result:\n");
		printf("\t");
		printStringArray(result, returnSize);
		printf("\n\n");

		printf("Should be: \n");
		printf("\t");
		printStringArray(answers[i], answersSizes[i]);
		printf("\n");

		if(!isCorrect(result, returnSize, answers[i], answersSizes[i])) {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
		}
		else {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	return 0;
}

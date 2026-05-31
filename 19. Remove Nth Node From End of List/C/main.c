#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	static int casesR[TEST_CASES][MAX_SIZE] = {{1, 2, 3, 4, 5}, {1}, {1, 2}};
	static int sizes[TEST_CASES] = {5, 1, 2};
	static int ns[TEST_CASES] = {2, 1, 1};

	struct ListNode* cases[TEST_CASES] = {};
	for(int i = 0; i < TEST_CASES; ++i) {
		cases[i] = allocateNode(casesR[i], sizes[i], 0);
	}

	static int answersR[TEST_CASES][MAX_SIZE] = {{1, 2, 3, 5}, {}, {1, 2}};
	static int answersSizes[TEST_CASES] = {4, 0, 1};

	struct ListNode* answers[TEST_CASES] = {};
	for(int i = 0; i < TEST_CASES; ++i) {
		answers[i] = allocateNode(answersR[i], answersSizes[i], 0);
	}

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		// printf("TEST CASE:\n");
		printf("case %d: \n\t", i + 1);

		printf("node = ");
		printIntArray(casesR[i], sizes[i]);
		printf(", n = %d", ns[i]);
		printf("\n\n");

		struct ListNode* result = removeNthFromEnd(cases[i], ns[i]);

		printf("Result:\n");
		printf("\t");
		printNode(result);
		printf("\n\n");

		printf("Should be: \n");
		printf("\t");
		printNode(answers[i]);
		printf("\n");

		if(result == NULL || !isCorrect(result, answers[i])) {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
			// break;
		}
		else {
			printf(ANSI_COLOR_GREEN
				   "-------------------TEST CASE "
				   "SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}

		freeNode(result);

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	freeNodes(cases, TEST_CASES);
	freeNodes(answers, TEST_CASES);

	return 0;
}

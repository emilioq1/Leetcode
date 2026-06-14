#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	static int casesR[TEST_CASES][2][MAX_SIZE] = {
		{{1, 2, 4}, {1, 3, 4}}, {{0}, {0}}, {{0}, {0}}};
	static int sizes[TEST_CASES][2] = {{3, 3}, {0, 0}, {0, 1}};

	struct ListNode* cases[TEST_CASES][2];
	for(int i = 0; i < TEST_CASES; ++i) {
		cases[i][0] = allocateNode(casesR[i][0], sizes[i][0], 0);
		cases[i][1] = allocateNode(casesR[i][1], sizes[i][1], 0);
	}

	static int answersR[TEST_CASES][MAX_SIZE] = {{1, 1, 2, 3, 4, 4}, {}, {0}};
	static int answersSizes[TEST_CASES] = {6, 0, 1};

	struct ListNode* answers[TEST_CASES];
	for(int i = 0; i < TEST_CASES; ++i) {
		if(answersSizes[i] == 0) answers[i] = NULL;
		else {
			answers[i] = allocateNode(answersR[i], answersSizes[i], 0);
		}
	}

	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		// printf("TEST CASE:\n");
		printf("case %d: \n\t", i + 1);

		printf("list1 = ");
		printNode(cases[i][0]);
		printf("\n\t");
		printf("list2 = ");
		printNode(cases[i][1]);
		printf("\n\n");

		struct ListNode* result = mergeTwoLists(cases[i][0], cases[i][1]);

		printf("Result:\n");
		printf("\t");
		printNode(result);
		printf("\n\n");

		printf("Should be: \n");
		printf("\t");
		printNode(answers[i]);
		printf("\n");

		if(!isCorrect(result, answers[i])) {
			printf(ANSI_COLOR_RED
				   "---------------------TEST CASE "
				   "FAILED---------------------\n" ANSI_COLOR_RESET);
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

	// for(int i = 0; i < TEST_CASES; ++i) {
	//	freeNodes(cases[i], 2);
	// }

	freeNodes(answers, TEST_CASES);

	return 0;
}

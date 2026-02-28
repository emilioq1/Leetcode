#include "shared.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
	int casesSize = 0;
	IntArray* cases = createCases("cases.txt", &casesSize);
	int targets[TEST_CASES] = {1, 1, 1, -2, -101, 7175, 300};

	static int answers[TEST_CASES] = {2, 0, 60, -2, -101, 2921, 300};


	printf("---------------------------------------------------------\n\n");

	int start = 5;
	int end = 6;
	for(int i = start; i < end; ++i) {
		printf("TEST CASE:\n");
		printf("case %d: ", start + (i + 1));

		printIntArray(cases[i].arr, cases[i].size);
		printf(", target = %d\n", targets[i]);
		printf("\n\n");

		int result = threeSumClosest(cases[i].arr, cases[i].size, targets[i]);
		printf("Result:\n");
		printf("\tresult: %d\n", result);


		printf("Should be: \n");
		printf("\tresult: %d\n", answers[i]);


		if(result == answers[i]) {
			printf(ANSI_COLOR_GREEN "-------------------TEST CASE "
									"SUCCESS---------------------\n" ANSI_COLOR_RESET);
		}
		else {
			printf(ANSI_COLOR_RED "---------------------TEST CASE "
								  "FAILED---------------------\n" ANSI_COLOR_RESET);
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	freeIntArrayArray(cases, casesSize);

	return 0;
}

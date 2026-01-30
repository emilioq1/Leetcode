#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define PRINT(x) x ? x : 'N'

bool isMatch(char* s, char* p) {
	if(strcmp(p, ".*") == 0) return true;
	if(strcmp(p, s) == 0) return true;

	size_t sLen = strnlen(s, 20);
	size_t pLen = strnlen(p, 21);

	printf("sLen: %lu\n", sLen);
	printf("pLen: %lu\n", pLen);

	int i = 0;

	int starCount = 0;
	// Note: If a letter is next to a star, it is not counted in
	// letterOrDotCount as there can be zero or more occurances of the letter.
	// int letterOrDotCount = 0;
	int letterCount = 0;
	int dotCount = 0;

	for(int k; k < pLen; ++k) {
		char next = p[k + 1];

		if(p[k] == '.') {
			if(next != '*') {
				++dotCount;
			}
		}
		else if(p[k] == '*') {
			++starCount;
		}
		else {
			if(next != '*') {
				++letterCount;
			}
		}

		// At end of s
		if(next == '\0') break;
	}
	int letterOrDotCount = letterCount + dotCount;

	printf("letterOrDotCount: %d\n", letterOrDotCount);
	printf("starCount: %d\n", starCount);

	if(starCount == 0 && letterOrDotCount < sLen) return false;
	if(starCount == 1 && letterOrDotCount == 0 && s[0] != p[0]) return false;
	if(letterOrDotCount > sLen) return false;

	int initialLetterCount = letterCount;
	int initialDotCount = dotCount;
	int initialStarCount = starCount;

	char prev = '\0';
	char curr = p[0];
	char next = '\0';

	printf("--------------------------------\n");

	bool ignoreMatch = false;
	bool reverse = false;
	int reverseIndex = sLen - letterOrDotCount;
	int initialPIndex = 0;

	for(int j = 0; j < pLen; ++j) {
		next = p[j + 1];

		printf("j: %d\n", j);
		printf("\tletterCount = %d\n", letterCount);
		printf("\tdotCount = %d\n", dotCount);
		printf("\tstarCount = %d\n", starCount);
		printf("\ts = \"%s\"\n", s);
		printf("\tp = \"%s\"\n", p);
		printf("\t\ti = %d\t\tj = %d\n", i, j);
		printf("\ts[%d] =\t%c\tp[%d] =\t%c\n", i, PRINT(s[i]), j, PRINT(p[j]));
		printf("\tcurr =\t%c\tnext =\t%c\n\n", PRINT(curr), PRINT(next));

		switch(curr) {
			case '.':
				printf("  .\n");
				if(next == '*') {
					prev = curr;
					printf("\tstar is next, break\n\n");
					break;
				}
				++i;
				//--letterOrDotCount;
				--dotCount;
				break;
			case '*':
				printf("  *\n");
				--starCount;

				// int remainingP = pLen - j;
				// printf("remainingP: %d\n", remainingP);
				printf("\tInitial letterOrDotCount: %d\n", letterOrDotCount);
				printf("\ts[%d] = %c\n\n", i, PRINT(s[i]));
				int remainingS = sLen - i;


				while(s[i] == prev && s[i] != next) {
					remainingS = sLen - i;
					printf("\tremainingS: %d\n", remainingS);
					printf("\tletterCount: %d\n", letterCount);
					printf("\tletterOrDotCount: %d\n", letterOrDotCount);

					if(remainingS == letterCount + dotCount) {
						printf("\tremainingS == letterOrDotCount\n");
						break;
					}
					if(remainingS == 0) {
						printf("\tremainingS == 0\n");
						break;
					}
					++i;
				}

				if(prev == '.') {
					ignoreMatch = true;
					if(remainingS == 0) break;
				}

				while(prev == '.') {
					remainingS = sLen - i;
					printf("\tremainingS: %d\n", remainingS);
					printf("\tletterCount: %d\n", letterCount);
					printf("\tletterOrDotCount: %d\n", letterOrDotCount);

					if(remainingS == letterCount + dotCount) {
						printf("\tremainingS == letterOrDotCount\n");
						break;
					}
					if(remainingS == 0) {
						printf("\tremainingS == 0\n");
						break;
					}
					++i;
				}
				printf("\n");
				printf("\tFinal remainingS: %lu\n", sLen - i);
				printf("\tFinal letterOrDotCount: %d\n", letterOrDotCount);

				printf("\n");
				break;
			default:
				printf("  letter\n");

				if(next == '*') {
					prev = curr;
					printf("\tstar is next, break\n\n");
					break;
				}


				if(s[i] == curr) {
					printf("\tmatch\n\n");
					//--letterOrDotCount;
					--letterCount;
					++i;
					break;
				}
				else {
					printf("\tno match\n\n");
					if(ignoreMatch == false) return false;
					i = sLen - 1;
					// if(reverse == true) {
					//	printf("reverse == true");
					//	--i;
					// }
				}
				break;
		}
		printf("--------------------------------\n\n");

		letterOrDotCount = letterCount + dotCount;

		if(letterOrDotCount == 0 && starCount == 0) break;
		if(prev == '.' && curr == '*' && j != pLen - 1) {
			initialPIndex = j;
			reverse = true;
		}
		if(i == sLen - 1 && next != '*' &&
		   (letterOrDotCount != 0 || starCount != 0) && reverse == true) {
			letterCount = initialLetterCount;
			dotCount = initialDotCount;
			starCount = initialStarCount;

			i = --reverseIndex;
			j = initialPIndex;
		}
		if(i == 0 && reverse == true) {
			return false;
		}

		// At end of s
		if(next == '\0') break;
		if(s[i] == '\0') break;


		curr = next;

		while(fgetc(stdin) != 10)
			;
	}

	if(i != sLen) {
		return false;
	}

	return true;
}

#define TEST_CASES 1

int main() {
	char* s[TEST_CASES] = {//"aa",
						   //				   "aa",
						   //				   "ab",
						   //				   "aab",
						   //				   "abcd",
						   //				   "ab",
						   //				   "mississippi",
						   //				   "aaa",
						   //				   "aaa",
						   //				   "mississippi",
						   "aabcbcbcaccbcaabc"};
	char* p[TEST_CASES] = {//"a",
						   //				   "a*",
						   //				   ".*",
						   //				   "c*a*b",
						   //				   "d*",
						   //				   ".*c",
						   //				   "mis*is*ip*.",
						   //				   "a*a",
						   //				   "ab*a*c*a",
						   //				   "mis*is*p*.",
						   ".*a*aa*.*b*.c*.*a*"};
	bool results[TEST_CASES] = {// false, true, true, true,  false, false,
								// true,  true, true, false,
								true};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\ts: \"%s\"\n", s[i]);
		printf("\tp: \"%s\"\n\n", p[i]);
		bool result = isMatch(s[i], p[i]);
		printf("result: %s\n\n", result ? "true" : "false");
		if(results[i] != result) {
			printf(
				"---------------------TEST CASE FAILED---------------------\n");
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	return 0;
}

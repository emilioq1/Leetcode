#define _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define PRINT(x) x ? x : 'N'

bool isMatch(char* s, char* p) {
	if(!strncmp(p, ".*", 21)) return true;
	if(!strncmp(s, p, 21)) return true;

	size_t sLen = strnlen(s, 21);

	// p consists of only '.' (any character) and is same length of s
	if(strspn(p, ".") == sLen) return true;

	size_t pLen = strnlen(p, 21);


	printf("sLen: %ld\n", sLen);
	printf("pLen: %ld\n\n", pLen);

	int i = 0;
	int j = 0;

	char prev = '\0';
	char curr = p[j];
	char next = '\0';

	while(curr != '\0') {
		next = p[++j];

		printf("i: %d, j: %d\n", i, j);
		printf("s[i]: %c\n", s[i]);
		printf("curr: %c, next: %c\n\n", PRINT(curr), PRINT(next));

		switch(curr) {
			case '.':
				printf(".\n\n");
				++i;
				break;
			case '*':
				printf("*\n");

				int remainingP = pLen - j;
				printf("remainingP: %d\n", remainingP);

				while(s[i] == prev || prev == '.') {
					int remainingS = sLen - i;
					printf("remainingS: %d\n", remainingS);

					if(remainingS == remainingP) break;
					++i;
				}

				printf("\n");
				break;
			default:
				printf("letter\n");

				if(next == '*') {
					prev = curr;
					printf("star is next\n\n");
					break;
				}


				if(s[i] == curr) {
					printf("match\n\n");
					++i;
					break;
				}
				else {
					printf("no match\n\n");
					return false;
				}
		}

		// At end of s
		if(next == '\0') break;

		curr = next;
	}

	if(i != sLen) {
		return false;
	}

	return true;
}

#define TEST_CASES 9

int main() {
	char* s[TEST_CASES] = {"aa", "aa",			"ab",  "aab", "abcd",
						   "ab", "mississippi", "aaa", "aaa"};
	char* p[TEST_CASES] = {"a",	  "a*",			 ".*",	"c*a*b",   "d*",
						   ".*c", "mis*is*ip*.", "a*a", "ab*a*c*a"};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\ts: \"%s\"\n", s[i]);
		printf("\tp: \"%s\"\n\n", p[i]);
		int result = isMatch(s[i], p[i]);
		printf("result: %s\n\n", result ? "true" : "false");

		printf("---------------------------------------------------------\n\n");
	}

	return 0;
}

/**
 * Used Binary search approach
 *
 * Leetcode Editorial implementation
 *
 * Used for reference
 *
 * Time complexity: O(S * log(m))
 *      - S is the sum of all characters in all strings
 *      - Makes log(m) iterations
 *      - For each of them there are S = m * n comparisons
 * Space complexity: O(1)
 * */

#include "shared.h"

bool isCommonPrefix(char** strs, int strsSize, int len) {
	for(int i = 1; i < strsSize; ++i) {
		if(strncmp(strs[0], strs[i], len) != 0) {
			return false;
		}
	}

	return true;
}

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strs == NULL || strsSize == 0) return strdup("");
	if(strsSize == 1) return strdup(strs[0]);

	size_t minLen = strlen(strs[0]);
	for(int i = 1; i < strsSize; ++i) {
		int len = strlen(strs[i]);
		if(len < minLen) minLen = len;
	}

	int low = 1;
	int high = minLen;

	while(low <= high) {
		int mid = (low + high) / 2;

		if(isCommonPrefix(strs, strsSize, mid)) {
			// the prefix does match all strs,
			// so we increment the index by one
			low = mid + 1;
		}
		else {
			// the prefix does not match,
			// so the size will be less than mid
			high = mid - 1;
		}
	}

	char* prefix = strndup(strs[0], high);

	return prefix;
}

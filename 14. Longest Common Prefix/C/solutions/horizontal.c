/**
 * Used Horizontal scanning
 *
 * From Leetcode Editorial
 *
 * Time complexity: O(S = m * n) = number of all characters in the array
 * Space complexity: O(1)
 * */

#include "shared.h"

#define MAX_LENGTH 200

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strsSize == 0) return strdup("");
	if(strsSize == 1) return strdup(strs[0]);

	char* prefix = strdup(strs[0]);

	for(int i = 1; i < strsSize; ++i) {

		// Repeat until it finds occurrence of prefix in strs[i]
		while(strstr(strs[i], prefix) != strs[i]) {
			// Decrement prefix string by 1
			prefix[strlen(prefix) - 1] = '\0';

			// Check if the prefix string is zero length
			if(!*prefix) {
				free(prefix);
				return strdup("");
			}
		}
	}

	return prefix;
}

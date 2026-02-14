/**
 * Used Divide and conquer approach
 *
 * From Leetcode
 *
 * Time complexity: O(m * n) = number of all characters in the array
 *      2 * T(n/2) + O(m) = O(m * n)
 * Space complexity: O(m * log(n))
 *      - log(n) recursive calls
 *      - each store need m space
 * */

#include "shared.h"

#define MAX_LENGTH 200

// Check the longest common prefix for the two passed strings
char* LCP(char* s1, char* s2) {
	int minLen = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);

	char* res = calloc(minLen + 1, sizeof(char));

	for(int i = 0; i < minLen; i++) {
		if(s1[i] != s2[i]) {
			res[i] = '\0';
			break;
		}
		res[i] = s1[i];
	}
	return res;
}

// Recursively splits the array and combines results
//
// int l: leftmost index
// int r: rightmost index
char* divide_and_conquer(char** strs, int l, int r) {
	// Only 1 string is in this range, so return it
	if(l == r) return strs[l];
	// More than 1 string in range
	else {
		int mid = (l + r) / 2;

		// Splits the array recursively until it returns the base case (1 string)
		char* lcpLeft = divide_and_conquer(strs, l, mid);
		char* lcpRight = divide_and_conquer(strs, mid + 1, r);

		// Longest common prefix
		char* res = LCP(lcpLeft, lcpRight);

		// Do not free lcpLeft or lcpRight if from strs
		if(lcpLeft != strs[l]) free(lcpLeft);
		if(lcpRight != strs[mid + 1]) free(lcpRight);
		return res;
	}
}

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strs == NULL || strsSize == 0) return "";
	return divide_and_conquer(strs, 0, strsSize - 1);
}

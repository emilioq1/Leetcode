/**
 * Trie implementation
 *
 * From Leetcode Editoral solution
 * Edited slightly
 *
 * Time complexity: O(S)
 *      - S is the number of all characters in the array
 *
 * Space complexity: O(S)
 * */

#include "shared.h"

#define MAX_LENGTH 200

typedef struct TrieNode {
	struct TrieNode* children[26]; // 26 english alphabet characters
	bool isEnd;					   // Is no other node after this node?
	int linkCount;				   // Tracks the number of non-null children
} TrieNode;


TrieNode* createTrieNode() {
	TrieNode* node = (TrieNode*)calloc(1, sizeof(TrieNode));

	// Check if calloc was successful
	if(node) {
		node->linkCount = 0;
	}

	return node;
}

void insert(TrieNode* root, char* word) {
	TrieNode* node = root;

	for(int i = 0; word[i] != '\0'; ++i) {
		// Get the alphabetical position of the current letter
		char currentChar = word[i] - 'a';

		// Create node if does not exist
		if(node->children[currentChar] == NULL) {
			node->children[currentChar] = createTrieNode();
			++node->linkCount; // track how many children this node has
		}

		// Move down to (or into newly created) child node
		node = node->children[currentChar];
	}
	// After parsed all letters, mark final node as end of valid word
	node->isEnd = true;
}

char* searchLongestPrefix(TrieNode* root, char* word) {
	TrieNode* node = root;
	char* prefix = (char*)malloc(MAX_LENGTH * sizeof(char));
	int index = 0;

	for(int i = 0; word[i] != '\0'; ++i) {
		char currentChar = word[i] - 'a';

		if(node->children[currentChar] != NULL && node->linkCount == 1 &&
		   !node->isEnd) {
			prefix[index++] = word[i];
			node = node->children[currentChar];
		}
		else break;
	}
	prefix[index] = '\0';

	return prefix;
}

void freeNode(TrieNode* node) {
	for(int i = 0; i < 26; ++i) {
		if(node->children[i] != NULL) {
			freeNode(node->children[i]);
		}
	}
	free(node);
}

char* longestCommonPrefix(char** strs, int strsSize) {
	if(strsSize == 0) return strdup("");
	if(strsSize == 1) return strdup(strs[0]);

	TrieNode* root = createTrieNode();
	for(int i = 1; i < strsSize; ++i) {
		insert(root, strs[i]);
	}

	char* result = searchLongestPrefix(root, strs[0]);

	freeNode(root);

	return result;
}

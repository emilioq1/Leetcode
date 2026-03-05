#include "../shared.h"

bool isCorrect(char** a, int aSize, char** b, int bSize) {
	if(a == NULL || b == NULL) return false;
	if(aSize != bSize) return false;
	if(aSize == 0 || bSize == 0) return false;

	int* aMatchedIndexes = calloc(aSize, sizeof(int));
	int aMatchedSize = 0;
	int* bMatchedIndexes = calloc(aSize, sizeof(int));
	int bMatchedSize = 0;


	for(int i = 0; i < aSize; ++i) {
		for(int j = 0; j < bSize; ++j) {
			if(strcmp(a[i], b[j]) == 0 &&
			   !inArray(aMatchedIndexes, aMatchedSize, i) &&
			   !inArray(bMatchedIndexes, bMatchedSize, j)) {
				aMatchedIndexes[aMatchedSize++] = i;
				bMatchedIndexes[bMatchedSize++] = j;
			}
		}
	}

	free(aMatchedIndexes);
	free(bMatchedIndexes);

	if(aMatchedSize == aSize && bMatchedSize == bSize) {
		return true;
	}


	return false;
}

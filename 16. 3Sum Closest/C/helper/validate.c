#include "../shared.h"

bool isCorrect(int** a, int* aColumnSizes, int aSize, int** b, int* bColumnSizes, int bSize) {
	if(a == NULL || b == NULL) return false;
	if(aColumnSizes == NULL || bColumnSizes == NULL) return false;
	if(aSize != bSize) return false;

	long long* aKeys = calloc(aSize, sizeof(long long));
	for(int i = 0; i < aSize; ++i) {
		long long key = ((long long)(a[i][0] + MAX_LENGTH) << 36) |
						((long long)(a[i][1] + MAX_LENGTH) << 18) |
						(long long)(a[i][2] + MAX_LENGTH);
		aKeys[i] = key;
	}

	long long* bKeys = calloc(aSize, sizeof(long long));
	for(int i = 0; i < aSize; ++i) {
		long long key = ((long long)(b[i][0] + MAX_LENGTH) << 36) |
						((long long)(b[i][1] + MAX_LENGTH) << 18) |
						(long long)(b[i][2] + MAX_LENGTH);
		bKeys[i] = key;
	}

	int* aMatchedIndexes = calloc(aSize, sizeof(int));
	int aMatchedSize = 0;
	int* bMatchedIndexes = calloc(aSize, sizeof(int));
	int bMatchedSize = 0;


	for(int i = 0; i < aSize; ++i) {
		for(int j = 0; j < bSize; ++j) {
			if(aKeys[i] == bKeys[j] && !inArray(aMatchedIndexes, aMatchedSize, i) &&
			   !inArray(bMatchedIndexes, bMatchedSize, j)) {
				aMatchedIndexes[aMatchedSize++] = i;
				bMatchedIndexes[bMatchedSize++] = j;
			}
		}
	}

	free(aMatchedIndexes);
	free(bMatchedIndexes);
	free(aKeys);
	free(bKeys);

	if(aMatchedSize == aSize && bMatchedSize == bSize) {
		return true;
	}


	return false;
}

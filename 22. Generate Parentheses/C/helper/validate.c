#include "../shared.h"

int cmp(const void* a, const void* b) {
	return strcmp(*(const char**)a, *(const char**)b);
}

bool isCorrect(char** a, int aSize, char** b, int bSize) {
	if(a == NULL && b == NULL) return true;
	if(aSize != bSize) return false;

	qsort(a, aSize, sizeof(char*), cmp);
	qsort(b, bSize, sizeof(char*), cmp);

	for(int i = 0; i < aSize; ++i) {
		if(!strcmp(a[i], b[i])) return false;
	}

	return true;
}

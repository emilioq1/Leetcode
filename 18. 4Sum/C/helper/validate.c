#include "../shared.h"

static int g_cols;

int cmp_int(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int cmp_row(const void* a, const void* b) {
	const int* ra = *(const int**)a;
	const int* rb = *(const int**)b;
	for(int i = 0; i < g_cols; ++i) {
		if(ra[i] != rb[i]) return ra[i] - rb[i];
	}
	return 0;
}

bool isCorrect(int** a, int aSize, int** b, int bSize, int cols) {
	if(a == NULL || b == NULL) return false;
	if(aSize != bSize) return false;
	if(aSize == 0 || bSize == 0) return false;

	// sort each row
	for(int i = 0; i < aSize; ++i) {
		qsort(a[i], cols, sizeof(int), cmp_int);
		qsort(b[i], cols, sizeof(int), cmp_int);
	}

	// sort the outer arrays
	g_cols = cols;
	qsort(a, aSize, sizeof(int*), cmp_row);
	qsort(b, bSize, sizeof(int*), cmp_row);

	// compare
	for(int i = 0; i < aSize; ++i) {
		for(int j = 0; j < cols; ++j) {
			if(a[i][j] != b[i][j]) return false;
		}
	}

	return true;
}

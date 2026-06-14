#include "../shared.h"

void printNumberArray(long long* array, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i == size - 1) {
			printf("%Ld", array[i]);
		}
		else {
			printf("%Ld, ", array[i]);
		}
	}
	printf("]");
}

void print2dNumberArray(long long** array, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		printNumberArray(array[i], sizes[i]);
		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]");
}

void print3dNumberArray(long long*** array, int** columnSizes, int* sizes,
						int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		print2dNumberArray(array[i], columnSizes[i], sizes[i]);

		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]\n");
}


void printDoubleArray(long double* array, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i == size - 1) {
			printf("%.4Lf", array[i]);
		}
		else {
			printf("%.4Lf, ", array[i]);
		}
	}
	printf("]");
}

void print2dDoubleArray(long double** array, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		printDoubleArray(array[i], sizes[i]);
		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]");
}

void print3dDoubleArray(long double*** array, int** columnSizes, int* sizes,
						int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		print2dDoubleArray(array[i], columnSizes[i], sizes[i]);

		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]\n");
}

void printStringArray(char** array, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i == size - 1) {
			printf("\"%s\"", array[i]);
		}
		else {
			printf("\"%s\", ", array[i]);
		}
	}
	printf("]");
}

void print2dStringArray(char*** array, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		printStringArray(array[i], sizes[i]);
		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]");
}

void print3dStringArray(char**** array, int** columnSizes, int* sizes,
						int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		print2dStringArray(array[i], columnSizes[i], sizes[i]);

		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]\n");
}

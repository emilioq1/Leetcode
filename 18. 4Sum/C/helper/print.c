#include "../shared.h"

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

void printIntArray(int* array, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i == size - 1) {
			printf("%d", array[i]);
		}
		else {
			printf("%d, ", array[i]);
		}
	}
	printf("]");
}

void print2dIntArray(int** array, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		printIntArray(array[i], sizes[i]);
		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]");
}

void print3dIntArray(int*** array, int** columnSizes, int* sizes, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		print2dIntArray(array[i], columnSizes[i], sizes[i]);

		if(i == size - 1) {
			printf("");
		}
		else {
			printf(", ");
		}
	}
	printf("]\n");
}

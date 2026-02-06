#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L) && !defined(__STRICT_ANSI__)
#define GNU11 1
#endif

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>

#define MAX_LENGTH 10000

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int maxArea(int* height, int heightSize) {
	if(heightSize == 2) {
		return MIN(height[0], height[1]);
	}

	int currentMax = 0;

	for(int i = 0; i < heightSize; ++i) {
		printf("i: %d\n\n", i);
		int iHeight = height[i];
		if(iHeight == 0) continue;
		for(int j = heightSize - 1; j > i; --j) {
			int jHeight = height[j];
			if(jHeight == 0) continue;

			printf("j: %d\n", j);

			int height = MIN(iHeight, jHeight);
			int width = j - i;
			if(height == 1 && width <= currentMax) continue;
			if(width == 1 && height <= currentMax) continue;

			int area = height * width;
			printf("area: %d\n", area);

			if(area == 1000000000) return area;

			if(area > currentMax) currentMax = area;
		}
		printf("\n\n");
	}


	return currentMax;
}

#define TEST_CASES 3

void printArray(int* arr, int size) {
	printf("[");
	for(int i = 0; i < size; ++i) {
		if(i + 1 == size) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}
	printf("]\n");
}

int main() {
	int cases[TEST_CASES][MAX_LENGTH] = {
		{1, 8, 6, 2, 5, 4, 8, 3, 7},
		{1, 1},
	};
	int sizes[TEST_CASES] = {9, 2};
	int results[TEST_CASES] = {49, 1};


	printf("---------------------------------------------------------\n\n");

	for(int i = 0; i < TEST_CASES; ++i) {
		printf("TEST CASE:\n");
		printf("\tcase %d: ", i);
		printArray(cases[i], sizes[i]);

		int result = maxArea(cases[i], sizes[i]);
		printf("result: %d\n\n", result);

		if(results[i] != result) {
			printf("---------------------TEST CASE FAILED---------------------\n");
			break;
		}

		printf("---------------------------------------------------------"
			   "\n\n");
	}

	return 0;
}

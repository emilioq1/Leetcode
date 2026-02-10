/**
 * I used 2 hints:
 * Hint 1
 * If you simulate the problem, it will be O(n^2) which is not efficient.
 *
 * Hint 2
 * Try to use two-pointers. Set one pointer to the left and one to the
 * right of the array. Always move the pointer that points to the lower line.
 *
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L) && !defined(__STRICT_ANSI__)
#define GNU11 1
#endif

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000
#define MAX_HEIGHT 10000

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct {
	int* arr;
	size_t size;
} IntArray;

IntArray createCase(char* filename) {
	FILE* fp = fopen(filename, "r");
	fseek(fp, 1, SEEK_SET);
	int* resultArr = calloc(1, sizeof(int));

	IntArray result = {0};

	char* line = NULL;
	size_t size = 0;
	ssize_t nread = getline(&line, &size, fp);

	if(nread == -1) {
		free(line);
		return result;
	}

	char* token = strtok(line, ",");

	int i = 0;

	while(token != NULL) {
		int num = strtol(token, NULL, 10);
		resultArr[i++] = num;
		resultArr = realloc(resultArr, ((i + 1) * sizeof(int)));
		// printf("%d\n", num);
		token = strtok(0, ",");
	}

	result.arr = resultArr;
	result.size = i;

	free(line);

	return result;
}

int maxArea(int* height, int heightSize) {
	if(heightSize == 2) {
		return MIN(height[0], height[1]);
	}

	// n == height.length
	// 2 <= n <= 10^5
	// 0 <= height[i] <= 10^4
	int maxPossibleArea = heightSize * MAX_HEIGHT;
	int currentMaxHeight = 0;
	int currentMaxWidth = 0;

	int currentMax = 0;

	int i = 0;
	int j = heightSize - 1;

	while(i != j && i < heightSize && j > 0) {
		printf("i: %d\n", i);
		printf("j: %d\n\n", j);
		int iHeight = height[i];
		int jHeight = height[j];
		printf("iHeight: %d\n", iHeight);
		printf("jHeight: %d\n", jHeight);

		int width = j - i;
		printf("width: %d\n", width);
		int height = MIN(iHeight, jHeight);
		printf("height: %d\n", height);

		int area = width * height;
		printf("area: %d\n", area);
		if(area > currentMax) {
			printf("area > currentMax\n");
			printf("%d > %d\n", area, currentMax);
			currentMax = area;
		}


		if(iHeight > jHeight) {
			printf("iHeight > jHeight\n");
			printf("--j\n\n");
			--j;
		}
		else if(iHeight < jHeight) {
			printf("iHeight < jHeight\n");
			printf("++i\n\n");
			++i;
		}
		else {
			printf("iHeight == jHeight\n");
			printf("++i and --j\n\n");
			++i;
			--j;
		}
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
	int cases[TEST_CASES][MAX_HEIGHT] = {
		{1, 8, 6, 2, 5, 4, 8, 3, 7},
		{1, 1},
	};
	int sizes[TEST_CASES] = {9, 2};
	int results[TEST_CASES] = {49, 1, 0};

	int i = 0;


	printf("---------------------------------------------------------\n\n");

	for(i = 0; i < TEST_CASES; ++i) {
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

	IntArray case3 = createCase("case.txt");
	printf("TEST CASE:\n");
	printf("\tcase %d: ", i);
	printArray(case3.arr, case3.size);

	int result = maxArea(case3.arr, case3.size);
	printf("result: %d\n\n", result);

	if(results[2] != result) {
		printf("---------------------TEST CASE FAILED---------------------\n");
	}

	printf("---------------------------------------------------------"
		   "\n\n");

	free(case3.arr);


	return 0;
}

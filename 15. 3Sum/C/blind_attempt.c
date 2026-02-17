#include "shared.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** result = (int**)calloc(1, sizeof(int*));
	result[0] = (int*)calloc(3, sizeof(int));
	int resultSize = 0;

	int* columnSizes = calloc(1, sizeof(int));

	int a, aIndex;
	int b, bIndex;
	int c, cIndex;

	for(int i = 0; i < numsSize; ++i) {
		int a = nums[i];
		int aIndex = i;

		for(int j = 1; j < numsSize; ++j) {
			int b = nums[j];
			int bIndex = j;

			if(b == a) continue;

			for(int k = 2; k < numsSize; ++k) {
				int c = nums[k];
				int cIndex = k;

				printf("a: %d\n", a);
				printf("b: %d\n", b);
				printf("c: %d\n\n", c);

				if(c == a) continue;
				if(c == b) continue;

				if((a + b + c) == 0) {
					printf("a+b+c == 0\n");
					result[resultSize][0] = a;
					result[resultSize][1] = b;
					result[resultSize][2] = c;
					columnSizes[resultSize] = 3;

					++resultSize;
					result = (int**)realloc(result, (resultSize + 1) * sizeof(int*));
					result[resultSize] = calloc(3, sizeof(int));
					columnSizes = realloc(columnSizes, (resultSize + 1) * sizeof(int));


					printf("resultSize: %d\n", resultSize);
				}
			}
		}
	}
	printf("Finished\n");
	printf("resultSize: %d\n", resultSize);

	print2dArray(result, columnSizes, resultSize);
	printf("\n");

	*returnSize = resultSize;
	*returnColumnSizes = columnSizes;

	return result;
}

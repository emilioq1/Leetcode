#include "shared.h"

bool isDuplicate(int* keys, int key, int keysSize) {
	printf("isDuplicate\n");
	for(int i = 0; i < keysSize; ++i) {
		printf("%d == %d\n", keys[i], key);
		if(keys[i] == key) {
			return true;
		}
	}

	return false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize,
			   int** returnColumnSizes) {
	int** result = (int**)calloc(1, sizeof(int*));
	result[0] = (int*)calloc(3, sizeof(int));
	int resultSize = 0;
	int* columnSizes = calloc(1, sizeof(int));

	if(numsSize == 3) {
		int sum = nums[0] + nums[1] + nums[2];
		if(sum == 0) {
			result[0][0] = nums[0];
			result[0][1] = nums[1];
			result[0][2] = nums[2];
			*returnSize = resultSize;
			columnSizes[0] = 3;
			*returnColumnSizes = columnSizes;
			return result;
		}
		else {
			*returnSize = 0;
			columnSizes[0] = 0;
			*returnColumnSizes = columnSizes;
			return result;
		}
	}

	int* keys = calloc(1, sizeof(int));

	int a = MIN_LENGTH - 1;
	int aIndex = -1;
	int b = MIN_LENGTH - 1;
	int bIndex = -1;
	int c = MIN_LENGTH - 1;
	int cIndex = -1;

	for(int i = 0; i < numsSize; ++i) {
		int a = nums[i];
		int aIndex = i;

		for(int j = 1; j < numsSize; ++j) {
			if(j == i) continue;

			int b = nums[j];
			int bIndex = j;

			if(b == a) continue;

			for(int k = 2; k < numsSize; ++k) {
				if(k == i) continue;
				if(k == j) continue;

				int c = nums[k];
				int cIndex = k;

				printf("a: %d\n", a);
				printf("b: %d\n", b);
				printf("c: %d\n\n", c);

				if(c == a) continue;
				if(c == b) continue;

				int sum = a + b + c;
				int key = a ^ b ^ c;
				printf("key: %d\n", key);

				if(sum == 0 && !isDuplicate(keys, key, resultSize)) {
					printf("a+b+c == 0\n");
					result[resultSize][0] = a;
					result[resultSize][1] = b;
					result[resultSize][2] = c;
					columnSizes[resultSize] = 3;
					keys[resultSize] = key;

					++resultSize;
					result =
						(int**)realloc(result, (resultSize + 1) * sizeof(int*));
					result[resultSize] = calloc(3, sizeof(int));
					columnSizes = (int*)realloc(columnSizes,
												(resultSize + 1) * sizeof(int));
					keys = (int*)realloc(keys, (resultSize + 1) * sizeof(int));


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

	free(keys);

	return result;
}

/**
 * 100 XOR -100 XOR 0 = -8
 * 0 XOR -100 XOR 100 = -8
 * -100 XOR 0 XOR 100 = -8
 *
 * 8 XOR -1 XOR -7
 *
 *
 *
 * */

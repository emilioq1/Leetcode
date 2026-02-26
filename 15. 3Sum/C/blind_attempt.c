#include "shared.h"

bool isDuplicate(long long* keys, long long key, int keysSize) {
	printf("isDuplicate\n");
	for(int i = 0; i < keysSize; ++i) {
		printf("%lld == %lld\n", keys[i], key);
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
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** result = (int**)calloc(1, sizeof(int*));
	int resultSize = 0;
	int* columnSizes = calloc(1, sizeof(int));

	if(numsSize == 3) {
		int sum = nums[0] + nums[1] + nums[2];

		if(sum == 0) {
			result[0] = (int*)calloc(3, sizeof(int));
			result[0][0] = nums[0];
			result[0][1] = nums[1];
			result[0][2] = nums[2];
			*returnSize = resultSize + 1;
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

	long long* keys = calloc(1, sizeof(long long));

	int a = MIN_LENGTH - 1;
	int aIndex = -1;
	int b = MIN_LENGTH - 1;
	int bIndex = -1;
	int c = MIN_LENGTH - 1;
	int cIndex = -1;

	for(int i = 0; i < numsSize; ++i) {
		int a = nums[i];
		int aIndex = i;

		for(int j = i + 1; j < numsSize; ++j) {
			int b = nums[j];
			int bIndex = j;

			for(int k = j + 1; k < numsSize; ++k) {
				int c = nums[k];
				int cIndex = k;

				printf("a: %d\n", a);
				printf("b: %d\n", b);
				printf("c: %d\n", c);

				int sum = a + b + c;
				int x, y, z = 0;
				if(a <= b && a <= c) {
					x = a;
					if(b < c) {
						y = b;
						z = c;
					}
					else {
						y = c;
						z = b;
					}
				}
				else if(b <= a && b <= c) {
					x = b;
					if(a < c) {
						y = a;
						z = c;
					}
					else {
						y = c;
						z = a;
					}
				}
				else {
					x = c;
					if(a < b) {
						y = a;
						z = b;
					}
					else {
						y = b;
						z = a;
					}
				}

				long long key =
					((long long)(x + MAX_LENGTH) << 36) ^ ((long long)(y + MAX_LENGTH) << 18) |
					(long long)(z + MAX_LENGTH);

				printf("key: %lld\n\n", key);

				if(sum == 0 && !isDuplicate(keys, key, resultSize)) {
					result = (int**)realloc(result, (resultSize + 1) * sizeof(int*));
					result[resultSize] = calloc(3, sizeof(int));
					columnSizes = (int*)realloc(columnSizes, (resultSize + 1) * sizeof(int));
					keys = (long long*)realloc(keys, (resultSize + 1) * sizeof(long long));


					printf("a+b+c == 0\n");
					result[resultSize][0] = a;
					result[resultSize][1] = b;
					result[resultSize][2] = c;
					columnSizes[resultSize] = 3;
					keys[resultSize] = key;

					++resultSize;
					printf("resultSize: %d\n", resultSize);
				}
			}
		}
	}

	*returnSize = resultSize;
	*returnColumnSizes = columnSizes;

	free(keys);

	return result;
}

#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 3000
#define MIN_LENGTH -100000
#define MAX_LENGTH 100000

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
	int* arr;
	size_t size;
} IntArray;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

void printArray(int* array, int size);
void print2dArray(int** array, int* sizes, int size);
void print3dArray(int*** array, int** columnSizes, int* sizes, int size);

IntArray createCase(char* filename);

#endif

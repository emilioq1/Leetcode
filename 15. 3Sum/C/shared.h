#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_CASES 5
#define MAX_SIZE 3000
#define MIN_LENGTH -100000
#define MAX_LENGTH 100000

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// array.c
int** convertToDoublePointer(int arr[TEST_CASES][MAX_SIZE], int sizes[]);
int*** convertToTriplePointer(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE], int sizes[TEST_CASES],
							  int columnSizes[TEST_CASES][MAX_SIZE]);
void free2dArray(void** array, int size);
void free3dArray(void*** array, int* sizes, int size);
bool inArray(int* array, int size, int item);

// file.c
typedef struct {
	int* arr;
	size_t size;
} IntArray;
IntArray createCase(char* filename);
IntArray* createCases(char* filename, int* returnSize);
void freeIntArrayArray(IntArray* array, int arraySize);

// print.c
void printIntArray(int* array, int size);
void print2dIntArray(int** array, int* sizes, int size);
void print3dIntArray(int*** array, int** columnSizes, int* sizes, int size);

// validate.c
bool isCorrect(int** a, int* aColumnSizes, int aSize, int** b, int* bColumnSizes, int bSize);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);


#endif

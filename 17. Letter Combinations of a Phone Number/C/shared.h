#ifndef SHARED_H
#define SHARED_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_CASES 3
#define MAX_SIZE 26244
#define MAX_LENGTH 4


#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// array.c
int** convertToDoublePointerInt(int arr[TEST_CASES][MAX_SIZE], int sizes[]);
int*** convertToTriplePointerInt(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE], int sizes[TEST_CASES],
								 int columnSizes[TEST_CASES][MAX_SIZE]);
char*** converToTriplePointerChar(char arr[TEST_CASES][MAX_SIZE][MAX_LENGTH + 1], int colSize[],
								  int size);
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
void printStringArray(char** array, int size);
void printIntArray(int* array, int size);
void print2dIntArray(int** array, int* sizes, int size);
void print3dIntArray(int*** array, int** columnSizes, int* sizes, int size);

// validate.c
bool isCorrect(char** a, int aSize, char** b, int bSize);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize);

#endif

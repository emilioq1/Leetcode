#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_CASES 2
#define MAX_SIZE 8

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// array.c
int** convertToDoublePointer(int arr[][MAX_SIZE], const int sizes[], int n);
int*** convertToTriplePointer(int arr[][MAX_SIZE][MAX_SIZE], const int sizes[],
							  const int columnSizes[][MAX_SIZE], int n);
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
void printNumberArray(long long* array, int size);
void print2dNumberArray(long long** array, int* sizes, int size);
void print3dNumberArray(long long*** array, int** columnSizes, int* sizes,
						int size);
void printDoubleArray(long double* array, int size);
void print2dDoubleArray(long double** array, int* sizes, int size);
void print3dDoubleArray(long double*** array, int** columnSizes, int* sizes,
						int size);
void printStringArray(char** array, int size);
void print2dStringArray(char*** array, int* sizes, int size);
void print3dStringArray(char**** array, int** columnSizes, int* sizes,
						int size);

// validate.c
bool isCorrect(char** a, int aSize, char** b, int bSize);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize);

#endif

#ifndef SHARED_H
#define SHARED_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_CASES 3
#define MAX_SIZE 30
#define MAX_VALUE 100

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// array.c
int** convertToDoublePointer(int arr[TEST_CASES][MAX_SIZE], int sizes[]);
int*** convertToTriplePointer(int arr[TEST_CASES][MAX_SIZE][MAX_SIZE],
							  int sizes[TEST_CASES],
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

struct ListNode {
	int val;
	struct ListNode* next;
};

// validate.c
bool isCorrect(struct ListNode* a, struct ListNode* b);

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

struct ListNode* allocateNode(int* items, int size, int offset);
void printNode(struct ListNode* node);
void freeNode(struct ListNode* node);
void freeNodes(struct ListNode* node[], int size);

#endif

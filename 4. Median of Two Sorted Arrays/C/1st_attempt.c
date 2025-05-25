#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_ARRAY 1000

void printIntArray(int* arr, int size) {
    printf("[");

    for(int i = 0; i < size; ++i) {
        printf("%d, ", arr[i]);
    }

    printf("]\n");
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1 == NULL || nums2 == NULL) {
        return -1.0;
    }
    else if(nums1Size < 0 || nums1Size > 1000) {
        return -1.0;
    }
    else if(nums2Size < 0 || nums2Size > 1000) {
        return -1.0;
    }

    int new_size = nums1Size + nums2Size;

    int* merged_array = calloc(new_size, sizeof(int));
    
    for(int i = 0; i < nums1Size; ++i) {
        merged_array[i] = nums1[i];
    }

    //int next_index = nums1Size;
    //for(int i = 0, j = 0; i < new_size || j < nums2Size; ++i, ++j) {
    for(int i = 0; i < nums2Size; ++i) {
        merged_array[nums1Size + i] = nums2[i];
    }

    for(int i = 0, j = new_size; i != j; ++i, --j) {
        printf("%d == %d\n", i, j);
        printf("merged_array[%d]: %d\n", i, merged_array[i]);
        printf("merged_array[%d]: %d\n", j, merged_array[j]);
        if(merged_array[i] > merged_array[j]) {
            int upper = merged_array[i];
            int lower = merged_array[j];
            merged_array[i] = lower;
            merged_array[j] = upper;
        }
    }
    
    printf("merged_array: ");
    printIntArray(merged_array, new_size);
    printf("new_size: %d\n", new_size);

    double result = 0.0;

    if(new_size % 2 == 0) {
        int first_index = (new_size / 2) - 1;
        int second_index = first_index + 1;
        result = ((double)merged_array[first_index] + (double)merged_array[second_index]) / 2;
    }
    else {
        int index = ((new_size + 1) / 2) - 1;
        printf("index: %d\n", index);
        result = (double)merged_array[index];
    }


    free(merged_array);

    return result;
}

int main(void) {
    int nums1[] = {0, 0, 0, 0, 0};
    int nums2[] = {-1, 0, 0, 0, 0, 0, 1};

    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    printf("nums1Size: %d\n", nums1Size);
    printf("nums2Size: %d\n", nums2Size);

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("result: %f\n", result);

    return 0;
}

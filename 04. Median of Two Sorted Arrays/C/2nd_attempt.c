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
    int* merged_array = calloc((size_t)new_size, sizeof(int));
    
    for(int i = 0; i < nums1Size; ++i) {
        merged_array[i] = nums1[i];
    }

    for(int i = nums1Size, j = 0; j < nums2Size; ++i, ++j) {
        merged_array[i] = nums2[j];
        int original_i = i;
        
        while(i > 0 && merged_array[i] < merged_array[i - 1]) {
            int temp = merged_array[i];
            merged_array[i] = merged_array[i - 1];
            merged_array[i - 1] = temp;
            --i;
        }

        i = original_i;
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
        result = (double)merged_array[index];
    }

    free(merged_array);
    return result;
}

int main(void) {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("result: %f\n", result);

    return 0;
}

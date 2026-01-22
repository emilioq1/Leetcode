#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_INT_ARRAY 1000

typedef struct {
    int* nums;
    int size;
} IntArray;

void printIntArray(int* arr, int size) {
    printf("[");

    for(int i = 0; i < size; ++i) {
        printf("%d, ", arr[i]);
    }

    printf("]\n");
}

void sortArray(int* arr, int size) {
    for(int i = 0; i < size; ++i) {
        int original_i = i;

        while(i > 0 && arr[i] < arr[i - 1]) {
            int temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            --i;
        }

        i = original_i;
    }
}

int* combineTwoArrays(int* arr1, int arr1_size, int* arr2, int arr2_size) {
    int new_size = arr1_size + arr2_size;
    int* new_arr = calloc((size_t)new_size, sizeof(int));
    
    for(int i = 0, j = 0, k = 0; k < new_size; ++k) {
        printf("i: %d\n", i);
        printf("j: %d\n", j);
        printf("k: %d\n", k);
        new_arr[k] = (i < arr1_size) ? arr1[i++] : arr2[j++];
    }

    free(arr1);
    free(arr2);

    return new_arr;
}

void printList(IntArray IntArray) {
    printf("[");

    for(int i = 0; i < IntArray.size; ++i) {
        printf("%d, ", IntArray.nums[i]);
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
    IntArray* lists = calloc((size_t)new_size, sizeof(IntArray));

    for(int i = 0, j = 0, k = 0; i < nums1Size || j < nums2Size; ++k) {
        lists[k].nums = calloc(1, sizeof(int));
        lists[k].size = 1;

        if(i < nums1Size) {
            lists[k].nums[0] = nums1[i++];
        }
        else {
            lists[k].nums[0] = nums2[j++];
        }
    }
    
    for(int i = 0, j = 1; i < new_size - 1; ++i) {
        lists[i].nums = combineTwoArrays(lists[i].nums, lists[i].size, lists[j].nums, lists[j].size);
        lists[i].size = lists[i].size + lists[j].size;
        sortArray(lists[i].nums, lists[i].size);

        i += 2;
        j += 2;

        printList(lists[i]);
    }

    free(lists[0].nums);
    free(lists);

    //printf("merged_array: ");
    //printIntArray(merged_array, new_size);
    //printf("new_size: %d\n", new_size);

    //double result = 0.0;

    //if(new_size % 2 == 0) {
    //    int first_index = (new_size / 2) - 1;
    //    int second_index = first_index + 1;
    //    result = ((double)merged_array[first_index] + (double)merged_array[second_index]) / 2;
    //}
    //else {
    //    int index = ((new_size + 1) / 2) - 1;
    //    result = (double)merged_array[index];
    //}

    free(merged_array);
    int result = 0;
    return result;
}

int main(void) {
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

    printf("result: %f\n", result);

    return 0;
}

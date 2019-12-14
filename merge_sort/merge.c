#include <stdio.h>
#include <stdlib.h>
#include<time.h> 

/*
* Print all elements in the array
* @param arr: arr is an array of integers
* @param n: the size of the array
*/
void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
* Split and sort when merging. Note that the old array passed into merge_sort initially is not freed
* @param arr: arr is an array of integers
* @param n: the size of the array
* @return: returns a new sorted array
*/
int *merge_sort(int *arr, int n) {
    int half = n/2;
    if (!arr || half == 0) {
        return arr;
    }
    int *left = merge_sort(arr, half);
    int *right = merge_sort(arr+half, n-half);

    int *sorted_arr = malloc(n * sizeof(int));

    int l_p = 0, r_p = 0, sorted_index = 0;
    while (l_p != half && r_p != n-half) {
        int *l = left + l_p;
        int *r = right+ r_p;
        if ( *l > *r ) {
            sorted_arr[sorted_index] = *r;
            r_p++;
        }
        else {
            sorted_arr[sorted_index] = *l;
            l_p++;
        }
        sorted_index++;
    }

    //get remaining elements in the left half of the array
    for (int i = l_p; i < half; i++) {
        sorted_arr[sorted_index] = *(left + i);
        sorted_index++;
    }
    
    //get remaining elements in the right half of the array
    for (int i = r_p; i < n-half; i++) {
        sorted_arr[sorted_index] = *(right + i);
        sorted_index++;
    }
    
    //if the sub array is not empty or a single element, free to prevent dangling pointers and memory leaks
    if (half > 1) {
        free(left);
    }
    if (n-half > 1) {
        free(right);
    }

    return sorted_arr;
}

int main () {
    int n = 10;
    int *arr = malloc(n * sizeof(int));
    srand(time(0)); 
  
    for(int i = 0; i<n; i++) {
        arr[i] = rand() % 20;
    }
    int *old = arr;

    printf("==Before Sorting==\n");
    print_arr(arr, n);
    printf("\n");

    //START MERGE SORT
    arr = merge_sort(arr, n);
    printf("==After Sorting==\n");
    print_arr(arr, n);
    printf("\n");

    free(old);
    free(arr);

    return 0;
}